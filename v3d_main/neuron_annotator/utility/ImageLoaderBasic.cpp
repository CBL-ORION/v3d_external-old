/*
 * ImageLoaderBasic.cpp
 *
 *  Created on: Jan 30, 2013
 *      Author: Christopher M. Bruns
 */

#include "ImageLoaderBasic.h"
#include "../../basic_c_fun/stackutil.h"
#include <iostream>
#include <sstream>

using std::cerr;
using std::endl;
using std::stringstream;

static const unsigned char oooooool = 1;
static const unsigned char oooooolo = 2;
static const unsigned char ooooooll = 3;
static const unsigned char oooooloo = 4;
static const unsigned char ooooolol = 5;
static const unsigned char ooooollo = 6;
static const unsigned char ooooolll = 7;


ImageLoaderBasic::ImageLoaderBasic()
    : bIsCanceled(false)
    , fid(0)
    , compressionPosition(0)
    , decompressionPosition(0)
    , decompressionPrior(0)
{
}


ImageLoaderBasic::~ImageLoaderBasic()
{
}


/* virtual */
bool ImageLoaderBasic::loadImage(Image4DSimple * stackp, const char* filepath)
{
    bool bSucceeded = false;
    std::string extension = getFileExtension(std::string(filepath));
    if (extension == "lsm") {
        // Vaa3d is not const-correct...
        stackp->loadImage(const_cast<char*>(filepath), true);
        bSucceeded = true;
    } else if ((extension == "tif") ||
            (extension == "v3draw") ||
            (extension == "raw")) {
        stackp->loadImage(const_cast<char*>(filepath));
        bSucceeded = true;
    } else if (hasPbdExtension(filepath)) {
        // Basic ImageLoader does not use threading, to avoid Qt linkage
        if (loadRaw2StackPBD(filepath, stackp, false) == 0)
            bSucceeded = true;
        else
            cerr << "Error with loadRaw2StackPBD";
    }
    return bSucceeded;
}


/*

 This function implements a hybrid of PackBits with difference-encoding, as follows:

 ==========================================================================================================
 8-bit

 <header byte>

 0 to 32   : Implies the following (n+1) bytes are literal
 33 to 127 : Implies the prior byte is to be followed by (n-32) 2-bit (4-value) differences, to be applied accumulatively.
             Any extra space to the remaining byte boundary is to be ignored. The 4 values are interpreted as as a progessive
             4D array incrementing the following values in order { 0, 1, 2, -1 }, such that,

             Value   Difference Sequence

             0    =  0,  0,  0,  0
             1    =  0,  0,  0,  1
             2    =  0,  0,  0,  2
             3    =  0,  0,  0, -1
             4    =  0,  0,  1,  0
             5    =  0,  0,  1,  1
             6    =  0,  0,  1,  2
             7    =  0,  0,  1, -1
             8    =  0,  0,  2,  0
            ...
            123   =  1, -1,  2, -1
            124   =  1, -1, -1,  0
            125   =  1, -1, -1,  1
            126   =  1, -1, -1,  2
            127   =  1, -1, -1, -1
            128   =  2,  0,  0,  0
            129   =  2,  0,  0,  1
            130   =  2,  0,  0,  2
            131   =  2,  0,  0, -1
            132   =  2,  0,  1,  0
            133   =  2,  0,  1,  1
            ...
            188   =  2, -1, -1,  0
            189   =  2, -1, -1,  1
            190   =  2, -1, -1,  2
            191   =  2, -1, -1, -1
            192   = -1,  0,  0,  0
            193   = -1,  0,  0,  1
            194   = -1,  0,  0,  2
            195   = -1,  0,  0, -1
            ...
            249   = -1, -1,  2,  1
            250   = -1, -1,  2,  2
            251   = -1, -1,  2, -1
            252   = -1, -1, -1,  0
            253   = -1, -1, -1,  1
            254   = -1, -1, -1,  2
            255   = -1, -1, -1, -1

128 to 255 : Implies the following single byte is to be repeated (n-127) times

 ==========================================================================================================
 16-bit

 <header byte>

 0 to 31   : Implies the following (n+1) positions are literal, which requires 2*(n+1) following bytes.

 32 to 79 : Implies the prior 2-byte value is to be followed by (n-31) 3-bit (8-value) differences, to be applied accumutively.
            Any extra space within a 1-byte boundary is to be ignored. The difference is encoded thus:

             3-bit

             0 - 4 (literal)
             5-7 (4-n)

 80 to 182 : Implies the prior 2-byte value is to be followed by (n-79) 4-bit (16-value) differences, to be applied accumutively.
             Any extra space within a 1-byte boundary is to be ignored. The difference is encoded thus:

             4-bit

             0 - 8 (literal)
             9-15 (8-n)


 183 to 222 : Implies the prior 2-byte value is to be followed by (n-182) 5-bit (32-value) differences, applied accumulatively.
              Any extra space within a 1-byte boundary is ignored. The difference is encoded as:

              5-bit

              0-16 (literal)
              17-31 (16-n)


223 to 255 : Implies the following two-byte value is to be repeated (n-222) times


*/

