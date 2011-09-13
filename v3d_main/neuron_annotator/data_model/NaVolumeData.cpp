#include "NaVolumeData.h"
#include <iostream>
#include <QFuture>
#include <cassert>

using namespace std;


/////////////////////////////////////////
// NaVolumeDataLoadableStack methods //
/////////////////////////////////////////

class SleepThread : QThread {
public:
    SleepThread() {}
    void msleep(int milliseconds) {
        QThread::msleep(milliseconds);
    }
};

NaVolumeDataLoadableStack::NaVolumeDataLoadableStack(My4DImage* stackpParam, QString filenameParam, int stackIndexParam)
   : QObject(NULL)
   , stackp(stackpParam)
   , filename(filenameParam)
   , stackIndex(stackIndexParam)
   , progressValue(0)
   , progressMin(0)
   , progressMax(100)
{
}

bool NaVolumeDataLoadableStack::load()
{
    setRelativeProgress(0.01); // getting here *is* finite progress
    qDebug() << "NaVolumeData::LoadableStack::load() filename=" << filename;
    const QByteArray fileArray = filename.toAscii();
    stackp->loadImage(const_cast<char *>(fileArray.data()));
    if (stackp->isEmpty()) {
        emit failed();
        return false;
    }
    setRelativeProgress(0.70);
    stackp->updateminmaxvalues();
    setRelativeProgress(1.0);
    emit finished();
    return true;
}

void NaVolumeDataLoadableStack::setRelativeProgress(float relativeProgress)
{
    int newProgressValue = (int) (progressMin + relativeProgress * (progressMax - progressMin) + 0.5);
    assert(newProgressValue >= progressMin);
    assert(newProgressValue <= progressMax);
    if (newProgressValue == progressValue) return;
    progressValue = newProgressValue;
    emit progressValueChanged(progressValue, stackIndex);
}


//////////////////////////
// NaVolumeData methods //
//////////////////////////

/* explicit */
NaVolumeData::NaVolumeData()
    : originalImageStack(NULL)
    , neuronMaskStack(NULL)
    , referenceStack(NULL)
    , emptyImage(new My4DImage())
    , originalImageProxy(emptyImage)
    , neuronMaskProxy(emptyImage)
    , referenceImageProxy(emptyImage)
    , currentProgress(0)
{
}

NaVolumeData::~NaVolumeData()
{
    Writer volumeWriter(*this); // Wait for readers to finish before deleting
    volumeWriter.clearImageData();
}

/* slot */
void NaVolumeData::setStackLoadProgress(int progressValue, int stackIndex)
{
    // qDebug() << "setStackLoadProgress()" << progressValue << stackIndex;
    if (stackIndex < 0) {
        qDebug() << "stack index less than zero";
        return;
    }
    if (stackIndex >= stackLoadProgressValues.size()) {
        qDebug() << "stack index out of range";
        return;
    }
    if (progressValue == stackLoadProgressValues[stackIndex])
        return; // no change
    // TODO - use different weights for each stack depending on file size.
    stackLoadProgressValues[stackIndex] = progressValue;
    float totalProgressValue = 0.0;
    for (int i = 0; i < stackLoadProgressValues.size(); ++i) {
        totalProgressValue += stackLoadProgressValues[i] * 1.0 / stackLoadProgressValues.size();
    }
    setProgressValue((int) (totalProgressValue + 0.5));
}

/* slot */
void NaVolumeData::setProgressValue(int progressValue)
{
    if (progressValue < 0) return;
    if (progressValue > 100) return;
    if (progressValue == currentProgress) return;
    currentProgress = progressValue;
    qDebug() << "NaVolumeData load progress =" << currentProgress;
    emit progressValueChanged(currentProgress);
}

