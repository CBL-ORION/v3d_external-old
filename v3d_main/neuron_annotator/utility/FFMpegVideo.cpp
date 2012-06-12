#include "FFMpegVideo.h"

#ifdef USE_FFMPEG

extern "C"
{
#include <libswscale/swscale.h>
}

#include <QMutexLocker>
#include <stdexcept>
#include <iostream>

using namespace std;

// Translated to C++ by Christopher Bruns May 2012
// from ffmeg_adapt.c in whisk package by Nathan Clack, Mark Bolstadt, Michael Meeuwisse

QMutex FFMpegVideo::mutex;

// Avoid link error on some macs
#ifdef __APPLE__
extern "C" {
#include <stdlib.h>
#include <errno.h>
// #include "compiler/compiler.h"

/*
 * Darwin doesn't have posix_memalign(), provide a private
 * weak alternative
 */
    /*
int __weak posix_memalign(void **ptr, size_t align, size_t size)
{
       if (*ptr)
               return 0;

       return ENOMEM;
}
*/
}
#endif

/////////////////////////////
// AVPacketWrapper methods //
/////////////////////////////

class AVPacketWrapper
{
public:
    AVPacketWrapper();
    virtual ~AVPacketWrapper();
    void free();

    AVPacket packet;
};


AVPacketWrapper::AVPacketWrapper()
{
    packet.destruct = NULL;
}

/* virtual */
AVPacketWrapper::~AVPacketWrapper()
{
    free();
}

void AVPacketWrapper::free()
{
    av_free_packet(&packet);
}


/////////////////////////
// FFMpegVideo methods //
/////////////////////////

FFMpegVideo::FFMpegVideo(PixelFormat pixelFormat)
{
    initialize();
    format = pixelFormat;
}

FFMpegVideo::FFMpegVideo(const std::string& fileName, PixelFormat pixelFormat)
{
    QMutexLocker lock(&FFMpegVideo::mutex);
    initialize();
    format = pixelFormat;
    open(fileName, pixelFormat);
}

/* virtual */
FFMpegVideo::~FFMpegVideo()
{
    QMutexLocker lock(&FFMpegVideo::mutex);
    if (NULL != Sctx) {
        sws_freeContext(Sctx);
        Sctx = NULL;
    }
    if (NULL != pRaw) {
        av_free(pRaw);
        pRaw = NULL;
    }
    if (NULL != pFrameRGB) {
        av_free(pFrameRGB);
        pFrameRGB = NULL;
    }
    if (NULL != pCtx) {
        avcodec_close(pCtx);
        pCtx = NULL;
    }
    if (NULL != container) {
        avformat_close_input(&container);
        container = NULL;
    }
    if (NULL != buffer) {
        av_free(buffer);
        buffer = NULL;
    }
    if (NULL != blank) {
        av_free(blank);
        blank = NULL;
    }
    // Don't need to free pCodec?
}

