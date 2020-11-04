QT       += testlib

QT       -= gui

TARGET = tst_statisticstest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_statisticstest.cpp \
    ../Game/gamestatistics.cpp \
    ../Course/CourseLib/errors/gameerror.cc


HEADERS += \
     ../Game/gamestatistics.h \
     ../Course/CourseLib/errors/gameerror.hh

INCLUDEPATH += \
            ../Game/ ../Course/CourseLib/
DEPENDPATH += \
            ../Game/

