#include "PrivateDataColorModel.h"
#include <algorithm>
#include <cmath>
#include <cassert>

PrivateDataColorModel::PrivateDataColorModel()
    : sharedGamma(1.0)
{}

PrivateDataColorModel::PrivateDataColorModel(const PrivateDataColorModel& rhs)
{
    channelColors = rhs.channelColors;
    sharedGamma = rhs.sharedGamma;
    // qDebug() << "PrivateDataColorModel copy ctor";
}

/* virtual */
PrivateDataColorModel::~PrivateDataColorModel() {}

// Crudely populate 3-channel rgb color model based on n-channel data color model,
// for use in fast mode of 3D viewer update.
// Input HDR range is set to 0-255 for now.
void PrivateDataColorModel::colorizeIncremental(
        const DataColorModel::Reader& desiredColorReader,
        const DataColorModel::Reader& currentColorReader)
{
    assert(desiredColorReader.getNumberOfDataChannels() == currentColorReader.getNumberOfDataChannels());
    const int numChannels = desiredColorReader.getNumberOfDataChannels();
    if (numChannels != channelColors.size()) {
        channelColors.assign(numChannels, ChannelColorModel(0));
    }
    qreal incGamma = currentColorReader.getSharedGamma() / desiredColorReader.getSharedGamma();
    setSharedGamma(incGamma);
    for (int chan = 0; chan < numChannels; ++chan)
    {
        channelColors[chan].bUseSharedGamma = desiredColorReader.getChannelUseSharedGamma(chan);
        // Use latest color information.  TODO - there might no good way to incrementally update channel colors.
        channelColors[chan].setColor(desiredColorReader.getChannelColor(chan));
        channelColors[chan].showChannel = desiredColorReader.getChannelVisibility(chan);
        // Set incremental gamma; qInc = qDes / qCur
        incGamma = desiredColorReader.getChannelGamma(chan) / currentColorReader.getChannelGamma(chan); // the usual case
        setChannelGamma(chan, incGamma); // setChannelGamma() folds in sharedGamma
        // channelColors[chan].setGamma(incGamma); // channel.setGamma() does not fold in sharedGamma
        // Set incremental HDR range, on a data scale of 0.0-1.0 (though hdrMin/Max might be outside that range)
        channelColors[chan].setDataRange(0.0, 1.0);
        qreal desRange = desiredColorReader.getChannelHdrMax(chan) - desiredColorReader.getChannelHdrMin(chan);
        qreal curRange = currentColorReader.getChannelHdrMax(chan) - currentColorReader.getChannelHdrMin(chan);
        // avoid divide by zero
        if (0 == desRange) desRange = 0.0001;
        if (0 == curRange) curRange = 0.0001;
        qreal incRange = desRange / curRange; // hdr range
        qreal totalInputRange = desiredColorReader.getChannelDataMax(chan) - desiredColorReader.getChannelDataMin(chan); // data range, NOT hdr range
        if (0 == totalInputRange) totalInputRange = 0.0001;
        qreal incMin = (desiredColorReader.getChannelHdrMin(chan) - currentColorReader.getChannelHdrMin(chan)) / totalInputRange;
        qreal incMax = incMin + incRange;
        channelColors[chan].setHdrRange(incMin, incMax);
    }
}

bool PrivateDataColorModel::autoCorrect(const NaVolumeData::Reader& volumeReader)
{
    if (! volumeReader.hasReadLock()) return false;
    const Image4DProxy<My4DImage>& volProxy = volumeReader.getOriginalImageProxy();
    if (volProxy.sx <= 0) return false; // data not populated yet?
    int numChannels = volProxy.sc;
    if (volumeReader.hasReferenceImage())
        numChannels += 1; // Add one for reference channel
    for (int channel = 0; channel < numChannels; ++channel)
    {
        ChannelColorModel& channelModel = channelColors[channel];
        const IntensityHistogram& hist = volumeReader.getHistogram(channel);
        // Use quantile range
        int rangeMin = hist.quantileIntensity(0.50);
        int rangeMax = hist.quantileIntensity(1.00);
        if (channel == volProxy.sc) // reference channel
        {
            rangeMin = hist.quantileIntensity(0.10);
            rangeMax = hist.quantileIntensity(1.00);
        }
        qDebug() << "Data channel" << channel << "adjusted range is" << rangeMin << "to" << rangeMax;
        channelModel.setHdrRange(rangeMin, rangeMax);
    }
}

