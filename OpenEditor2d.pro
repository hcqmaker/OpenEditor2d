#-------------------------------------------------
#
# Project created by QtCreator 2014-04-16T17:01:24
#
#-------------------------------------------------

QT       += core gui

TARGET = OpenEditor2d
TEMPLATE = app

SOURCES += main.cpp\
        openeditor2d.cpp \
    configini.cpp \
    imagepack.cpp \
    lua-5.2.3/lzio.c \
    lua-5.2.3/lvm.c \
    lua-5.2.3/lundump.c \
    lua-5.2.3/luac.c \
    lua-5.2.3/lua.c \
    lua-5.2.3/ltm.c \
    lua-5.2.3/ltablib.c \
    lua-5.2.3/ltable.c \
    lua-5.2.3/lstrlib.c \
    lua-5.2.3/lstring.c \
    lua-5.2.3/lstate.c \
    lua-5.2.3/lparser.c \
    lua-5.2.3/loslib.c \
    lua-5.2.3/lopcodes.c \
    lua-5.2.3/lobject.c \
    lua-5.2.3/loadlib.c \
    lua-5.2.3/lmem.c \
    lua-5.2.3/lmathlib.c \
    lua-5.2.3/llex.c \
    lua-5.2.3/liolib.c \
    lua-5.2.3/linit.c \
    lua-5.2.3/lgc.c \
    lua-5.2.3/lfunc.c \
    lua-5.2.3/ldump.c \
    lua-5.2.3/ldo.c \
    lua-5.2.3/ldebug.c \
    lua-5.2.3/ldblib.c \
    lua-5.2.3/lctype.c \
    lua-5.2.3/lcorolib.c \
    lua-5.2.3/lcode.c \
    lua-5.2.3/lbitlib.c \
    lua-5.2.3/lbaselib.c \
    lua-5.2.3/lauxlib.c \
    lua-5.2.3/lapi.c \
    scriptengine.cpp \
    datahelp.cpp \
    imagepackscene.cpp

HEADERS  += openeditor2d.h \
    configini.h \
    imagepack.h \
    lua-5.2.3/lzio.h \
    lua-5.2.3/lvm.h \
    lua-5.2.3/lundump.h \
    lua-5.2.3/lualib.h \
    lua-5.2.3/luaconf.h \
    lua-5.2.3/lua.hpp \
    lua-5.2.3/lua.h \
    lua-5.2.3/ltm.h \
    lua-5.2.3/ltable.h \
    lua-5.2.3/lstring.h \
    lua-5.2.3/lstate.h \
    lua-5.2.3/lparser.h \
    lua-5.2.3/lopcodes.h \
    lua-5.2.3/lobject.h \
    lua-5.2.3/lmem.h \
    lua-5.2.3/llimits.h \
    lua-5.2.3/llex.h \
    lua-5.2.3/lgc.h \
    lua-5.2.3/lfunc.h \
    lua-5.2.3/ldo.h \
    lua-5.2.3/ldebug.h \
    lua-5.2.3/lctype.h \
    lua-5.2.3/lcode.h \
    lua-5.2.3/lauxlib.h \
    lua-5.2.3/lapi.h \
    scriptengine.h \
    datahelp.h \
    imagepackscene.h

FORMS    += openeditor2d.ui \
    imagepack.ui \
    imagepackright.ui \
    imagepackleft.ui

RESOURCES += \
    OpenEditor.qrc
