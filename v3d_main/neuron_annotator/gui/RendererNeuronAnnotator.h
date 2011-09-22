#ifndef RENDERERNEURONANNOTATOR_H
#define RENDERERNEURONANNOTATOR_H

#include <QObject>
#include "../../3drenderer/renderer_gl2.h"
#include "../geometry/Vector3D.h"

class RendererNeuronAnnotator : public QObject, public Renderer_gl2
{

Q_OBJECT

public:
    RendererNeuronAnnotator(void* widget);
    virtual ~RendererNeuronAnnotator();
    virtual void loadVol();
    virtual int hitMenu(int x, int y, bool b_glwidget);
    bool populateNeuronMaskAndReference(const My4DImage* my4Dmask, const My4DImage* referenceImage);

    void rebuildFromBaseTextures(const QList<int>& maskIndexList, QList<RGBA8*>& overlayList);

    void updateCurrentTextureMask(int maskIndex, int state);
    bool initializeTextureMasks();
    void setMasklessSetupStackTexture(bool state) { masklessSetupStackTexture=state; }
    // useful value for computing zoom level
    float getZoomedPerspectiveViewAngle() const {return viewAngle * zoomRatio;}
    void setInternalZoomRatio(float z) {zoomRatio = z;}
    float glUnitsPerImageVoxel() const {
        return 2.0 / boundingBox.Dmax();
    }
    RGBA8* getOverlayTextureByAnnotationIndex(int index);
    const RGBA8* getTexture3DCurrent() const;
    bool hasBadMarkerViewMatrix() const // to help avoid a crash
    {
        return (! (markerViewMatrix[0] == markerViewMatrix[0]));
    }
    void clearLandmarks()
    {
        if (0 == listMarker.size()) return; // already clear
        listMarker.clear();
    }
    void setLandmarks(const QList<ImageMarker>& landmarks)
    {
        if (landmarks == listMarker) return; // no change
        listMarker = landmarks;
    }


signals:
    void progressValueChanged(int);
    void progressComplete();
    void progressMessageChanged(QString);

protected:
    virtual void setupStackTexture(bool bfirst);
    void load3DTextureSet(RGBA8* tex3DBuf);
    RGBA8* extendTextureFromMaskList(const QList<RGBA8*> & sourceTextures, const QList<int> & maskIndexList);
    void cleanExtendedTextures();
    // void updateProgressDialog(QProgressDialog & dialog, int level);
    bool populateBaseTextures();

    // We want all of these OFF for now to keep the texture handling constant across different hardware environments
    virtual bool supported_TexStream() {return false;}
    virtual void setupTexStreamBuffer() {tex_stream_buffer = false;}
    virtual void cleanTexStreamBuffer() {tex_stream_buffer = false;}
    virtual bool _streamingTex() {return false;}
    virtual void _streamTex(int stack_i, int slice_i, int step, int slice0, int slice1) {}
    virtual void _streamTex_end() {}

private:
    unsigned char* neuronMask; // sized to texture buffer dimensions realX,Y,Z
    RGBA8* texture3DSignal;
    RGBA8* texture3DReference;
    RGBA8* texture3DBackground;
    RGBA8* texture3DBlank;
    RGBA8* texture3DCurrent;
    bool textureSetAlreadyLoaded;
    bool masklessSetupStackTexture;
};

#endif // RENDERERNEURONANNOTATOR_H