bool PrivateDataColorModel::initialize(const NaVolumeData::Reader& volumeReader)
{
    setSharedGamma(1.0);
    if (! volumeReader.hasReadLock()) return false;
    const Image4DProxy<My4DImage>& volProxy = volumeReader.getOriginalImageProxy();
    if (volProxy.sx <= 0) return false; // data not populated yet?
    const Image4DProxy<My4DImage>& refProxy = volumeReader.getReferenceImageProxy();
    // Add one for reference channel
    int numChannels = volProxy.sc;
    if (volumeReader.hasReferenceImage())
        numChannels += 1;
    channelColors.clear();
    for (int channel = 0; channel < numChannels; ++channel)
    {
        // Channel color
        // The Janelia Zeiss microscope computers are configured to show the data channels as blue/green/red/gray
        // from pairs of images gray/blue/green and gray/red.
        // Single channel gets colored white
        QRgb color = qRgb(255, 255, 255);
        if (numChannels > 1) {
            int remainder = channel % 4; // cycle through blue, green, red, gray
            if (remainder == 0) {
                color = qRgb(255, 0, 0); // red
            }
            else if (remainder == 1) {
                color = qRgb(0, 255, 0); // green
            }
            else if (remainder == 2) {
                color = qRgb(0, 0, 255); // blue
            }
            else {
                color = qRgb(170, 170, 170); // white/gray reference
            }
        }
        ChannelColorModel channelModel(color);
        // Initialize intensity range to entire observed range
        if (channel < volProxy.sc) // fragments and background
        {
            channelModel.setDataRange(volProxy.vmin[channel], volProxy.vmax[channel]);
            channelModel.resetHdrRange();
        }
        else // reference channel
        {
            channelModel.setDataRange(refProxy.vmin[0], refProxy.vmax[0]); // darken reference by giving it a higher hdr max
            channelModel.resetHdrRange();
            channelModel.bUseSharedGamma = false; // Don't apply shared gamma to reference channel
        }
        channelColors.push_back(channelModel);
        // qDebug() << "Channel color " << channelColors.size() << qRed(color) << qGreen(color) << qBlue(color);
    }
    return true;
}

const PrivateDataColorModel::ChannelColorModel& PrivateDataColorModel::getReferenceChannel() const {
    return channelColors.back();
}

QRgb PrivateDataColorModel::blend(const double channelIntensities[]) const {
    int red, green, blue;
    red = green = blue = 0;
    int sc = (int)channelColors.size();
    for (int c = 0; c < sc; ++c) {
        if (channelIntensities[c] == 0.0)
            continue;
        if (! channelColors[c].showChannel)
            continue;
        const ChannelColorModel& ccm = channelColors[c];
        QRgb channelColor = ccm.getColor(channelIntensities[c]);
        red += qRed(channelColor);
        green += qGreen(channelColor);
        blue += qBlue(channelColor);
    }
    red = min(255, red);
    green = min(255, green);
    blue = min(255, blue);
    return qRgb(red, green, blue);
}

QRgb PrivateDataColorModel::blendInvisible(const double channelIntensities[]) const {
    int red, green, blue;
    red = green = blue = 0;
    int sc = (int)channelColors.size();
    for (int c = 0; c < sc; ++c) {
        if (channelIntensities[c] == 0.0)
            continue;
        const ChannelColorModel& ccm = channelColors[c];
        QRgb channelColor = ccm.getInvisibleColor(channelIntensities[c]);
        red += qRed(channelColor);
        green += qGreen(channelColor);
        blue += qBlue(channelColor);
    }
    red = min(255, red);
    green = min(255, green);
    blue = min(255, blue);
    return qRgb(red, green, blue);
}

QRgb PrivateDataColorModel::blend(const std::vector<double>& channelIntensities) const {
    return blend(&channelIntensities[0]);
}

bool PrivateDataColorModel::setChannelColor(int index, QRgb color)
{
    if (channelColors[index].channelColor == color)
        return false; // no change
    channelColors[index].setColor(color);
    return true;
}

bool PrivateDataColorModel::hasChannelHdrRange(int index, qreal minParam, qreal maxParam) const
{
    if (index >= channelColors.size()) return false;
    return ( (channelColors[index].hdrMin == minParam)
          && (channelColors[index].hdrMax == maxParam) );
}

