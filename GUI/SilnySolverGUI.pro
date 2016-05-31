#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T18:01:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = SilnySolverGUI
TEMPLATE = app

INCLUDEPATH += \
    ../Dev/inc/

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    ../Dev/src/CrazyCube.cpp \
    ../Dev/src/CrazyCubeAbstract.cpp \
    ../Dev/src/CrazyCubeCache.cpp \
    ../Dev/src/CrazyCubeImproved.cpp \
    ../Dev/src/CrazyCubeSolver.cpp

HEADERS  += \
    inc/mainwindow.h


FORMS    += \
    design/mainwindow.ui