int ImageLoaderBasic::saveStack2RawPBD(const char * filename, ImagePixelType datatype, unsigned char* data, const V3DLONG * sz)
{
    int berror=0;

        /* This function save a data stack to raw file */
                printf("size of [V3DLONG]=[%ld], [V3DLONG]=[%ld] [int]=[%ld], [short int]=[%ld], [double]=[%ld], [float]=[%ld]\n",
                       sizeof(V3DLONG), sizeof(V3DLONG), sizeof(int), sizeof(short int), sizeof(double), sizeof(float));
        V3DLONG i;

        fid = fopen(filename, "wb");
        if (!fid)
        {
            return exitWithError("Fail to open file for writing");
        }

        /* Write header */
                         // raw_image_stack_by_hpeng
        char formatkey[] = "v3d_volume_pkbitdf_encod";
        int lenkey = strlen(formatkey);

        V3DLONG nwrite = fwrite(formatkey, 1, lenkey, fid);
        if (nwrite!=lenkey)
        {
            return exitWithError("File write error");
        }

        char endianCodeMachine = checkMachineEndian();
        if (endianCodeMachine!='B' && endianCodeMachine!='L')
        {
                return exitWithError("This program only supports big- or little- endian but not other format. Cannot save data on this machine.");
        }

        nwrite = fwrite(&endianCodeMachine, 1, 1, fid);
        if (nwrite!=1)
        {
                return exitWithError("Error happened in file writing.");
        }

        //int b_swap = (endianCodeMachine==endianCodeData)?0:1;
        //int b_swap = 0; //for this machine itself, should not swap data.

        short int dcode = (short int)datatype;
        if (!(dcode==1 || dcode==2))
        {
            stringstream msg;
            msg << "Unrecognized data type code = [";
            msg << dcode;
            msg << "]. This code is not supported in this version.";
            return exitWithError(msg.str());
        }

        //if (b_swap) swap2bytes((void *)&dcode);
        nwrite=fwrite(&dcode, 2, 1, fid); /* because I have already checked the file size to be bigger than the header, no need to check the number of actual bytes read. */
        if (nwrite!=1)
        {
                return exitWithError("Writing file error.");
        }

        V3DLONG unitSize = datatype; /* temporarily I use the same number, which indicates the number of bytes for each data point (pixel). This can be extended in the future. */

        //short int mysz[4];
        BIT32_UNIT mysz[4];//060806
                                           //if (b_swap)  {
                                           //for (i=0;i<4;i++) mysz[i] = (short int) sz[i];
                for (i=0;i<4;i++) {
                    mysz[i] = (BIT32_UNIT) sz[i];
                    cerr << " size " << i << " = " << mysz[i] << endl;
                }
                //swap2bytes((void *)(mysz+i));
                //}
                nwrite = fwrite(mysz, 4, 4, fid); /* because I have already checked the file size to be bigger than the header, no need to check the number of actual bytes read. */
        if (nwrite!=4)
        {
                return exitWithError("Writing file error.");
        }

        V3DLONG totalUnit = 1;
        for (i=0;i<4;i++)
        {
                totalUnit *= sz[i];
        }

        cerr << "Using totalUnit=" << totalUnit << " unitSize=" << unitSize << endl;

        V3DLONG maxSize = totalUnit*unitSize*2;                             // NOTE:
        // unsigned char * compressionBuffer = new unsigned char [maxSize]; // we give the compression buffer 2x room without throwing an error,
                                                                            // even though we hope it peforms well below 1, obviously
        std::vector<unsigned char> compressionBuffer(maxSize);

        printf("Allocated compression target with maxSize=%ld\n", maxSize);

        V3DLONG compressionSize = 0;

        if (datatype==1) {
            compressionSize=compressPBD8(&compressionBuffer[0], data, totalUnit*unitSize, maxSize);
        } else if (datatype==2) {
            compressionSize=compressPBD16(&compressionBuffer[0], data, totalUnit*unitSize, maxSize);
        }

        if (compressionSize==0) {
            return exitWithError("Error during compressPBD");
        }

        double finalCompressionRatio = (totalUnit*unitSize*1.0)/compressionSize;

        V3DLONG originalSize=totalUnit*unitSize;

        printf("Total original size=%ld  post-compression size=%ld  ratio=%f\n", originalSize, compressionSize, finalCompressionRatio);

        printf("Writing file...");

        nwrite = fwrite(&compressionBuffer[0], 1, compressionSize, fid);
        if (nwrite!=compressionSize)
        {
            stringstream msg;
            msg << "Something wrong in file writing. The program wrote ";
            msg << nwrite;
            msg << "data points but the file says there should be ";
            msg << totalUnit;
            msg << "data points.";
            return exitWithError(msg.str());
        }

        /* clean and return */
        fclose(fid);
        fid = 0;
        printf("done.\n");
        return berror;
}

V3DLONG ImageLoaderBasic::compressPBD8(unsigned char * compressionBuffer, unsigned char * sourceBuffer, V3DLONG sourceBufferLength, V3DLONG spaceLeft) {
    // bool debug=false;
    V3DLONG p=0;

    if (sourceBufferLength==0) {
        printf("ImageLoaderBasic::compressPBD8 - unexpectedly received buffer of zero size\n");
        return 0;
    }

    unsigned char currentValue=0;
    int dbuffer[95];
    V3DLONG activeLiteralIndex=-1; // if -1 this means there is no literal mode started
    for (V3DLONG i=0;i<sourceBufferLength;i++) {

        if (p>=spaceLeft) {
            printf("ImageLoaderBasic::compressPBD8 ran out of space p=%ld\n", p);
            return 0;
        }

        // From this point we assume the result has been accumulating in compressionBuffer, and at this moment
        // we are searching for the best approach for the next segment. First, we will try reading
        // the next value, and testing what the runlength encoding efficiency would be. The
        // efficiency is simply the (number of bytes encoded / actual bytes). Next, we will test
        // the different encoding, and (depending on its reach), see what its efficiency is.
        // The minimum number of unencoded bytes to use run-length encoding for is 3 (code, value).
        // The minimum number of unencoded bytes to use difference encoding is 3 also (code, value).

        int reTest=1;
        currentValue=sourceBuffer[i];
        V3DLONG currentPosition=i+1;
        while(currentPosition<sourceBufferLength && reTest<128) { // 128 is the max number of repeats supported
            if (sourceBuffer[currentPosition++]==currentValue) {
                reTest++;
            } else {
                break;
            }
        }
        double reEfficiency = reTest*1.0 / 2.0; // 2-bytes are used for the encoding

        if (reEfficiency>=4.0) { // 4.0 is the max efficiency from the difference encoding
            // Then use RE
            compressionBuffer[p++]=reTest+127; // The code for number of repeats
            compressionBuffer[p++]=currentValue; // The repeated value
            i+=(reTest-1); // because will increment one more time at top of loop
            activeLiteralIndex=-1;
        } else {
            double dfEfficiency=0.0;
            V3DLONG c=i;
            if (i>0) { // I.e., if not first since we can't start with a difference encoding
                // We need to evaluate difference encoding starting with the prior value
                unsigned int priorValue=sourceBuffer[i-1];
                V3DLONG unitsToCheck=sourceBufferLength-i;
                if (unitsToCheck>95) {
                    unitsToCheck=95; // 95 is max supported number of differences
                }
                for (int j=0;j<95;j++) {
                    dbuffer[j]=0; // clear the difference buffer
                }
                for (;c<i+unitsToCheck;c++) {
                    int d=sourceBuffer[c] - priorValue;
                    if (d>2 || d<-1) {
                        break;
                    }
                    priorValue=sourceBuffer[c]; // since by definition the diff encoding is cumulative
                    if (d==-1) {
                        d=3; // we use this to represent -1 in the dbuffer for key lookup later
                    }
                    dbuffer[c-i]=d;
                }
                dfEfficiency = ((c-i)*1.0)/(((c-i)/4)+2); // The denominator includes the coding byte and the encoding bytes
            }
            // Now we can decide between RE and DF based on efficiency
            if (reEfficiency>dfEfficiency && reEfficiency>1.0) {
                // Then use RE
                compressionBuffer[p++]=reTest+127; // The code for number of repeats
                compressionBuffer[p++]=currentValue; // The repeated value
                i+=(reTest-1); // because will increment one more time at top of loop
                activeLiteralIndex=-1;
            } else if (dfEfficiency>1.0) {
                // First, encode the number of units we expect
                compressionBuffer[p++]=c-i+32;

                // Then use DF. We want to move forward in units of 4, and pick the correct encoding.
                // Note that is doesn't matter if we pad extra 0s because we know what the correct
                // length is from above.
                V3DLONG cp=i;
                unsigned char d0,d1,d2,d3;
                d0=d1=d2=d3=0;
                while(cp<c) {
                    V3DLONG start=cp-i;
                    d0=dbuffer[start];
                    if (cp+1<c) {
                        d1=dbuffer[start+1];
                        if (cp+2<c) {
                            d2=dbuffer[start+2];
                            if (cp+3<c) {
                                d3=dbuffer[start+3];
                            }
                        }
                    }
                    // In decompression, we want FIFO for speed, so we put last first.
                    unsigned char v=0;
                    v |= d3;
                    v <<= 2;
                    v |= d2;
                    v <<= 2;
                    v |= d1;
                    v <<= 2;
                    v |= d0;

                    compressionBuffer[p++]=v;
                    cp+=4; // Move ahead 4 steps at a time
                }

                activeLiteralIndex=-1;
                i=c-1; // will increment at top
            } else { // This will catch the case where dfEfficiency is 0.0 due to i==0
                // We need to add this value as a literal. If there is already a literal mode, then simply
                // add it. Otherwise, start a new one.
                if (activeLiteralIndex<0 || compressionBuffer[activeLiteralIndex]>=32) {
                    // We need a new index
                    compressionBuffer[p++]=0;
                    activeLiteralIndex=p-1; // Our new literal index
                    compressionBuffer[p++]=currentValue; // Add the current value onto current sequence of literals
                } else {
                    compressionBuffer[activeLiteralIndex] += 1; // Increment existing literal count
                    compressionBuffer[p++]=currentValue; // Add the current value onto current sequence of literals
                }
            }
        }
    }
    return p;
}