/* slot */
void NaVolumeData::loadVolumeDataFromFiles()
{
    QTime stopwatch;
    stopwatch.start();

    { // Allocate writer on the stack so write lock will be automatically released when method returns
        Writer volumeWriter(*this);
        volumeWriter.clearImageData();

        emit progressMessageChanged("Loading image stack files");
        if (!volumeWriter.loadStacks()) {
            volumeWriter.unlock(); // unlock before emit
            emit progressAborted(QString("Problem loading stacks"));
            return;
        }
    } // release locks before emit

    // nerd report
    size_t data_size = 0;
    data_size += originalImageStack->getTotalBytes();
    data_size += referenceStack->getTotalBytes();
    data_size += neuronMaskStack->getTotalBytes();
    qDebug() << "Loading 16-bit image data from disk took " << stopwatch.elapsed() / 1000.0 << " seconds";
    qDebug() << "Loading 16-bit image data from disk absorbed "
            << (double)data_size / double(1e6) << " MB of RAM"; // kibibytes boo hoo whatever...

    emit progressCompleted();
    emit dataChanged();
}

//////////////////////////////////
// NaVolumeData::Writer methods //
//////////////////////////////////

void NaVolumeData::Writer::clearLandmarks()
{
    if (m_data->originalImageStack != NULL)
        m_data->originalImageStack->listLandmarks.clear();
}

void NaVolumeData::Writer::setLandmarks(const QList<LocationSimple> locations)
{
    if (m_data->originalImageStack != NULL)
        m_data->originalImageStack->listLandmarks = locations;
}

void NaVolumeData::Writer::clearImageData()
{
    if (m_data->originalImageStack != NULL) {
        delete m_data->originalImageStack;
        m_data->originalImageStack = NULL;
    }
    if (m_data->neuronMaskStack != NULL) {
        delete m_data->neuronMaskStack;
        m_data->neuronMaskStack = NULL;
    }
    if (m_data->referenceStack != NULL) {
        delete m_data->referenceStack;
        m_data->referenceStack = NULL;
    }
    if (m_data->emptyImage != NULL) {
        delete m_data->emptyImage;
        m_data->emptyImage = NULL;
    }
}

bool NaVolumeData::Writer::loadStacks()
{
    QTime stopwatch;
    stopwatch.start();

    QList< QFuture<void> > loaderList;

    // Prepare to track progress of 3 file load operations
    m_data->stackLoadProgressValues.assign(3, 0);
    m_data->currentProgress = -1; // to make sure progress value changes on the next line
    m_data->setProgressValue(0);
    QCoreApplication::processEvents(); // ensure that progress bar gets displayed

    m_data->originalImageStack = new My4DImage();
    LoadableStack originalStack(m_data->originalImageStack, m_data->originalImageStackFilePath, 0);
    connect(&originalStack, SIGNAL(progressValueChanged(int, int)),
            m_data, SLOT(setStackLoadProgress(int, int)));
    qDebug() << "NaVolumeData::Writer::loadStacks() starting originalStack.load()";
    // Pass stack pointer instead of stack reference to avoid problem with lack of QObject copy constructor.
    QFuture<void> originalLoader = QtConcurrent::run(&originalStack, &LoadableStack::load);
    loaderList.append(originalLoader);

    m_data->neuronMaskStack = new My4DImage();
    LoadableStack maskStack(m_data->neuronMaskStack, m_data->maskLabelFilePath, 1);
    connect(&maskStack, SIGNAL(progressValueChanged(int, int)),
            m_data, SLOT(setStackLoadProgress(int, int)));
    qDebug() << "NaVolumeData::Writer::loadStacks() starting maskStack.load()";
    QFuture<void> maskLoader = QtConcurrent::run(&maskStack, &LoadableStack::load);
    loaderList.append(maskLoader);

    My4DImage* initialReferenceStack = new My4DImage();
    LoadableStack referenceStack(initialReferenceStack, m_data->referenceStackFilePath, 2);
    connect(&referenceStack, SIGNAL(progressValueChanged(int, int)),
            m_data, SLOT(setStackLoadProgress(int, int)));
    qDebug() << "NaVolumeData::Writer::loadStacks() starting referenceStack.load()";
    QFuture<void> referenceLoader = QtConcurrent::run(&referenceStack, &LoadableStack::load);
    loaderList.append(referenceLoader);

    while(1) {
        SleepThread st;
        st.msleep(1000);
        int doneCount=0;
        for (int i=0;i<loaderList.size();i++) {
            QFuture<void> loader=loaderList.at(i);
            if (loader.isFinished()) {
                doneCount++;
            }
        }
        int stillActive=loaderList.size()-doneCount;
        if (stillActive==0) {
            break;
        } else {
            qDebug() << "Waiting on " << stillActive << " loaders";
        }
        QCoreApplication::processEvents(); // let progress signals through
    }

    qDebug() << "NaVolumeData::Writer::loadStacks() done loading all stacks in " << stopwatch.elapsed() / 1000.0 << " seconds";

    m_data->originalImageProxy = Image4DProxy<My4DImage>(m_data->originalImageStack);
    m_data->originalImageProxy.set_minmax(m_data->originalImageStack->p_vmin, m_data->originalImageStack->p_vmax);

    m_data->neuronMaskProxy = Image4DProxy<My4DImage>(m_data->neuronMaskStack);
    m_data->neuronMaskProxy.set_minmax(m_data->neuronMaskStack->p_vmin, m_data->neuronMaskStack->p_vmax);

    normalizeReferenceStack(initialReferenceStack);

    return true;
}