void FFMpegVideo::open(const std::string& fileName, enum PixelFormat formatParam)
{
    format = formatParam;
    sc = getNumberOfChannels();

    // Open file, check usability
    avtry( avformat_open_input(&container, fileName.c_str(), NULL, NULL), fileName );
    avtry( avformat_find_stream_info(container, NULL), "Cannot find stream information." );
    avtry( videoStream=av_find_best_stream(container, AVMEDIA_TYPE_VIDEO, -1, -1, &pCodec, 0), "Cannot find a video stream." );
    pCtx=container->streams[videoStream]->codec;
    width  = pCtx->width;
    height = pCtx->height;
    avtry( avcodec_open2(pCtx, pCodec, NULL), "Cannot open video decoder." );

    /* Frame rate fix for some codecs */
    if( pCtx->time_base.num > 1000 && pCtx->time_base.den == 1 )
        pCtx->time_base.den = 1000;

    /* Compute the total number of frames in the file */
    /* duration is in microsecs */
    numFrames = (int)(( container->duration / (double)AV_TIME_BASE ) * pCtx->time_base.den );

    /* Get framebuffers */
    if (! (pRaw = avcodec_alloc_frame()) )
        throw std::runtime_error("");
    if (! (pFrameRGB = avcodec_alloc_frame()) )
        throw std::runtime_error("");

    /* Create data buffer */
    if (format == PIX_FMT_NONE) {
        numBytes = 0;
        buffer = NULL;
        blank = NULL;
        pFrameRGB = NULL;
        Sctx = NULL;
    }
    else {
        numBytes = avpicture_get_size( format, pCtx->width, pCtx->height ); // RGB24 format
        if (! (buffer   = (uint8_t*)av_malloc(numBytes + FF_INPUT_BUFFER_PADDING_SIZE)) ) // RGB24 format
            throw std::runtime_error("");
        if (! (blank    = (uint8_t*)av_mallocz(avpicture_get_size(pCtx->pix_fmt,width,height))) ) // native codec format
            throw std::runtime_error("");

        /* Init buffers */
        avpicture_fill( (AVPicture * ) pFrameRGB, buffer, format,
                        pCtx->width, pCtx->height );

        /* Init scale & convert */
        if (! (Sctx=sws_getContext(
                pCtx->width,
                pCtx->height,
                pCtx->pix_fmt,
                width,
                height,
                format,
                SWS_POINT, // fastest?
                NULL,NULL,NULL)) )
            throw std::runtime_error("");
    }

    /* Give some info on stderr about the file & stream */
    //dump_format(container, 0, fname, 0);

    previousFrameIndex = -1;
}

bool FFMpegVideo::fetchFrame(int targetFrameIndex)
{
    if ((targetFrameIndex < 0) || (targetFrameIndex > numFrames))
        return false;
    if (targetFrameIndex == (previousFrameIndex + 1)) {
        if (! readNextFrame(targetFrameIndex))
            return false;
    }
    else
        if (seekToFrame(targetFrameIndex) < 0)
            return false;
    previousFrameIndex = targetFrameIndex;
    return true;
}

// \returns current frame on success, otherwise -1
int FFMpegVideo::seekToFrame(int targetFrameIndex)
{
    int64_t duration = container->streams[videoStream]->duration;
    int64_t ts = av_rescale(duration,targetFrameIndex,numFrames);
    int64_t tol = av_rescale(duration,1,2*numFrames);
    if ( (targetFrameIndex < 0) || (targetFrameIndex >= numFrames) ) {
        return -1;
    }
    int result = avformat_seek_file( container, //format context
                            videoStream,//stream id
                            0,               //min timestamp
                            ts,              //target timestamp
                            ts,              //max timestamp
                            0); //AVSEEK_FLAG_ANY),//flags
    if (result < 0)
        return -1;

    avcodec_flush_buffers(pCtx);
    if (! readNextFrame(targetFrameIndex))
        return -1;

    return targetFrameIndex;
}

bool FFMpegVideo::readNextFrame(int targetFrameIndex)
{
    AVPacket packet = {0};
    av_init_packet(&packet);
    bool result = readNextFrameWithPacket(targetFrameIndex, packet, pRaw);
    av_free_packet(&packet);
    return result;
}