V3DLONG ImageLoaderBasic::compressPBD16(unsigned char * compressionBuffer, unsigned char * sourceBuffer, V3DLONG sourceBufferLength, V3DLONG spaceLeft) {
    bool debug=false;
    V3DLONG p=0;
    const int THREE_BIT_DIFF_MAX_LENGTH=79-31;
    const int FOUR_BIT_DIFF_MAX_LENGTH=182-79;
    const int FIVE_BIT_DIFF_MAX_LENGTH=222-182;
    const int REPEAT_MAX_LENGTH=255-222;

    if (sourceBufferLength==0) {
        printf("ImageLoaderBasic::compressPBD16 - unexpectedly received buffer of zero size\n");
        return 0;
    }

    v3d_uint16 currentValue=0;
    v3d_uint16 * source16Buffer = (v3d_uint16*)sourceBuffer;
    V3DLONG source16BufferLength = sourceBufferLength/2;
    int* dbuffer = 0;
    int d3buffer[256];
    int d4buffer[256];
    int d5buffer[256];
    V3DLONG activeLiteralIndex=-1; // if -1 this means there is no literal mode started

    // Minimum number of values to accept as an encoding preferable to literal:
    //
    //      Run-length: 2 { code, value } = 3 bytes to encode 2 values as repeats, vs 4 bytes to encode 2 literal values (STARTS NEW VALUE)
    //
    //      Three-bit: 2 { code, diff } = 2 bytes to encode 2 or more values, superior to literal starting at 2 values (EXTENDS PRIOR VALUE)
    //
    //      Four-bit:  2 { code, diff } = 2 bytes to encode 2 values, superior to literal starting at 2 values (EXTENDS PRIOR VALUE)
    //
    //      Five-bit: 3 { code, diff } = 3 bytes to encode 3 values, superior to literal start at 3 values (EXTENDS PRIOR VALUE)

    const double THREE_BIT_MAX_EFF = 16.0/3.0;
    const double FOUR_BIT_MAX_EFF = 16.0/4.0;
    const double FIVE_BIT_MAX_EFF = 16.0/5.0;

    for (V3DLONG i=0;i<source16BufferLength;i++) {

        if (p>=spaceLeft) {
            cerr << "ImageLoaderBasic::compressPBD16 ran out of space p=" << p << endl;
            return 0;
        }

        // From this point we assume the result has been accumulating in compressionBuffer, and at this moment
        // we are searching for the best approach for the next segment. First, we will try reading
        // the next value, and testing what the runlength encoding efficiency would be. The
        // efficiency is simply the (number of bytes encoded / actual bytes). Next, we will test
        // the different encoding, and (depending on its reach), see what its efficiency is.

        // We will test the efficiency of the various methods and see how well we can do from the current position.

        int repeatTest=1;
        currentValue=source16Buffer[i];
        //qDebug() << "At position=" << i << " value=" << currentValue;
        V3DLONG currentPosition=i+1;
        while(currentPosition<source16BufferLength && repeatTest<REPEAT_MAX_LENGTH) {
            if (source16Buffer[currentPosition++]==currentValue) {
                repeatTest++;
            } else {
                break;
            }
        }
        double repeatEfficiency = repeatTest*1.0 / 3.0; // 3-bytes are used for the encoding

        if (repeatEfficiency>=THREE_BIT_MAX_EFF) { // we can't do better than this with difference encoding
            // Then go ahead and use repeat runlength encoding - this will work even at the start
            compressionBuffer[p++]=repeatTest+222; // The code for number of repeats
            v3d_uint16 * repeatValuePointer = (v3d_uint16*)(compressionBuffer + p);
            *repeatValuePointer=currentValue;
            p=p+2; // advance p by two bytes
            i+=(repeatTest-1); // because will increment one more time at top of loop
            activeLiteralIndex=-1; // we have no current literal context
        } else {
            // This means we don't have an impossible-to-beat repeat context, so we'll try a difference encoding
            // to see if we can do better. We will try them from most efficient to least.
            double dfEfficiency=0.0;
            int dfType=0; // 0 is unknown, 3=3-bit, 4=4-bit, etc.
            double df3Efficiency=0.0;
            double df4Efficiency=0.0;
            double df5Efficiency=0.0;
            V3DLONG c=0;
            V3DLONG d3c=0;
            V3DLONG d4c=0;
            V3DLONG d5c=0;
            if (i>0) { // We can only use a difference encoding if we are initialized to have a prior value.
                v3d_uint16 priorValue=source16Buffer[i-1];
                int unitsToCheck=source16BufferLength-i;
                for (dfType=3;dfType<6;dfType++) {
                    c=i;
                    if (dfType==3) {
                        if (unitsToCheck>THREE_BIT_DIFF_MAX_LENGTH) {
                            unitsToCheck=THREE_BIT_DIFF_MAX_LENGTH;
                        }
                        for (int j=0;j<256;j++) {
                            d3buffer[j]=0; // clear the difference buffer
                        }
                        for (;c<i+unitsToCheck;c++) {
                            //qDebug() << "debug: df3  c=" << c << " value=" << source16Buffer[c];
                            int d=source16Buffer[c] - priorValue;
                            if (d>4 || d<-3) {
                                break;
                            }
                            priorValue=source16Buffer[c]; // since by definition the diff encoding is cumulative
                            d3buffer[c-i]=d;
                        }
                        df3Efficiency=((c-i)*2.0)/(((c-i)*(3.0/8.0))+2.0); // 2.0 handles 1 byte boundary + length bias
                        d3c=c;
                    } else if (dfType==4) {
                        if (unitsToCheck>FOUR_BIT_DIFF_MAX_LENGTH) {
                            unitsToCheck=FOUR_BIT_DIFF_MAX_LENGTH;
                        }
                        for (int j=0;j<256;j++) {
                            d4buffer[j]=0; // clear the difference buffer
                        }
                        for (;c<i+unitsToCheck;c++) {
                            int d=source16Buffer[c] - priorValue;
                            if (d>8 || d<-7) {
                                break;
                            }
                            priorValue=source16Buffer[c]; // since by definition the diff encoding is cumulative
                            d4buffer[c-i]=d;
                        }
                        df4Efficiency=((c-i)*2.0)/(((c-i)/2.0)+2.0); // 2.0 handles 1 byte boundary + length bias
                        d4c=c;
                    } else if (dfType==5) {
                        if (unitsToCheck>FIVE_BIT_DIFF_MAX_LENGTH) {
                            unitsToCheck=FIVE_BIT_DIFF_MAX_LENGTH;
                        }
                        for (int j=0;j<256;j++) {
                            d5buffer[j]=0; // clear the difference buffer
                        }
                        for (;c<i+unitsToCheck;c++) {
                            int d=source16Buffer[c] - priorValue;
                            if (d>16 || d<-15) {
                                break;
                            }
                            priorValue=source16Buffer[c]; // since by definition the diff encoding is cumulative
                            d5buffer[c-i]=d;
                        }
                        df5Efficiency=((c-i)*2.0)/(((c-i)*(5.0/8.0))+2.0); // 2.0 handles 1 byte boundary + length bias
                        d5c=c;
                    }
                }

                // DEBUG - TYPE 3 ONLY FOR NOW
                dfEfficiency=df3Efficiency;
                c=d3c;
                dfType=3;
                dbuffer=d3buffer;

//                if (df4Efficiency>df3Efficiency) {
//                    dfEfficiency=df4Efficiency;
//                    c=d4c;
//                    dfType=4;
//                    dbuffer=d4buffer;
//                } else {
//                    dfEfficiency=df3Efficiency;
//                    c=d3c;
//                    dfType=3;
//                    dbuffer=d3buffer;
//                }
//                if (df5Efficiency>dfEfficiency) {
//                    dfEfficiency=df5Efficiency;
//                    c=d5c;
//                    dfType=5;
//                    dbuffer=d5buffer;
//                }
            }
            // Now we can decide between RE and DF based on efficiency
            if (repeatEfficiency>dfEfficiency && repeatEfficiency>1.0) {
                // Then use RE
                compressionBuffer[p++]=repeatTest+222; // The code for number of repeats
                v3d_uint16 * cbp = (v3d_uint16*)(compressionBuffer + p);
                *cbp=currentValue;
                p=p+2;
                i+=(repeatTest-1); // because will increment one more time at top of loop
                activeLiteralIndex=-1;
            } else if (dfEfficiency>1.0) {

                V3DLONG cp;
                unsigned char d0,d1,d2,d3,d4;

                if (dfType==3) {
                    // First, encode the number of units we expect
                    compressionBuffer[p++]=c-i+31;

                    // Then use DF. We want to move forward in units of 4, and pick the correct encoding.
                    // Note that is doesn't matter if we pad extra 0s because we know what the correct
                    // length is from above.
                    cp=i;
                    d0=d1=d2=d3=d4=0;

                    // byte partition sequence 332, 1331, 233

                    while(cp<c) {

                        // 332
                        int dvalue=dbuffer[cp-i];
                        if (dvalue<0) {
                            d0=4-dvalue;
                        } else {
                            d0=dvalue;
                        }
                        cp++;
                        if (cp==c) {
                            d0 <<= 5;
                            compressionBuffer[p++]=d0;
                            break;
                        }
                        d0 <<= 3;
                        dvalue=dbuffer[cp-i];
                        if (dvalue<0) {
                            d1=4-dvalue;
                        } else {
                            d1=dvalue;
                        }
                        d0 |= d1;
                        cp++;
                        d0 <<= 2;
                        if (cp==c) {
                            compressionBuffer[p++]=d0;
                            break;
                        }
                        dvalue=dbuffer[cp-i];
                        if (dvalue<0) {
                            d2=4-dvalue;
                        } else {
                            d2=dvalue;
                        }
                        d3 = d2;
                        d3 &= ooooollo;
                        d3 >>= 1;
                        d0 |= d3;
                        compressionBuffer[p++]=d0;
                        d4 = d2;
                        d4 &= oooooool;
                        unsigned char carryOver=d4;
                        d0=d1=d2=d3=d4=0;

                        // 1331
                        d0=carryOver;
                        cp++;
                        if (cp==c) {
                            d0 <<= 7;
                            compressionBuffer[p++]=d0;
                            break;
                        }
                        d0 <<= 3;
                        dvalue=dbuffer[cp-i];
                        if (dvalue<0) {
                            d1=4-dvalue;
                        } else {
                            d1=dvalue;
                        }
                        d0 |= d1;
                        cp++;
                        d0 <<= 3;
                        if (cp==c) {
                            d0 <<= 1;
                            compressionBuffer[p++]=d0;
                            break;
                        }
                        dvalue=dbuffer[cp-i];
                        if (dvalue<0) {
                            d2=4-dvalue;
                        } else {
                            d2=dvalue;
                        }
                        d0 |= d2;
                        cp++;
                        d0 <<= 1;
                        if (cp==c) {
                            compressionBuffer[p++]=d0;
                            break;
                        }
                        dvalue=dbuffer[cp-i];
                        if (dvalue<0) {
                            d3=4-dvalue;
                        } else {
                            d3=dvalue;
                        }
                        d4=d3;
                        d3 &= oooooloo;
                        d3 >>= 2;
                        d0 |= d3;
                        compressionBuffer[p++]=d0;
                        d4 &= ooooooll;
                        carryOver = d4;
                        d0=d1=d2=d3=d4=0;

                        // 233
                        d0=carryOver;
                        cp++;
                        if (cp==c) {
                            d0 <<= 6;
                            compressionBuffer[p++]=d0;
                            break;
                        }
                        d0 <<= 3;
                        dvalue=dbuffer[cp-i];
                        if (dvalue<0) {
                            d1=4-dvalue;
                        } else {
                            d1=dvalue;
                        }
                        d0 |= d1;
                        cp++;
                        d0 <<= 3;
                        if (cp==c) {
                            compressionBuffer[p++]=d0;
                            break;
                        }
                        dvalue=dbuffer[cp-i];
                        if (dvalue<0) {
                            d2=4-dvalue;
                        } else {
                            d2=dvalue;
                        }
                        d0 |= d2;
                        compressionBuffer[p++]=d0;
                        cp++;
                    }
                }

                activeLiteralIndex=-1;
                i=c-1; // will increment at top

            } else { // This will catch the case where dfEfficiency is 0.0 due to i==0
                // We need to add this value as a literal. If there is already a literal mode, then simply
                // add it. Otherwise, start a new one.
                if (activeLiteralIndex<0 || compressionBuffer[activeLiteralIndex]>=31) {
                    // We need a new index
                    compressionBuffer[p++]=0;
                    activeLiteralIndex=p-1; // Our new literal index
                    v3d_uint16 * cbp = (v3d_uint16*)(compressionBuffer + p); // Add the current value onto current sequence of literals
                    *cbp=currentValue;
                    //v3d_uint16 testValue=*((v3d_uint16*)(compressionBuffer + p));
                    if (debug)
                        cerr << "Assigned literal value for i=" << i << " index=0  p=" << p << " currentValue=" << currentValue << endl;
                    p+=2;
                } else {
                    compressionBuffer[activeLiteralIndex] += 1; // Increment existing literal count
                    v3d_uint16 * cbp = (v3d_uint16*)(compressionBuffer + p); // Add the current value onto current sequence of literals
                    *cbp=currentValue;
                    //v3d_uint16 testValue=*((v3d_uint16*)(compressionBuffer + p));
                    if (debug) cerr << "Assigned literal value for i=" << i << " index=" << compressionBuffer[activeLiteralIndex] << "  p=" << p << " currentValue=" << currentValue << endl;
                    p+=2;
                }
            }
        }
    }
    return p;
}

