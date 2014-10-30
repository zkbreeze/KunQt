#-------------------------------------------------
#
# Project created by QtCreator 2014-10-15T11:09:40
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testKVS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    kunscreen.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    kunscreen.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../local/kvs1814/lib/release/ -lkvsCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../local/kvs1814/lib/debug/ -lkvsCore
else:unix: LIBS += -L$$PWD/../../../../local/kvs1814/lib/ -lkvsCore

INCLUDEPATH += $$PWD/../../../../local/kvs1814/include
DEPENDPATH += $$PWD/../../../../local/kvs1814/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/release/libkvsCore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/debug/libkvsCore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/release/kvsCore.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/debug/kvsCore.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/libkvsCore.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../local/kvs1814/lib/release/ -lkvsSupportGLUT
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../local/kvs1814/lib/debug/ -lkvsSupportGLUT
else:unix: LIBS += -L$$PWD/../../../../local/kvs1814/lib/ -lkvsSupportGLUT

INCLUDEPATH += $$PWD/../../../../local/kvs1814/include
DEPENDPATH += $$PWD/../../../../local/kvs1814/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/release/libkvsSupportGLUT.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/debug/libkvsSupportGLUT.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/release/kvsSupportGLUT.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/debug/kvsSupportGLUT.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/libkvsSupportGLUT.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../local/kvs1814/lib/release/ -lkvsSupportQt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../local/kvs1814/lib/debug/ -lkvsSupportQt
else:unix: LIBS += -L$$PWD/../../../../local/kvs1814/lib/ -lkvsSupportQt

INCLUDEPATH += $$PWD/../../../../local/kvs1814/include
DEPENDPATH += $$PWD/../../../../local/kvs1814/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/release/libkvsSupportQt.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/debug/libkvsSupportQt.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/release/kvsSupportQt.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/debug/kvsSupportQt.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../local/kvs1814/lib/libkvsSupportQt.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../opt/local/lib/release/ -lGLEW
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../opt/local/lib/debug/ -lGLEW
else:unix: LIBS += -L$$PWD/../../../../../../opt/local/lib/ -lGLEW

INCLUDEPATH += $$PWD/../../../../../../opt/local/include
DEPENDPATH += $$PWD/../../../../../../opt/local/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../opt/local/lib/release/libGLEW.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../opt/local/lib/debug/libGLEW.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../opt/local/lib/release/GLEW.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../../opt/local/lib/debug/GLEW.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../../../opt/local/lib/libGLEW.a