bool FFMpegVideo::readNextFrameWithPacket(int targetFrameIndex, AVPacket& packet, AVFrame* pYuv)
{
    int finished = 0;
    do {
        finished = 0;
        av_free_packet(&packet);
        int result = av_read_frame( container, &packet ); // !!NOTE: see docs on packet.convergence_duration for proper seeking
        if (result != 0) {
            av_free_packet(&packet);
            return false;
        }
        if( packet.stream_index != videoStream ) /* Is it what we're trying to parse? */
        {
            av_free_packet(&packet);
            continue;
        }
        result = avcodec_decode_video2( pCtx, pYuv, &finished, &packet );
        if (result <= 0) {
            av_free_packet(&packet);
            return false;
        }
        if(pCtx->codec_id==CODEC_ID_RAWVIDEO && !finished)
        {
            avpicture_fill( (AVPicture * ) pYuv, blank, pCtx->pix_fmt,width, height ); // set to blank frame
            finished=1;
        }
#if 0 // very useful for debugging
        cout << "Packet - pts:" << (int)packet.pts;
        cout << " dts:" << (int)packet.dts;
        cout << " - flag: " << packet.flags;
        cout << " - finished: " << finished;
        cout << " - Frame pts:" << (int)pYuv->pts;
        cout << " " << (int)pYuv->best_effort_timestamp;
        cout << endl;
        /* printf("Packet - pts:%5d dts:%5d (%5d) - flag: %1d - finished: %3d - Frame pts:%5d %5d\n",
               (int)packet.pts,(int)packet.dts,
               packet.flags,finished,
               (int)pYuv->pts,(int)pYuv->best_effort_timestamp); */
#endif
        if(!finished)
            if (packet.pts == AV_NOPTS_VALUE)
                throw std::runtime_error("");
    } while ( (!finished) || (pYuv->best_effort_timestamp < targetFrameIndex));

    if (format != PIX_FMT_NONE) {
        sws_scale(Sctx,              // sws context
                  pYuv->data,        // src slice
                  pYuv->linesize,    // src stride
                  0,                      // src slice origin y
                  pCtx->height,      // src slice height
                  pFrameRGB->data,        // dst
                  pFrameRGB->linesize );  // dst stride
    }

    previousFrameIndex = targetFrameIndex;
    return true;
}

uint8_t FFMpegVideo::getPixelIntensity(int x, int y, Channel c) const
{
    return *(pFrameRGB->data[0] + y * pFrameRGB->linesize[0] + x * sc + c);
}

int FFMpegVideo::getNumberOfFrames() const { return numFrames; }

int FFMpegVideo::getWidth() const { return width; }

int FFMpegVideo::getHeight() const { return height; }

int FFMpegVideo::getNumberOfChannels() const
{
    switch(format)
    {
    case PIX_FMT_BGRA:
        return 4;
        break;
    case PIX_FMT_RGB24:
        return 3;
        break;
    case PIX_FMT_GRAY8:
        return 1;
        break;
    default:
        return 0;
        break;
    }
    return 0;
}

void FFMpegVideo::initialize()
{
    Sctx = NULL;
    pRaw = NULL;
    pFrameRGB = NULL;
    pCtx = NULL;
    container = NULL;
    buffer = NULL;
    blank = NULL;
    pCodec = NULL;
    format = PIX_FMT_NONE;
    FFMpegVideo::maybeInitFFMpegLib();
}

void FFMpegVideo::maybeInitFFMpegLib()
{
    if (FFMpegVideo::b_is_one_time_inited)
        return;
    av_register_all();
    avcodec_register_all();
    avformat_network_init();
    FFMpegVideo::b_is_one_time_inited = true;
}

void FFMpegVideo::avtry(int result, const std::string& msg) {
    if ((result < 0) && (result != AVERROR_EOF)) {
        char buf[1024];
        av_strerror(result, buf, sizeof(buf));
        std::string message = std::string("FFMpeg Error: ") + msg + buf;
        throw std::runtime_error(message.c_str());
    }
}

bool FFMpegVideo::b_is_one_time_inited = false;



///////////////////////////
// FFMpegEncoder methods //
///////////////////////////