V3DLONG ImageLoaderBasic::decompressPBD8(unsigned char * sourceData, unsigned char * targetData, V3DLONG sourceLength) {

    // Decompress data
    V3DLONG cp=0;
    V3DLONG dp=0;
    const unsigned char mask=0x0003;
    unsigned char p0,p1,p2,p3;
    unsigned char value=0;
    unsigned char pva=0;
    unsigned char pvb=0;
    int leftToFill=0;
    int fillNumber=0;
    unsigned char * toFill=0;
    unsigned char sourceChar=0;
    while(cp<sourceLength) {

        if (isCanceled())
            return dp;

        value=sourceData[cp];

        if (value<33) {
            // Literal 0-32
            unsigned char count=value+1;
            for (V3DLONG j=cp+1;j<cp+1+count;j++) {
                targetData[dp++]=sourceData[j];
            }
            cp+=(count+1);
            decompressionPrior=targetData[dp-1];
        } else if (value<128) {
            // Difference 33-127
            leftToFill=value-32;
            while(leftToFill>0) {
                fillNumber=(leftToFill<4 ? leftToFill : 4);
                sourceChar=sourceData[++cp];
                toFill = targetData+dp;
                p0=sourceChar & mask;
                sourceChar >>= 2;
                p1=sourceChar & mask;
                sourceChar >>= 2;
                p2=sourceChar & mask;
                sourceChar >>= 2;
                p3=sourceChar & mask;
                pva=(p0==3?-1:p0)+decompressionPrior;

                *toFill=pva;
                if (fillNumber>1) {
                    toFill++;
                    pvb=pva+(p1==3?-1:p1);
                    *toFill=pvb;
                    if (fillNumber>2) {
                        toFill++;
                        pva=(p2==3?-1:p2)+pvb;
                        *toFill=pva;
                        if (fillNumber>3) {
                            toFill++;
                            *toFill=(p3==3?-1:p3)+pva;
                        }
                    }
                }

                decompressionPrior = *toFill;
                dp+=fillNumber;
                leftToFill-=fillNumber;
            }
            cp++;
        } else {
            // Repeat 128-255
            unsigned char repeatCount=value-127;
            unsigned char repeatValue=sourceData[++cp];

            for (int j=0;j<repeatCount;j++) {
                targetData[dp++]=repeatValue;
            }
            decompressionPrior=repeatValue;
            cp++;
        }

    }
    return dp;
}

