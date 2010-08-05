
TEMPLATE	= lib
CONFIG		+= plugin warn_off
CONFIG		+= x86_64

INCLUDEPATH	+= /System/Library/Frameworks/JavaVM.framework/Headers \
               ../../../v3d_main/basic_c_fun \
                dependent/include
LIBS		 = -framework JavaVM \
				-L/usr/local/lib/ -lboost_thread \
				dependent/lib64/libbfcpp.dylib \
				dependent/lib64/libjace.dylib

HEADERS       = bioFormat_ex.h
SOURCES       = bioFormat_ex.cpp

TARGET        = $$qtLibraryTarget(readImage_bioformat)
QMAKE_POST_LINK = cp dependent/lib64/* ../../v3d;

DESTDIR       =  ../../v3d/plugins/ImageIO_bioformat

