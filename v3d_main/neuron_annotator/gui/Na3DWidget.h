#ifndef NA3DWIDGET_H
#define NA3DWIDGET_H

#include "../../3drenderer/v3dr_glwidget.h"
#include "../../v3d/xformwidget.h"
#include "NaViewer.h"
#include "../geometry/Rotation3D.h"
#include "MouseClickManager.h"
#include <cmath>
#include "NeuronContextMenu.h"
#include "Stereo3dMode.h"
#include <stdint.h>

class RendererNeuronAnnotator;
class DataColorModel;
namespace jfrc {
    class VolumeTexture;
}

#if defined (_MSC_VER)
#include "../basic_c_fun/vcdiff.h"
#else
#endif

// Derived class of V3dR_GLWidget so we can use a simpler constructor
// for the convenience of Qt Designer,
// and to customize features for NeuronAnnotator.
class Na3DWidget : public V3dR_GLWidget, public NaViewer
{
    Q_OBJECT

public:
    Na3DWidget(QWidget* parent);
    virtual ~Na3DWidget();
    virtual void initializeGL();
    const Vector3D& focus() const {return cameraModel.focus();}
    float getZoomScale() const; // in viewport pixels per image voxel at focus
    virtual void mouseMoveEvent(QMouseEvent * event);
    virtual void mousePressEvent(QMouseEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent * event);
    virtual void wheelEvent(QWheelEvent * e); // zoom with scroll wheel
    virtual void mouseDoubleClickEvent(QMouseEvent * event); // double click to center
    virtual void keyPressEvent(QKeyEvent *e);
    virtual void keyReleaseEvent(QKeyEvent *e);
    virtual void resizeEvent(QResizeEvent * event);
    virtual void moveEvent(QMoveEvent * event);
    virtual void setDataFlowModel(const DataFlowModel*);
    void resetVolumeCutRange();
    virtual RendererNeuronAnnotator* getRendererNa();
    virtual const RendererNeuronAnnotator* getRendererNa() const;
    void setResizeEnabled(bool b) {bResizeEnabled = b;}
    int neuronAt(QPoint pos);
    void setContextMenus(QMenu* viewerMenu, NeuronContextMenu* neuronMenu);
    Vector3D getDefaultFocus() const;
    // Don't update if the current rotation is within 0.5 of the specified integer angle
    void setXYZBodyRotationInt(int rotX, int rotY, int rotZ);
    static int radToDeg(double angleInRadians);
    static bool eulerAnglesAreEquivalent(int x1, int y1, int z1, int x2, int y2, int z2);
    bool screenShot(QString filename);
    void setUndoStack(QUndoStack& undoStackParam); // for undo/redo custom clip planes
    int getSlabPosition() const;

signals:
    void neuronSelected(double x, double y, double z);
    void progressValueChanged(int);
    void progressComplete();
    void progressMessageChanged(QString);
    void progressAborted(QString);
    void alphaBlendingChanged(bool);
    void quadStereoSupported(bool);
    void showCornerAxesChanged(bool);
    void slabThicknessChanged(int);
    void slabPositionChanged(int);
    void volume3DUploaded();
    void signalTextureLoaded();
    void labelTextureLoaded();
    void visibilityTextureLoaded();
    void colorMapTextureLoaded();
    void scenePainted(); // useful for timing
    void benchmarkTimerResetRequested();
    void benchmarkTimerPrintRequested(QString);

public slots:
    void setShowCornerAxes(bool b);
    void setAlphaBlending(bool);
    void DEPRECATEDonVolumeTextureDataChanged();
    void updateIncrementalColors();
    void showContextMenu(QPoint point);
    void resetView();
    void resetRotation();
    void translateImage(int dx, int dy);
    void showCrosshair(bool b) {NaViewer::showCrosshair(b); update();}
    void updateHighlightNeurons();
    void onMouseSingleClick(QPoint pos);
    void onNotSingleClick();
    void onPossibleSingleClickAlert();
    virtual void updateImageData();
    void setXCutLock(int b);
    void setYCutLock(int b);
    void setZCutLock(int b);
    void setStereoOff(bool);
    void setStereoLeftEye(bool);
    void setStereoRightEye(bool);
    void setStereoQuadBuffered(bool);
    void setStereoAnaglyphRedCyan(bool);
    void setStereoAnaglyphGreenMagenta(bool);
    void setStereoRowInterleaved(bool);
    void setStereoColumnInterleaved(bool);
    void setStereoCheckerInterleaved(bool b);
    void setStereoMode(int);
    void setCustomCutMode();
    void cancelCustomCutMode();
    void applyCustomCut();
    void setSlabThickness(int); // range 2-1000 voxels
    void setSlabPosition(int); // range -500 - +500 voxels
    void clipSlab(); // Apply clip plane to current slab
    void updateScreenPosition(); // for stencil based 3D modes
    void initializeDefaultTextures();

protected slots:
    // focus setting should be done via cameraModel, not with these methods.
    void updateRendererZoomRatio(qreal relativeScale);
    void updateRotation(const Rotation3D&);
    void updateFocus(const Vector3D& f);
    // VolumeTexture methods that must be run in the main/OpenGL thread are implemented in Na3DWidget slots
    bool loadSignalTexture(); // with locking
    bool loadSignalTexture3D(size_t w, size_t h, size_t d, const uint32_t* texture_data); // raw
    bool loadLabelTexture(); // with locking
    bool loadLabelTexture3D(size_t w, size_t h, size_t d, const uint16_t* texture_data);
    bool loadVisibilityTexture();
    bool loadVisibilityTexture2D(const uint32_t* texture_data);
    bool loadColorMapTexture(); // TODO
    bool loadColorMapTexture2D(const uint32_t* texture_data); // TODO

public:
    QElapsedTimer widgetStopwatch;

protected:
    // bool tryUpdateFullVolume();
    bool bResizeEnabled; // to disable resizes during progressBar show/hide
    virtual void resizeGL(int, int);
    void updateCursor();
    void highlightNeuronAtPosition(QPoint pos);
    // Rotation helper methods
    static int round(double d);
    static bool anglesAreEqual(int a1, int a2); // in degrees
    virtual void paintGL();
    void paintFiducial(const Vector3D& v);
    void paintGrid();
    virtual void choiceRenderer(); // Create a new internal renderer object
    virtual void settingRenderer(); // Apply settings to internal renderer object
    float glUnitsPerImageVoxel() const;
    void updateDefaultScale();
    // v3dr_glwidget::event() can cause crash
    virtual bool event(QEvent* e) {QGLWidget::event(e);}

    // BrightnessCalibrator<unsigned char> brightnessCalibrator;
    const DataColorModel * incrementalDataColorModel;
    QCursor * rotateCursor;
    QMenu* viewerContextMenu;
    NeuronContextMenu* neuronContextMenu;
    bool bHasQuadStereo;
    bool bShowCornerAxes;
    bool bAlphaBlending;
    bool bClickIsWaiting;
    bool bGLIsInitialized;
    QUndoStack* undoStack;
    qreal cachedRelativeScale;
    jfrc::Stereo3DMode stereo3DMode;
    bool bStereoSwapEyes;

    // We use 4 textures in the shader
    // Some times we want to initialize them to non-pathological values
    unsigned int defaultVolumeTextureId;
    unsigned int defaultColormapTextureId;
    unsigned int defaultVisibilityTextureId;
    unsigned int defaultLabelTextureId;

    mutable Vector3D cachedDefaultFocus;
    mutable bool cachedDefaultFocusIsDirty;
};

#endif // NA3DWIDGET_H