V3DLONG ImageLoaderBasic::decompressPBD16(unsigned char * sourceData, unsigned char * targetData, V3DLONG sourceLength)
{
    // bool debug=false;

    // Decompress data
    V3DLONG cp=0;
    V3DLONG dp=0;
    unsigned char code=0;
    int leftToFill=0;
    unsigned char sourceChar=0;
    unsigned char carryOver=0;
    v3d_uint16* target16Data=(v3d_uint16*)targetData;

    unsigned char d0,d1,d2,d3,d4;

    while(cp<sourceLength) {

        if (isCanceled())
            return dp*2;

        code=sourceData[cp];

         //if (debug) qDebug() << "decompressPBD16  dPos=" << decompPos << " dBuf=" << decompBuf << " decompressionPrior=" << decompressionPrior << " debugThreshold=" << debugThreshold << " cp=" << cp << " code=" << code;

        // Literal 0-31
        if (code<32) {
            unsigned char count=code+1;
            //if (debug) qDebug() << "decompressPBD16  literal count=" << count;
            v3d_uint16 * initialOffset = (v3d_uint16*)(sourceData + cp + 1);
            for (int j=0;j<count;j++) {
                target16Data[dp++]=initialOffset[j];
                //if (debug) qDebug() << "decompressPBD16 added literal value=" << target16Data[dp-1] << " at position=" << ((decompressionPosition-decompressionBuffer) + 2*(dp-1));
            }
            cp+=(count*2+1);
            decompressionPrior=target16Data[dp-1];
            //if (debug) qDebug() << "debug: literal set decompressionPrior=" << decompressionPrior;
        }

        // NOTE: For the difference sections, we will unroll conditional
        // logic and explicitly go through the full cycle byte-boundary cycle.

        // Difference 3-bit 32-79
        else if (code<80) {
            leftToFill=code-31;
            //if (debug) qDebug() << "decompressPBD16 leftToFill start=" << leftToFill << " decompressionPrior=" << decompressionPrior;
            while(leftToFill>0) {

                // 332
                d0=d1=d2=d3=d4=0;
                sourceChar=sourceData[++cp];
                d0=sourceChar;
                d0 >>= 5;
                target16Data[dp++]=decompressionPrior+(d0<5?d0:4-d0);
                //if (debug) qDebug() << "debug: position " << (dp-1) << " diff value=" << target16Data[dp-1] << " d0=" << d0;
                leftToFill--;
                if (leftToFill==0) {
                    break;
                }
                d1=sourceChar;
                d1 >>= 2;
                d1 &= ooooolll;
                target16Data[dp++]=target16Data[dp-1]+(d1<5?d1:4-d1);
                //if (debug) qDebug() << "debug: position " << (dp-1) << " diff value=" << target16Data[dp-1];
                leftToFill--;
                if (leftToFill==0) {
                    break;
                }
                d2=sourceChar;
                d2 &= ooooooll;
                carryOver=d2;

                // 1331
                d0=d1=d2=d3=d4=0;
                sourceChar=sourceData[++cp];
                d0=sourceChar;
                carryOver <<= 1;
                d0 >>= 7;
                d0 |= carryOver;
                target16Data[dp++]=target16Data[dp-1]+(d0<5?d0:4-d0);
                //if (debug) qDebug() << "debug: position " << (dp-1) << " diff value=" << target16Data[dp-1];
                leftToFill--;
                if (leftToFill==0) {
                    break;
                }
                d1=sourceChar;
                d1 >>= 4;
                d1 &= ooooolll;
                target16Data[dp++]=target16Data[dp-1]+(d1<5?d1:4-d1);
                //if (debug) qDebug() << "debug: position " << (dp-1) << " diff value=" << target16Data[dp-1];
                leftToFill--;
                if (leftToFill==0) {
                    break;
                }
                d2=sourceChar;
                d2 >>= 1;
                d2 &= ooooolll;
                target16Data[dp++]=target16Data[dp-1]+(d2<5?d2:4-d2);
                //if (debug) qDebug() << "debug: position " << (dp-1) << " diff value=" << target16Data[dp-1];
                leftToFill--;
                if (leftToFill==0) {
                    break;
                }
                d3=sourceChar;
                d3 &= oooooool;
                carryOver=d3;

                // 233
                d0=d1=d2=d3=d4=0;
                sourceChar=sourceData[++cp];
                d0=sourceChar;
                d0 >>= 6;
                carryOver <<= 2;
                d0 |= carryOver;
                target16Data[dp++]=target16Data[dp-1]+(d0<5?d0:4-d0);
                //if (debug) qDebug() << "debug: position " << (dp-1) << " diff value=" << target16Data[dp-1];
                leftToFill--;
                if (leftToFill==0) {
                    break;
                }
                d1=sourceChar;
                d1 >>= 3;
                d1 &= ooooolll;
                target16Data[dp++]=target16Data[dp-1]+(d1<5?d1:4-d1);
                //if (debug) qDebug() << "debug: position " << (dp-1) << " diff value=" << target16Data[dp-1];
                leftToFill--;
                if (leftToFill==0) {
                    break;
                }
                d2=sourceChar;
                d2 &= ooooolll;
                target16Data[dp++]=target16Data[dp-1]+(d2<5?d2:4-d2);
                //if (debug) qDebug() << "debug: position " << (dp-1) << " diff value=" << target16Data[dp-1];
                leftToFill--;
                if (leftToFill==0) {
                    break;
                }
                decompressionPrior=target16Data[dp-1];
            }
            decompressionPrior=target16Data[dp-1];
            //if (debug) qDebug() << "debug: diff set decompressionPrior=" << decompressionPrior;
            cp++;
        } else if (code<223) {
            cerr << "DEBUG: Mistakenly received unimplemented code of " << code << " at dp=" << dp << " cp=" << cp << " decompressionPrior=" << decompressionPrior << endl;
        }
        // Repeat 223-255
        else {
            unsigned char repeatCount=code-222;
            cp++;
            v3d_uint16 repeatValue=*((v3d_uint16*)(sourceData + cp));
            //if (debug) qDebug() << "decompressPBD16  repeatCount=" << repeatCount << " repeatValue=" << repeatValue;
            for (int j=0;j<repeatCount;j++) {
                target16Data[dp++]=repeatValue;
            }
            decompressionPrior=repeatValue;
            //if (debug) qDebug() << "debug: repeat set decompressionPrior=" << decompressionPrior;
            cp+=2;
            //if (debug) qDebug() << "decompressPBD16  finished adding repeats at dp=" << dp << " cp=" << cp;
        }

    }
    return dp*2;
}


