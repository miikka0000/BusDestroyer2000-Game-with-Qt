TEMPLATE = subdirs

SUBDIRS += \
        CourseLib \
        Game \
        StudentSideTests

CourseLib.subdir = Course/CourseLib
Game.depends = CourseLib