FFMpegEncoder::FFMpegEncoder(const char * file_name, int width, int height, enum CodecID codec_id)
    : picture_yuv(NULL)
    , picture_rgb(NULL)
    , container(NULL)
{
    if (0 != (width % 2))
        cerr << "WARNING: Video width is not a multiple of 2" << endl;
    if (0 != (height % 2))
        cerr << "WARNING: Video height is not a multiple of 2" << endl;

    FFMpegVideo::maybeInitFFMpegLib();

    container = avformat_alloc_context();
    if (NULL == container)
        throw std::runtime_error("Unable to allocate format context");

    AVOutputFormat * fmt = av_guess_format(NULL, file_name, NULL);
    if (!fmt)
        fmt = av_guess_format("mpeg", NULL, NULL);
    if (!fmt)
        throw std::runtime_error("Unable to deduce video format");
    container->oformat = fmt;

    fmt->video_codec = codec_id;
    // fmt->video_codec = CODEC_ID_H264; // fails to write

    AVStream * video_st = avformat_new_stream(container, NULL);

    pCtx = video_st->codec;
    pCtx->codec_id = fmt->video_codec;
    pCtx->codec_type = AVMEDIA_TYPE_VIDEO;
    // resolution must be a multiple of two
    pCtx->width = width;
    pCtx->height = height;

    // bit_rate determines image quality
    pCtx->bit_rate = width * height * 4; // ?
    // pCtx->qmax = 50; // no effect?

    // "high quality" parameters from http://www.cs.ait.ac.th/~on/mplayer/pl/menc-feat-enc-libavcodec.html
    // vcodec=mpeg4:mbd=2:mv0:trell:v4mv:cbp:last_pred=3:predia=2:dia=2:vmax_b_frames=2:vb_strategy=1:precmp=2:cmp=2:subcmp=2:preme=2:vme=5:naq:qns=2
    if (false) // does not help
    // if (pCtx->codec_id == CODEC_ID_MPEG4)
    {
        pCtx->mb_decision = 2;
        pCtx->last_predictor_count = 3;
        pCtx->pre_dia_size = 2;
        pCtx->dia_size = 2;
        pCtx->max_b_frames = 2;
        pCtx->b_frame_strategy = 2;
        pCtx->trellis = 2;
        pCtx->compression_level = 2;
        pCtx->global_quality = 300;
        pCtx->pre_me = 2;
        pCtx->mv0_threshold = 1;
        // pCtx->quantizer_noise_shaping = 2; // deprecated
        // TODO
    }

    pCtx->time_base = (AVRational){1, 25};
    // pCtx->time_base = (AVRational){1, 10};
    pCtx->gop_size = 12; // emit one intra frame every twelve frames
    // pCtx->max_b_frames = 0;
    pCtx->pix_fmt = PIX_FMT_YUV420P;
    if (fmt->flags & AVFMT_GLOBALHEADER)
        pCtx->flags |= CODEC_FLAG_GLOBAL_HEADER;

    if (pCtx->codec_id == CODEC_ID_H264)
    {
        // http://stackoverflow.com/questions/3553003/encoding-h-264-with-libavcodec-x264
        pCtx->coder_type = 1;  // coder = 1
        pCtx->flags|=CODEC_FLAG_LOOP_FILTER;   // flags=+loop
        pCtx->me_cmp|= 1;  // cmp=+chroma, where CHROMA = 1
        // pCtx->partitions|=X264_PART_I8X8+X264_PART_I4X4+X264_PART_P8X8+X264_PART_B8X8; // partitions=+parti8x8+parti4x4+partp8x8+partb8x8
        pCtx->me_method=ME_HEX;    // me_method=hex
        pCtx->me_subpel_quality = 7;   // subq=7
        pCtx->me_range = 16;   // me_range=16
        pCtx->gop_size = 250;  // g=250
        pCtx->keyint_min = 25; // keyint_min=25
        pCtx->scenechange_threshold = 40;  // sc_threshold=40
        pCtx->i_quant_factor = 0.71; // i_qfactor=0.71
        pCtx->b_frame_strategy = 1;  // b_strategy=1
        pCtx->qcompress = 0.6; // qcomp=0.6
        pCtx->qmin = 10;   // qmin=10
        pCtx->qmax = 51;   // qmax=51
        pCtx->max_qdiff = 4;   // qdiff=4
        pCtx->max_b_frames = 3;    // bf=3
        pCtx->refs = 3;    // refs=3
        // pCtx->directpred = 1;  // directpred=1
        pCtx->trellis = 1; // trellis=1
        // pCtx->flags2|=CODEC_FLAG2_BPYRAMID+CODEC_FLAG2_MIXED_REFS+CODEC_FLAG2_WPRED+CODEC_FLAG2_8X8DCT+CODEC_FLAG2_FASTPSKIP;  // flags2=+bpyramid+mixed_refs+wpred+dct8x8+fastpskip
        // pCtx->weighted_p_pred = 2; // wpredp=2
        // libx264-main.ffpreset preset
        // pCtx->flags2|=CODEC_FLAG2_8X8DCT;
        // pCtx->flags2^=CODEC_FLAG2_8X8DCT;    // flags2=-dct8x8
    }

    AVCodec * codec = avcodec_find_encoder(pCtx->codec_id);
    if (NULL == codec)
        throw std::runtime_error("Unable to find Mpeg4 codec");
    if (codec->pix_fmts)
        pCtx->pix_fmt = codec->pix_fmts[0];
    {
        QMutexLocker lock(&FFMpegVideo::mutex);
        if (avcodec_open2(pCtx, codec, NULL) < 0)
            throw std::runtime_error("Error opening codec");
    }

    /* Get framebuffers */
    if (! (picture_yuv = avcodec_alloc_frame()) ) // final frame format
        throw std::runtime_error("");
    if (! (picture_rgb = avcodec_alloc_frame()) ) // rgb version I can understand easily
        throw std::runtime_error("");
    /* the image can be allocated by any means and av_image_alloc() is
         * just the most convenient way if av_malloc() is to be used */
    if ( av_image_alloc(picture_yuv->data, picture_yuv->linesize,
                       pCtx->width, pCtx->height, pCtx->pix_fmt, 1) < 0 )
        throw std::runtime_error("Error allocating YUV frame buffer");
    if ( av_image_alloc(picture_rgb->data, picture_rgb->linesize,
                   pCtx->width, pCtx->height, PIX_FMT_RGB24, 1) < 0 )
        throw std::runtime_error("Error allocating RGB frame buffer");

    /* Init scale & convert */
    if (! (Sctx=sws_getContext(
            width,
            height,
            PIX_FMT_RGB24,
            pCtx->width,
            pCtx->height,
            pCtx->pix_fmt,
            SWS_BICUBIC,NULL,NULL,NULL)) )
        throw std::runtime_error("");

    /* open the output file */
    if (!(fmt->flags & AVFMT_NOFILE))
    {
        QMutexLocker lock(&FFMpegVideo::mutex);
        if (avio_open(&container->pb, file_name, AVIO_FLAG_WRITE) < 0)
             throw std::runtime_error("Error opening output video file");
    }
    avformat_write_header(container, NULL);
}