// This is the main decompression function, which is basically a wrapper for the decompression function
// of ImageLoaderBasic, except it determines the boundary of acceptable processing given the contents of the
// most recently read block. This function assumes it is called sequentially (i.e., not in parallel)
// and so doesn't have to check that the prior processing step is finished. updatedCompressionBuffer
// points to the first invalid data position, i.e., all previous positions starting with compressionBuffer
// are valid.
void ImageLoaderBasic::updateCompressionBuffer8(unsigned char * updatedCompressionBuffer) {
    //printf("d1\n");
    if (compressionPosition==0) {
        // Just starting
        compressionPosition=&compressionBuffer[0];
    }
    unsigned char * lookAhead=compressionPosition;
    while(lookAhead<updatedCompressionBuffer) {
        unsigned char lav=*lookAhead;
        // We will keep going until we find nonsense or reach the end of the block
        if (lav<33) {
            // Literal values - the actual number of following literal values
            // is equal to the lav+1, so that if lav==32, there are 33 following
            // literal values.
            if ( lookAhead+lav+1 < updatedCompressionBuffer ) {
                // Then we can process the whole literal section - we can move to
                // the next position
                lookAhead += (lav+2);
            } else {
                break; // leave lookAhead in current maximum position
            }
        } else if (lav<128) {
            // Difference section. The number of difference entries is equal to lav-32, so that
            // if lav==33, the minimum, there will be 1 difference entry. For a given number of
            // difference entries, there are a factor of 4 fewer compressed entries. With the
            // equation below, lav-33 will be 4 when lav==37, which is 5 entries, requiring 2 bytes, etc.
            unsigned char compressedDiffEntries=(lav-33)/4 + 1;
            if ( lookAhead+compressedDiffEntries < updatedCompressionBuffer ) {
                // We can process this section, so advance to next position to evaluate
                lookAhead += (compressedDiffEntries+1);
            } else {
                break; // leave in current max position
            }
        } else {
            // Repeat section. Number of repeats is equal to lav-127, but the very first
            // value is the value to be repeated. The total number of compressed positions
            // is always == 2
            if ( lookAhead+1 < updatedCompressionBuffer ) {
                lookAhead += 2;
            } else {
                break; // leave in current max position
            }
        }
    }
    // At this point, lookAhead is in an invalid position, which if equal to updatedCompressionBuffer
    // means the entire compressed update can be processed.
    V3DLONG compressionLength=lookAhead-compressionPosition;
    if (decompressionPosition==0) {
        // Needs to be initialized
        decompressionPosition=decompressionBuffer;
    }
    //qDebug() << "updateCompressionBuffer calling decompressPBD compressionPosition=" << compressionPosition << " decompressionPosition=" << decompressionPosition
    //        << " size=" << compressionLength << " previousTotalDecompSize=" << getDecompressionSize() << " maxDecompSize=" << maxDecompressionSize;
    V3DLONG dlength=decompressPBD8(compressionPosition, decompressionPosition, compressionLength);
    compressionPosition=lookAhead;
    decompressionPosition+=dlength;
    //printf("d2\n");
}


