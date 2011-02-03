
TEMPLATE      = app
CONFIG       += qt plugin warn_off
macx: CONFIG       -= app_bundle 
#CONFIG       += x86_64

V3DMAINDIR = ../../../v3d_external/v3d_main

INCLUDEPATH  += $$V3DMAINDIR/basic_c_fun

HEADERS       = istitch.h 
HEADERS      +=	istitch_gui.h
HEADERS      +=	$$V3DMAINDIR/basic_c_fun/stackutil.h
HEADERS      +=	$$V3DMAINDIR/basic_c_fun/mg_utilities.h
HEADERS      += $$V3DMAINDIR/basic_c_fun/mg_image_lib.h

SOURCES       = istitch.cpp
SOURCES      +=	$$V3DMAINDIR/basic_c_fun/stackutil.cpp
SOURCES      +=	$$V3DMAINDIR/basic_c_fun/mg_utilities.cpp
SOURCES      +=	$$V3DMAINDIR/basic_c_fun/mg_image_lib.cpp

LIBS         += -lm -L../../v3d_main/common_lib/lib -lv3dtiff -lpthread
LIBS	     += -lfftw3f -lfftw3f_threads
#LIBS	     += -L/usr/local/lib/libfftw3f.a -L/usr/local/lib/libfftw3f_threads.a