void FFMpegEncoder::setPixelIntensity(int x, int y, int c, uint8_t value)
{
    uint8_t * ptr = picture_rgb->data[0] + y * picture_rgb->linesize[0] + x * 3 + c;
    *ptr = value;
}

void FFMpegEncoder::write_frame()
{
    // convert from RGB24 to YUV
    sws_scale(Sctx,              // sws context
              picture_rgb->data,        // src slice
              picture_rgb->linesize,    // src stride
              0,                      // src slice origin y
              pCtx->height,      // src slice height
              picture_yuv->data,        // dst
              picture_yuv->linesize );  // dst stride

    /* encode the image */
    // use non-deprecated avcodec_encode_video2(...)
    AVPacket packet;
    av_init_packet(&packet);
    packet.data = NULL;
    packet.size = 0;

    int got_packet;
    int ret = avcodec_encode_video2(pCtx,
                                    &packet,
                                    picture_yuv,
                                    &got_packet);
    if (ret < 0)
        throw std::runtime_error("Video encoding failed");
    if (got_packet)
    {
        // std::cout << "encoding frame" << std::endl;
        int result = av_write_frame(container, &packet);
        av_destruct_packet(&packet);
    }
}

/* virtual */
FFMpegEncoder::~FFMpegEncoder()
{
    int result = av_write_frame(container, NULL); // flush
    result = av_write_trailer(container);
    {
        QMutexLocker lock(&FFMpegVideo::mutex);
        avio_close(container->pb);
    }
    for (int i = 0; i < container->nb_streams; ++i)
        av_freep(container->streams[i]);
    av_free(container);
    container = NULL;

    {
        QMutexLocker lock(&FFMpegVideo::mutex);
        avcodec_close(pCtx);
    }
    av_free(pCtx);
    pCtx = NULL;
    av_free(picture_yuv->data[0]);
    av_free(picture_yuv);
    picture_yuv = NULL;
    av_free(picture_rgb->data[0]);
    av_free(picture_rgb);
    picture_rgb = NULL;
}

#endif // USE_FFMPEG

