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
    ../Dev/inc/ \
    ../Dev/src/

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    ../Dev/src/CrazyCube.cpp \
    ../Dev/src/CrazyCubeAbstract.cpp \
    ../Dev/src/CrazyCubeMapper.cpp

HEADERS  += \
    inc/mainwindow.h \
    ../Dev/inc/CrazyCubeMapper.h


FORMS    += \
    design/mainwindow.ui