// This is the main decompression function, which is basically a wrapper for the decompression function
// of ImageLoaderBasic, except it determines the boundary of acceptable processing given the contents of the
// most recently read block. This function assumes it is called sequentially (i.e., not in parallel)
// and so doesn't have to check that the prior processing step is finished. updatedCompressionBuffer
// points to the first invalid data position, i.e., all previous positions starting with compressionBuffer
// are valid.
void ImageLoaderBasic::updateCompressionBuffer16(unsigned char * updatedCompressionBuffer) {
    //printf("d1\n");
    if (compressionPosition==0) {
        // Just starting
        compressionPosition=&compressionBuffer[0];
    }
    unsigned char * lookAhead=compressionPosition;
    while(lookAhead<updatedCompressionBuffer) {
        // We assume at this point that lookAhead is at a code position
        unsigned char lav=*lookAhead;
        // We will keep going until we find nonsense or reach the end of the block
        if (lav<32) {
            // Literal values - the actual number of following literal values
            // is equal to the lav+1, so that if lav==31, there are 32 following
            // literal values.
            if ( lookAhead+((lav+1)*2) < updatedCompressionBuffer ) {
                // Then we can process the whole literal section - we can move to
                // the next position
                lookAhead += ( (lav+1)*2 + 1); // +1 is for code
            } else {
                break; // leave lookAhead in current maximum position
            }
        } else if (lav<80) {
            // Difference section, 3-bit encoding.
            // The number of difference entries is equal to lav-31, so that
            // if lav==32, the minimum, there will be 1 difference entry.
            unsigned char compressedDiffBytes=int(((((lav-31)*3)*1.0)/8.0)-0.0001) + 1;
//            int a=(lav-31)*3;
//            double b=a*1.0;
//            double c=b/8.0;
//            double d=c-0.0001;
//            int e=int(d);
//            int f=e+1;
//            qDebug() << "lav=" << lav << " lav-31=" << (lav-31) << " cdb=" << compressedDiffBytes;
//            qDebug() << "a=" << a << " b=" << b << " c=" << c << " d=" << d << " e=" << e << " f=" << f;
            if ( lookAhead+compressedDiffBytes < updatedCompressionBuffer ) {
                // We can process this section, so advance to next position to evaluate
                lookAhead += (compressedDiffBytes+1); // +1 is for code
            } else {
                break; // leave in current max position
            }
        } else if (lav<183) {
            // Difference section, 4-bit encoding.
            // The number of difference entries is equal to lav-79, so that
            // if lav==80, the minimum, there will be 1 difference entry.
            unsigned char compressedDiffBytes=int(((((lav-79)*4)*1.0)/8.0)-0.0001) + 1;
            if ( lookAhead+compressedDiffBytes < updatedCompressionBuffer ) {
                // We can process this section, so advance to next position to evaluate
                lookAhead += (compressedDiffBytes+1); // +1 is for code
            } else {
                break; // leave in current max position
            }
        } else if (lav<223) {
            // Difference section, 5-bit encoding.
            // The number of difference entries is equal to lav-182, so that
            // if lav==183, the minimum, there will be 1 difference entry.
            unsigned char compressedDiffBytes=int(((((lav-182)*5)*1.0)/8.0)-0.0001) + 1;
            if ( lookAhead+compressedDiffBytes < updatedCompressionBuffer ) {
                // We can process this section, so advance to next position to evaluate
                lookAhead += (compressedDiffBytes+1); // +1 is for code
            } else {
                break; // leave in current max position
            }
        } else {
            // Repeat section. Number of repeats is equal to lav-222, but the very first
            // value is the value to be repeated. The total number of compressed positions
            // is always == 3, one for the code and 2 for the 16-bit value
            if ( lookAhead+2 < updatedCompressionBuffer ) {
                lookAhead += 3;
            } else {
                break; // leave in current max position
            }
        }
    }
    // At this point, lookAhead is in an invalid position, which if equal to updatedCompressionBuffer
    // means the entire compressed update can be processed.
    V3DLONG compressionLength=lookAhead-compressionPosition;
    if (decompressionPosition==0) {
        // Needs to be initialized
        decompressionPosition=decompressionBuffer;
    }
    //qDebug() << "updateCompressionBuffer calling decompressPBD compressionPosition=" << compressionPosition << " decompressionPosition=" << decompressionPosition
    //        << " size=" << compressionLength << " previousTotalDecompSize=" << getDecompressionSize() << " maxDecompSize=" << maxDecompressionSize;
    V3DLONG dlength=decompressPBD16(compressionPosition, decompressionPosition, compressionLength);
    compressionPosition=lookAhead;
    decompressionPosition+=dlength;
    //printf("d2\n");
}

/* virtual */
int ImageLoaderBasic::exitWithError(std::string errorMessage) {
    std::cerr << errorMessage;
    if (fid!=0) {
        fclose(fid);
        fid = 0;
    }
    int berror=1;
    return berror;
}

int ImageLoaderBasic::loadRaw2StackPBD(const char* filename, Image4DSimple * image, bool useThreading)
{
    fid = fopen(filename, "rb");
    if (! fid)
        return exitWithError(std::string("Fail to open file for reading."));
    fseek (fid, 0, SEEK_END);
    V3DLONG fileSize = ftell(fid);
    rewind(fid);
    FileStarStream fileStream(fid);
    return loadRaw2StackPBD(fileStream, fileSize, image, useThreading);
}

