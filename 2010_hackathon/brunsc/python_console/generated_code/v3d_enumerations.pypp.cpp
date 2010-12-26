// This file has been generated by Py++.

#include "boost/python.hpp"
#include "wrappable_v3d.h"
#include "v3d_enumerations.pypp.hpp"

namespace bp = boost::python;

void register_enumerations(){

    bp::enum_< ImagePixelType>("ImagePixelType")
        .value("V3D_UNKNOWN", V3D_UNKNOWN)
        .value("V3D_UINT8", V3D_UINT8)
        .value("V3D_UINT16", V3D_UINT16)
        .value("V3D_FLOAT32", V3D_FLOAT32)
        .export_values()
        ;

    bp::enum_< PxLocationMarkerShape>("PxLocationMarkerShape")
        .value("pxUnset", pxUnset)
        .value("pxSphere", pxSphere)
        .value("pxCube", pxCube)
        .value("pxCircleX", pxCircleX)
        .value("pxCircleY", pxCircleY)
        .value("pxCircleZ", pxCircleZ)
        .value("pxSquareX", pxSquareX)
        .value("pxSquareY", pxSquareY)
        .value("pxSquareZ", pxSquareZ)
        .value("pxLineX", pxLineX)
        .value("pxLineY", pxLineY)
        .value("pxLineZ", pxLineZ)
        .value("pxTriangle", pxTriangle)
        .value("pxDot", pxDot)
        .export_values()
        ;

    bp::enum_< PxLocationUsefulness>("PxLocationUsefulness")
        .value("pxUnknown", pxUnknown)
        .value("pxLocaNotUseful", pxLocaNotUseful)
        .value("pxLocaUseful", pxLocaUseful)
        .value("pxLocaUnsure", pxLocaUnsure)
        .value("pxTemp", pxTemp)
        .export_values()
        ;

    bp::enum_< TimePackType>("TimePackType")
        .value("TIME_PACK_NONE", TIME_PACK_NONE)
        .value("TIME_PACK_Z", TIME_PACK_Z)
        .value("TIME_PACK_C", TIME_PACK_C)
        .export_values()
        ;

}
