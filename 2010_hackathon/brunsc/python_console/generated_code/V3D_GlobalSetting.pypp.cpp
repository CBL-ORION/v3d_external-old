// This file has been generated by Py++.

#include "boost/python.hpp"
#include "wrappable_v3d.h"
#include "V3D_GlobalSetting.pypp.hpp"

namespace bp = boost::python;

void register_V3D_GlobalSetting_class(){

    bp::class_< V3D_GlobalSetting >( "V3D_GlobalSetting", bp::init< >() )    
        .def_readwrite( "GPara_df_compute_method", &V3D_GlobalSetting::GPara_df_compute_method )    
        .def_readwrite( "GPara_landmarkMatchingMethod", &V3D_GlobalSetting::GPara_landmarkMatchingMethod )    
        .def_readwrite( "autoVideoCardStreamMode", &V3D_GlobalSetting::autoVideoCardStreamMode )    
        .def_readwrite( "b_3dcurve_autoconnecttips", &V3D_GlobalSetting::b_3dcurve_autoconnecttips )    
        .def_readwrite( "b_3dcurve_autodeform", &V3D_GlobalSetting::b_3dcurve_autodeform )    
        .def_readwrite( "b_3dcurve_autowidth", &V3D_GlobalSetting::b_3dcurve_autowidth )    
        .def_readwrite( "b_3dcurve_inertia", &V3D_GlobalSetting::b_3dcurve_inertia )    
        .def_readwrite( "b_3dcurve_width_from_xyonly", &V3D_GlobalSetting::b_3dcurve_width_from_xyonly )    
        .def_readwrite( "b_UseMylibTiff", &V3D_GlobalSetting::b_UseMylibTiff )    
        .def_readwrite( "b_autoConvert2_8bit", &V3D_GlobalSetting::b_autoConvert2_8bit )    
        .def_readwrite( "b_autoDispBoundingBox", &V3D_GlobalSetting::b_autoDispBoundingBox )    
        .def_readwrite( "b_autoDispXYZAxes", &V3D_GlobalSetting::b_autoDispXYZAxes )    
        .def_readwrite( "b_autoOpenImg3DViewer", &V3D_GlobalSetting::b_autoOpenImg3DViewer )    
        .def_readwrite( "b_autoRescale16bitDisplay", &V3D_GlobalSetting::b_autoRescale16bitDisplay )    
        .def_readwrite( "b_autoSWCLineMode", &V3D_GlobalSetting::b_autoSWCLineMode )    
        .def_readwrite( "b_autoVideoCard3DTex", &V3D_GlobalSetting::b_autoVideoCard3DTex )    
        .def_readwrite( "b_autoVideoCardCompress", &V3D_GlobalSetting::b_autoVideoCardCompress )    
        .def_readwrite( "b_autoVideoCardNPTTex", &V3D_GlobalSetting::b_autoVideoCardNPTTex )    
        .def_readwrite( "b_plugin_dispParameterDialog", &V3D_GlobalSetting::b_plugin_dispParameterDialog )    
        .def_readwrite( "b_plugin_dispResInNewWindow", &V3D_GlobalSetting::b_plugin_dispResInNewWindow )    
        .def_readwrite( "b_plugin_outputImgConvert2UINT8", &V3D_GlobalSetting::b_plugin_outputImgConvert2UINT8 )    
        .def_readwrite( "b_plugin_outputImgRescale", &V3D_GlobalSetting::b_plugin_outputImgRescale )    
        .def_readwrite( "b_yaxis_up", &V3D_GlobalSetting::b_yaxis_up )    
        .def_readwrite( "default_lookglass_size", &V3D_GlobalSetting::default_lookglass_size )    
        .def_readwrite( "default_marker_radius", &V3D_GlobalSetting::default_marker_radius )    
        .def_readwrite( "default_rightshift_bits", &V3D_GlobalSetting::default_rightshift_bits )    
        .def_readwrite( "iChannel_for_plugin", &V3D_GlobalSetting::iChannel_for_plugin )    
        .def_readwrite( "marker_disp_amplifying_factor", &V3D_GlobalSetting::marker_disp_amplifying_factor );

}
