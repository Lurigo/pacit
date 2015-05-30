#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T00:03:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pacman
TEMPLATE = app


SOURCES += main.cpp\
    Game.cpp \
    Player.cpp \
    Debug.cpp \
    Bullet.cpp \
    Teleport.cpp \
    Wall.cpp \
    Floor.cpp

HEADERS  += \
    Game.h \
    Player.h \
    Debug.h \
    Bullet.h \
    Teleport.h \
    Wall.h \
    Floor.h

FORMS    +=

RESOURCES += \
    images.qrc
