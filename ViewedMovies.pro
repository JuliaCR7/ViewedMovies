#-------------------------------------------------
#
# Project created by QtCreator 2011-04-22T16:53:25
#
#-------------------------------------------------

QT       += core gui sql

TARGET = ViewedMovies
TEMPLATE = app


SOURCES += main.cpp\
        viewedmovies.cpp \
    addform.cpp \
    film.cpp \
    filmmodel.cpp \
    infoform.cpp

HEADERS  += viewedmovies.h \
    addform.h \
    film.h \
    filmmodel.h \
    infoform.h

FORMS    += viewedmovies.ui \
    addform.ui \
    infoform.ui

RESOURCES += \
    resources.qrc

RC_FILE = server.rc