bool NaVolumeData::Writer::normalizeReferenceStack(My4DImage* initialReferenceStack)
{
    m_data->referenceStack=new My4DImage();
    My4DImage * referenceStack = m_data->referenceStack;
    referenceStack->loadImage(initialReferenceStack->getXDim(), initialReferenceStack->getYDim(), initialReferenceStack->getZDim(), 1 /* number of channels */, 1 /* bytes per channel */);
    Image4DProxy<My4DImage> initialProxy(initialReferenceStack);
    Image4DProxy<My4DImage> referenceProxy(referenceStack);

    double initialMin=initialReferenceStack->getChannalMinIntensity(0);
    double initialMax=initialReferenceStack->getChannalMaxIntensity(0);

    qDebug() << "Populating reference with initial data";
    double initialRange=initialMax-initialMin;
    qDebug() << "Reference lsm initialMin=" << initialMin << " initialMax=" << initialMax << " initialRange=" << initialRange;
    int zDim=initialReferenceStack->getZDim();
    int yDim=initialReferenceStack->getYDim();
    int xDim=initialReferenceStack->getXDim();
    for (int z=0;z<zDim;z++) {
        for (int y=0;y<yDim;y++) {
            for (int x=0;x<xDim;x++) {
                int value= (255.0*(*initialProxy.at_uint16(x,y,z,0))-initialMin)/initialRange;
                if (value<0) {
                    value=0;
                } else if (value>255) {
                    value=255;
                }
                referenceProxy.put8bit_fit_at(x,(yDim-y)-1,z,0,value); // For some reason, the Y-dim seems to need inversion
            }
        }
    }
    initialReferenceStack->cleanExistData();
    delete initialReferenceStack;
    referenceStack->updateminmaxvalues();

    m_data->referenceImageProxy = Image4DProxy<My4DImage>(m_data->referenceStack);
    m_data->referenceImageProxy.set_minmax(m_data->referenceStack->p_vmin, m_data->referenceStack->p_vmax);

    qDebug() << "Finished loading reference stack";

    return true;
}

//////////////////////////////////
// NaVolumeData::Reader methods //
//////////////////////////////////

const Image4DProxy<My4DImage>& NaVolumeData::Reader::getNeuronMaskProxy() const
{
    return m_data->neuronMaskProxy;
}

const Image4DProxy<My4DImage>& NaVolumeData::Reader::getOriginalImageProxy() const
{
    return m_data->originalImageProxy;
}

const Image4DProxy<My4DImage>& NaVolumeData::Reader::getReferenceImageProxy() const
{
    return m_data->referenceImageProxy;
}


