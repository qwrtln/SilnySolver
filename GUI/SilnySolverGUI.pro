#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T18:01:50
#
#-------------------------------------------------

QT       += core gui opengl

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
    ../Dev/src/CrazyCubeSolver.cpp \
    ../Dev/src/FileReader.cpp \
    ../Dev/src/FileWriter.cpp \
    ../Dev/src/CrazyCubePruner.cpp \
    ../Dev/src/CrazyCubeMapper.cpp \
    ../Dev/src/OuterCornersMapGenerator.cpp \
    ../Dev/src/MoveMapsGeneratorI.cpp \
    ../Dev/src/CrazyCubeMoveMapper.cpp \
    crazycubegl.cpp

HEADERS  += \
    inc/mainwindow.h \
    crazycubegl.h


FORMS    += \
    design/mainwindow.ui
