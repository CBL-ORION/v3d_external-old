#ifndef __CurvatureAnisotropicDiffusion_H__
#define __CurvatureAnisotropicDiffusion_H__

#include "V3DITKPluginDefaultHeader.h"

class CurvatureAnisotropicDiffusionPlugin : public QObject, public V3DPluginInterface
{
  Q_OBJECT
  Q_INTERFACES(V3DPluginInterface)
  V3DITKPLUGIN_DEFAULT_CLASS_DECLARATION_BODY(CurvatureAnisotropicDiffusion);
};

#endif
