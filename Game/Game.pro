TEMPLATE = app
TARGET = NYSSE

QT += core gui widgets network multimedia

CONFIG += c++14

SOURCES += \
    basicprojectile.cpp \
    bonusitem.cpp \
    gamecity.cpp \
    gameoverdialog.cpp \
    gamestatistics.cpp \
    gamewindow.cpp \
    helpdialog.cpp \
    initgame.cpp \
    main.cc \
    mainmenudialog.cpp \
    player.cpp \
    settingsdialog.cpp \
    statistisdialog.cpp \
    tophighscores.cpp

win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

HEADERS += \
    basicprojectile.h \
    bonusitem.h \
    gamecity.h \
    gameoverdialog.h \
    gamestatistics.h \
    gamewindow.h \
    helpdialog.h \
    initgame.h \
    mainmenudialog.h \
    player.h \
    settingsdialog.h \
    statistisdialog.h \
    tophighscores.h

RESOURCES += \
    resources/res.qrc

FORMS += \
    gameoverdialog.ui \
    gamewindow.ui \
    helpdialog.ui \
    mainmenudialog.ui \
    settingsdialog.ui \
    statistisdialog.ui


