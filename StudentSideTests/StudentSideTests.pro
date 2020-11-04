QT       += testlib

QT       -= gui

TARGET = tst_statisticstest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_statisticstest.cpp \
    ../Game/gamestatistics.cpp


HEADERS += \
     ../Game/gamestatistics.h

INCLUDEPATH += \
            ../Game/
DEPENDPATH += \
            ../Game/

