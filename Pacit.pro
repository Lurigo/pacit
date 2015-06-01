#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T00:03:53
#
#-------------------------------------------------

QT       += core gui network \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pacman
TEMPLATE = app
RC_FILE = pacscii.rc
QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter

CONFIG += c++11

SOURCES += main.cpp\
    Game.cpp \
    Player.cpp \
    Debug.cpp \
    Bullet.cpp \
    Teleport.cpp \
    Wall.cpp \
    Floor.cpp \
    Enemy.cpp \
    Powerup.cpp \
    Ammo.cpp \
    Pickup.cpp \
    Score.cpp \
    Health.cpp \
    Barrier.cpp \
    P2score.cpp

HEADERS  += \
    Game.h \
    Player.h \
    Debug.h \
    Bullet.h \
    Teleport.h \
    Wall.h \
    Floor.h \
    Enemy.h \
    Powerup.h \
    Ammo.h \
    Pickup.h \
    Score.h \
    Health.h \
    Barrier.h \
    P2score.h

FORMS    +=

RESOURCES += \
    images.qrc \
    sounds.qrc