/* virtual */
int ImageLoaderBasic::loadRaw2StackPBD(DataStream& fileStream, V3DLONG fileSize, Image4DSimple * image, bool useThreading)
{
    if (useThreading) {
        cerr << "Error: attempt to use threading with ImageLoaderBasic" << __FILE__ << __LINE__ << endl;
    }

    decompressionPrior = 0;
    int berror = 0;

    /* Read header */
    char formatkey[] = "v3d_volume_pkbitdf_encod";
    V3DLONG lenkey = strlen(formatkey);

#ifndef _MSC_VER //added by PHC, 2010-05-21
    if (fileSize<lenkey+2+4*4+1) // datatype has 2 bytes, and sz has 4*4 bytes and endian flag has 1 byte.
    {
        stringstream msg;
        msg << "The size of your input file is too small and is not correct, -- it is too small to contain the legal header.\n";
        msg << "The fseek-ftell produces a file size = " << fileSize;
        return exitWithError(msg.str());
    }
#endif

    keyread.resize(lenkey+1);
    // V3DLONG nread = fread(&keyread[0], 1, lenkey, fid);
    V3DLONG nread = fileStream.read(&keyread[0], lenkey);
    if (nread!=lenkey)
    {
        return exitWithError(std::string("File unrecognized or corrupted file."));
    }
    keyread[lenkey] = '\0';

    V3DLONG i;
    if (strcmp(formatkey, &keyread[0])) /* is non-zero then the two strings are different */
    {
        return exitWithError("Unrecognized file format.");
    }

    char endianCodeData;
    // fread(&endianCodeData, 1, 1, fid);
    fileStream.read(&endianCodeData, 1);
    if (endianCodeData!='B' && endianCodeData!='L')
    {
        return exitWithError("This program only supports big- or little- endian but not other format. Check your data endian.");
    }

    char endianCodeMachine;
    endianCodeMachine = checkMachineEndian();
    if (endianCodeMachine!='B' && endianCodeMachine!='L')
    {
        return exitWithError("This program only supports big- or little- endian but not other format. Check your data endian.");
    }

    int b_swap = (endianCodeMachine==endianCodeData)?0:1;

    short int dcode = 0;
    // fread(&dcode, 2, 1, fid); /* because I have already checked the file size to be bigger than the header, no need to check the number of actual bytes read. */
    fileStream.read((char*)&dcode, 2); /* because I have already checked the file size to be bigger than the header, no need to check the number of actual bytes read. */
    if (b_swap)
        swap2bytes((void *)&dcode);

    int datatype;

    switch (dcode)
    {
    case 1:
        datatype = 1; /* temporarily I use the same number, which indicates the number of bytes for each data point (pixel). This can be extended in the future. */
        break;

    case 2:
        datatype = 2;
        break;

    case 4:
        datatype = 4;
        break;

    default:
        stringstream msg;
        msg << "Unrecognized data type code [";
        msg << dcode;
        msg << "The file type is incorrect or this code is not supported in this version.";
        return exitWithError(msg.str());
    }

    // qDebug() << "Setting datatype=" << datatype;

    if (datatype==1) {
        image->setDatatype(V3D_UINT8);
    } else if (datatype==2) {
        image->setDatatype(V3D_UINT16);
    } else {
        return exitWithError("ImageLoader::loadRaw2StackPBD : only datatype=1 or datatype=2 supported");
    }
    loadDatatype=image->getDatatype(); // used for threaded loading

    // qDebug() << "Finished setting datatype=" << image->getDatatype();

    V3DLONG unitSize = datatype; // temporarily I use the same number, which indicates the number of bytes for each data point (pixel). This can be extended in the future.

    BIT32_UNIT mysz[4];
    mysz[0]=mysz[1]=mysz[2]=mysz[3]=0;
    // int tmpn=fread(mysz, 4, 4, fid); // because I have already checked the file size to be bigger than the header, no need to check the number of actual bytes read.
    int tmpn=fileStream.read((char*)mysz, 16); // because I have already checked the file size to be bigger than the header, no need to check the number of actual bytes read.
    if (tmpn!=16)
    {
        stringstream msg;
        msg << "This program only reads [" << tmpn << "] units.";
        return exitWithError(msg.str());
    }

    if (b_swap && (unitSize==2 || unitSize==4)) {
        stringstream msg;
        msg << "b_swap true and unitSize > 1 - this is not implemented in current code";
        return exitWithError(msg.str());
    }

    if (b_swap)
    {
        for (i=0;i<4;i++)
        {
            //swap2bytes((void *)(mysz+i));
            printf("mysz raw read unit[%ld]: [%d] ", i, mysz[i]);
            swap4bytes((void *)(mysz+i));
            printf("swap unit: [%d][%0x] \n", mysz[i], mysz[i]);
        }
    }

    std::vector<V3DLONG> sz(4, 0); // avoid memory leak
    // V3DLONG * sz = new V3DLONG [4]; // reallocate the memory if the input parameter is non-null. Note that this requests the input is also an NULL point, the same to img.

    V3DLONG totalUnit = 1;
    for (i=0;i<4;i++)
    {
        sz[i] = (V3DLONG)mysz[i];
        totalUnit *= sz[i];
    }

    //mexPrintf("The input file has a size [%ld bytes], different from what specified in the header [%ld bytes]. Exit.\n", fileSize, totalUnit*unitSize+4*4+2+1+lenkey);
    //mexPrintf("The read sizes are: %ld %ld %ld %ld\n", sz[0], sz[1], sz[2], sz[3]);

    V3DLONG headerSize=4*4+2+1+lenkey;
    V3DLONG compressedBytes=fileSize-headerSize;
    maxDecompressionSize=totalUnit*unitSize;

    compressionBuffer.resize(compressedBytes);

    V3DLONG remainingBytes = compressedBytes;
    //V3DLONG nBytes2G = V3DLONG(1024)*V3DLONG(1024)*V3DLONG(1024)*V3DLONG(2);
    V3DLONG readStepSizeBytes = V3DLONG(1024)*20000;
    totalReadBytes = 0;

    // done reading header
    // Transfer data to My4DImage

    // Allocating memory can take seconds.  So send a message
    image->createBlankImage(sz[0], sz[1], sz[2], sz[3], datatype);
    decompressionBuffer = image->getRawData();

    while (remainingBytes>0)
    {
        // qDebug() << "ImageLoader::loadRaw2StackPBD" << filename << stopwatch.elapsed() << __FILE__ << __LINE__;
        if (isCanceled()) {
            // clean and return
            // fclose(fid);
            return exitWithError(std::string("image load canceled"));
        }

        V3DLONG curReadBytes = (remainingBytes<readStepSizeBytes) ? remainingBytes : readStepSizeBytes;
        // nread = fread(&compressionBuffer[0]+totalReadBytes, 1, curReadBytes, fid);
        nread = fileStream.read((char*)(&compressionBuffer[0]+totalReadBytes), curReadBytes);
        totalReadBytes+=nread;
        if (nread!=curReadBytes)
        {
            stringstream msg;
            msg << "Something wrong in file reading. The program reads [";
            msg << nread << " data points] but the file says there should be [";
            msg << curReadBytes << " data points].";
            return exitWithError(msg.str());
        }
        remainingBytes -= nread;

        if (datatype==1) {
            updateCompressionBuffer8(&compressionBuffer[0]+totalReadBytes);
        } else {
            // assume datatype==2
            updateCompressionBuffer16(&compressionBuffer[0]+totalReadBytes);
        }

        if (isCanceled()) {
            return exitWithError(std::string("load canceled"));
        }
    }
    // qDebug() << "ImageLoader::loadRaw2StackPBD" << filename << stopwatch.elapsed() << __FILE__ << __LINE__;
    // qDebug() << "Total time elapsed after all reads is " << stopwatch.elapsed() / 1000.0 << " seconds";

    // clean and return
    // fclose(fid); //bug fix on 060412
    return berror;
}

