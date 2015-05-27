#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

#include "Player.h"
#include "Debug.h"
#include "Teleport.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget *parent=0);

    QGraphicsScene *scene;
    Player *player;
    Teleport *teleport;
    Debug *debug;

    // Game-wide constants
    static const int WINDOW_WIDTH = 1024;
    static const int WINDOW_HEIGHT = 768;
    static const int BLOCK_SIZE = 32;
    static const int BULLET_SIZE = 4;
    static const int STEP_SIZE = 4;

};

#endif // GAME_H
