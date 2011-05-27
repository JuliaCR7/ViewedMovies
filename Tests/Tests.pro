#-------------------------------------------------
#
# Project created by QtCreator 2011-05-27T21:51:39
#
#-------------------------------------------------

QT       += sql testlib

QT       -= gui

TARGET = tst_testfilmmodel
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_testfilmmodel.cpp \
    ../filmmodel.cpp \
    ../film.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../filmmodel.h \
    ../film.h