bool PrivateDataColorModel::setChannelHdrRange(int index, qreal minParam, qreal maxParam)
{
    // qDebug() << "setChannelHdrRange" << index << minParam << maxParam;
    if ( hasChannelHdrRange(index, minParam, maxParam) )
        return false; // no change
    channelColors[index].setHdrRange(minParam, maxParam);
    return true;
}

bool PrivateDataColorModel::setSharedGamma(qreal gamma) // for all channels
{
    bool bChanged = false;
    if (gamma == sharedGamma)
        return bChanged;
    qreal incGamma = gamma / sharedGamma; // Compute change in gamma
    // Update channels *before* updating sharedGamma
    for (int c = 0; c < channelColors.size(); ++c)
    {
        qreal oldChannelGamma = getChannelGamma(c);
        if (channelColors[c].bUseSharedGamma)
            channelColors[c].setGamma( gamma * oldChannelGamma );
    }
    sharedGamma = gamma;
    bChanged = true;
    return bChanged;
}

bool PrivateDataColorModel::setChannelGamma(int index, qreal gammaParam)
{
    qreal gamma = gammaParam / sharedGamma; // Correct for preapplication of global gamma
    if (! channelColors[index].bUseSharedGamma)
        gamma = gammaParam;
    if (channelColors[index].gamma == gamma)
        return false; // no change
    channelColors[index].setGamma(gamma);
    return true;
}

QRgb PrivateDataColorModel::getChannelColor(int channelIndex) const {
    return channelColors[channelIndex].getColor();
}

qreal PrivateDataColorModel::getChannelHdrMin(int channel) const {
    return channelColors[channel].getHdrMin();
}

qreal PrivateDataColorModel::getChannelHdrMax(int channel) const {
    return channelColors[channel].getHdrMax();
}

qreal PrivateDataColorModel::getChannelDataMin(int channel) const
{
    return channelColors[channel].getDataMin();
}

qreal PrivateDataColorModel::getChannelDataMax(int channel) const
{
    return channelColors[channel].getDataMax();
}

qreal PrivateDataColorModel::getReferenceScaledIntensity(qreal raw_intensity) const {
    return getReferenceChannel().getScaledIntensity(raw_intensity);
}

qreal PrivateDataColorModel::getChannelScaledIntensity(int channel, qreal raw_intensity) const {
    return channelColors[channel].getScaledIntensity(raw_intensity);
}

qreal PrivateDataColorModel::getChannelGamma(int channel) const {
    if (channelColors[channel].bUseSharedGamma)
        return channelColors[channel].getGamma() / sharedGamma; // Correct for preapplied shared Gamma
    else
        return channelColors[channel].getGamma();
}

qreal PrivateDataColorModel::getSharedGamma() const {
    return sharedGamma;
}

bool PrivateDataColorModel::setChannelVisibility(int index, bool isVisibleParam)
{
    if (index >= channelColors.size()) return false;
    if (index < 0) return false;
    if (channelColors[index].showChannel == isVisibleParam) return false;
    channelColors[index].showChannel = isVisibleParam;
    return true;
}

bool PrivateDataColorModel::getChannelVisibility(int index) const
{
    if (index >= channelColors.size()) return false;
    if (index < 0) return false;
    return channelColors[index].showChannel;
}

bool PrivateDataColorModel::setChannelUseSharedGamma(int index, bool useIt)
{
    if (useIt == channelColors[index].bUseSharedGamma) return false;
    channelColors[index].bUseSharedGamma = useIt;
    return true;
}

bool PrivateDataColorModel::getChannelUseSharedGamma(int index) const
{
    return channelColors[index].bUseSharedGamma;
}

//////////////////////////////////////////////////////
// PrivateDataColorModel::ChannelColorModel methods //
//////////////////////////////////////////////////////

PrivateDataColorModel::ChannelColorModel::ChannelColorModel(QRgb channelColorParam)
    : blackColor(qRgb(0, 0, 0))
    , showChannel(true)
    , bUseSharedGamma(true)
{
    setColor(channelColorParam);
    setGamma(1.0f);
    setDataRange(0, 4095);
    resetHdrRange();
}

