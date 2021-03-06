QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    App/app.cpp \
    App/main.cpp \
    Common/utils.cpp \
    Model/imagemodel.cpp \
    Parameter/parameter.cpp \
    View/viewnotification.cpp \
    View/mainwindow.cpp \
    View/view.cpp \
    ViewModel/viewmodelcommand.cpp \
    ViewModel/imageviewmodel.cpp \
    ViewModel/viewmodelnotification.cpp

HEADERS += \
    App/app.h \
    Common/etl.h \
    Common/utils.h \
    Model/imagemodel.h \
    Parameter/parameter.h \
    View/viewnotification.h \
    View/mainwindow.h \
    View/view.h \
    ViewModel/viewmodelcommand.h \
    ViewModel/imageviewmodel.h \
    ViewModel/viewmodelnotification.h

FORMS += \
    View/mainwindow.ui

INCLUDEPATH += $$PWD/Common/opencv/include
LIBS += $$PWD/Common/opencv/lib/libopencv_*.a

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target
