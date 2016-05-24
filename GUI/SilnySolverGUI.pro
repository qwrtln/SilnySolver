#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T18:01:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SilnySolverGUI
TEMPLATE = app


SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS  += \
    inc/mainwindow.h \
    ../Dev/inc/CrazyCube.h \
    ../Dev/inc/CrazyCubeAbstract.h \
    ../Dev/inc/CrazyCubeBase.h \
    ../Dev/inc/CrazyCubeCache.h \
    ../Dev/inc/CrazyCubeImproved.h \
    ../Dev/inc/CrazyCubeMapper.h \
    ../Dev/inc/CrazyCubeSolver.h \
    ../Dev/inc/CrazyCubeSolverParametersD.h \
    ../Dev/inc/FileReader.h \
    ../Dev/inc/FileWriter.h

FORMS    += \
    design/mainwindow.ui