void PrivateDataColorModel::ChannelColorModel::setColor(QRgb channelColorParam)
{
    channelColor = channelColorParam;
    colorRed = qRed(channelColor);
    colorGreen = qGreen(channelColor);
    colorBlue = qBlue(channelColor);
}

QRgb PrivateDataColorModel::ChannelColorModel::getColor() const {return channelColor;}

void PrivateDataColorModel::ChannelColorModel::setHdrRange(qreal hdrMinParam, qreal hdrMaxParam)
{
    // qDebug() << "PrivateDataColorModel::ChannelColorModel::setHdrRange()" << hdrMinParam << hdrMaxParam;
    if (! (hdrMinParam == hdrMinParam)) // NaN
    {
        qDebug() << "hdrMinParam set to NaN";
        return; // don't do that.
    }
    hdrMin = hdrMinParam;
    hdrMax = hdrMaxParam;
    hdrRange = hdrMaxParam - hdrMinParam;
}

void PrivateDataColorModel::ChannelColorModel::setDataRange(qreal dataMinParam, qreal dataMaxParam)
{
    dataMin = dataMinParam;
    dataMax = dataMaxParam;
}

void PrivateDataColorModel::ChannelColorModel::resetHdrRange()
{
    setHdrRange(dataMin, dataMax);
}

/// Stored gamma with sharedGamma already applied.  (Unlike PrivateDataColorModel::setChannelGamma(g))
void PrivateDataColorModel::ChannelColorModel::setGamma(qreal gammaParam)
{
    // qDebug() << "PrivateDataColorModel::ChannelColorModel::setGamma()" << gammaParam << __FILE__ << __LINE__;
    gamma = gammaParam;
    gammaIsNotUnity = (gamma != 1.0f); // premature optimization
    // populate gamma lookup table
    qreal previous_i_out = 0.0f;
    for (int i = 0; i < 256; ++i) {
        qreal i_in = i / 255.0f; // range 0.0-1.0
        qreal i_out = std::pow(i_in, gamma);
        gammaTable[i] = i_out;
        if (i > 0)
            dGammaTable[i - 1] = i_out - previous_i_out;
        previous_i_out = i_out;
    }
    dGammaTable[255] = 0.0f; // final unused entry for neatness
}

// Returns a value in the range 0.0-1.0
// Applies channel visibility toggle
qreal PrivateDataColorModel::ChannelColorModel::getScaledIntensity(qreal raw_intensity) const
{
    if (! showChannel) return 0.0;
    return getInvisibleScaledIntensity(raw_intensity);
}

// Returns a value in the range 0.0-1.0
// Ignores channel visibility toggle.
qreal PrivateDataColorModel::ChannelColorModel::getInvisibleScaledIntensity(qreal raw_intensity) const
{
    if (raw_intensity <= hdrMin) return 0.0; // clamp below
    if (raw_intensity >= hdrMax) return 1.0; // clamp above
    if (hdrRange <= 0) return 0.5;
    // 1) Apply hdr interval
    qreal i = (raw_intensity - hdrMin)/hdrRange;

    /*
    if (   (colorGreen == 255) // debug green channel
        && (raw_intensity > 0.266)
        && (raw_intensity < 0.267) ) // i_in = 68
    {
        qDebug() << "ChannelColorModel::getScaledIntensity" << raw_intensity << i
                << hdrMin << hdrMax << hdrRange
                << __FILE__ << __LINE__;
    }
     */

    // 2) Apply gamma correction
    if (gammaIsNotUnity)
    {
       qreal gf = i * 255.0f; // index for lookup table, including decimal fraction
       int gi = int(gf); // index for lookup table
       i = gammaTable[gi] + dGammaTable[gi] * (gf - gi); // Taylor series interpolation
    }
    return i;
}

QRgb PrivateDataColorModel::ChannelColorModel::getInvisibleColor(qreal raw_intensity) const
{
    if (raw_intensity <= hdrMin) return blackColor; // clamp below
    if (raw_intensity >= hdrMax) return channelColor; // clamp above
    const qreal i = getInvisibleScaledIntensity(raw_intensity);
    return qRgb(int(i * colorRed), int(i * colorGreen), int(i * colorBlue));
}

QRgb PrivateDataColorModel::ChannelColorModel::getColor(qreal raw_intensity) const
{
    if (! showChannel) return blackColor;
    return getInvisibleColor(raw_intensity);
}



