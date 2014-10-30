#=============================================================================
#  KVS directory.
#=============================================================================
KVS_DIR = $$(KVS_DIR)

isEmpty( KVS_DIR ) {
    error( "KVS_DIR is not defined." )
}


#=============================================================================
#  Template.
#=============================================================================
TEMPLATE = app


#=============================================================================
#  Target.
#=============================================================================
TARGET = test


#=============================================================================
#  Configuration valiable.
#=============================================================================
CONFIG += release warn_off opengl
QT     += opengl


#=============================================================================
#  Definition.
#=============================================================================
win32 {
    DEFINES += WIN32 _MBCS NOMINMAX _SCL_SECURE_NO_DEPRECATE _CRT_SECURE_NO_DEPRECATE _CRT_NONSTDC_NO_DEPRECATE
}

DEFINES += NDEBUG KVS_SUPPORT_GLUT KVS_SUPPORT_QT


#=============================================================================
#  Include path.
#=============================================================================
INCLUDEPATH += $$KVS_DIR/include

KVS_GLEW_DIR = $$(KVS_GLEW_DIR)
GLEW_INCLUDE_PATH = 
GLEW_LIBRARY_PATH = 
!isEmpty( KVS_GLEW_DIR )
{
    GLEW_INCLUDE_PATH = $$KVS_GLEW_DIR/include
    GLEW_LIBRARY_PATH = $$KVS_GLEW_DIR/lib
}

INCLUDEPATH += $$GLEW_INCLUDE_PATH

#=============================================================================
#  Link library.
#=============================================================================
win32 {
    LIBS += \
$$KVS_DIR/lib/kvsSupportQt.lib \
$$KVS_DIR/lib/kvsSupportGLUT.lib \
$$KVS_DIR/lib/kvsCore.lib \
glew32.lib

}

macx {
    LIBS += \
$$KVS_DIR/lib/libkvsSupportQt.a \
$$KVS_DIR/lib/libkvsSupportGLUT.a \
$$KVS_DIR/lib/libkvsCore.a \
-framework GLUT \
-L$$GLEW_LIBRARY_PATH -lGLEW \

}

x11 {
    LIBS += \
$$KVS_DIR/lib/libkvsSupportQt.a \
$$KVS_DIR/lib/libkvsSupportGLUT.a \
$$KVS_DIR/lib/libkvsCore.a \
-lglut \
-L$$GLEW_LIBRARY_PATH -lGLEW \

}

#=============================================================================
#  Include.
#=============================================================================
exists( kvsmake.qt.conf ) { include( kvsmake.qt.conf ) }


#=============================================================================
#  Header.
#=============================================================================
HEADERS += \
glwidget.h \
mainwindow.h \



#=============================================================================
#  Source.
#=============================================================================
SOURCES += \
glwidget.cpp \
main.cpp \
mainwindow.cpp \



#=============================================================================
#  Resource.
#=============================================================================
RESOURCES += \


