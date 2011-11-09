// This file has been generated by Py++.

#include "boost/python.hpp"
#include "wrappable_v3d.h"
#include "QWidget.pypp.hpp"

namespace bp = boost::python;

void register_QWidget_class(){

    { //::QWidget
        typedef bp::class_< QWidget, boost::noncopyable > QWidget_exposer_t;
        QWidget_exposer_t QWidget_exposer = QWidget_exposer_t( "QWidget", bp::no_init );
        bp::scope QWidget_scope( QWidget_exposer );
        bp::enum_< QWidget::RenderFlag>("RenderFlag")
            .value("DrawWindowBackground", QWidget::DrawWindowBackground)
            .value("DrawChildren", QWidget::DrawChildren)
            .value("IgnoreMask", QWidget::IgnoreMask)
            .export_values()
            ;
    }

}
