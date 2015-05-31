#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

#include "Player.h"
#include "Debug.h"
#include "Wall.h"
#include "Floor.h"
#include "Enemy.h"
#include "Powerup.h"
#include "Pickup.h"
#include "Ammo.h"
#include "Score.h"
#include "Health.h"
#include "Teleport.h"
#include "Barrier.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget *parent=0);

    QGraphicsScene *scene;
    Player *player;
    Debug *debug;
    Ammo *ammo;
    Score *score;
    Health *health;

    // Game-wide constants
    static const int WINDOW_WIDTH = 512;
    static const int WINDOW_HEIGHT = 384;
    static const int BLOCK_SIZE = 32;
    static const int BULLET_SIZE = 4;
    static const int BULLET_INTERVAL = 10;
    static const int STEP_SIZE = 4;
    static const int PING = 30;
    static const int MAPX = 16;
    static const int MAPY = 14;

    int MAP[MAPY][MAPX] = {
        {1,1,1,1,1,4,1,1,1,1,4,1,1,1,1,1,},
        {0,0,0,0,1,0,1,1,1,1,0,1,1,1,1,1,},
        {1,1,1,1,2,2,1,1,1,1,2,2,1,1,1,1,},
        {1,3,2,2,2,2,2,2,2,2,2,2,2,2,3,1,},
        {1,2,1,1,1,2,1,1,5,1,1,2,1,1,2,1,},
        {1,2,2,1,2,2,1,0,0,0,1,2,2,2,2,1,},
        {1,1,2,1,2,1,1,1,1,1,1,1,2,1,2,1,},
        {1,1,2,2,2,1,2,2,0,2,2,1,2,1,2,1,},
        {1,2,2,1,2,2,2,1,2,1,2,2,2,1,2,1,},
        {1,2,1,1,1,2,1,1,2,1,2,1,1,1,2,1,},
        {1,2,3,1,2,2,2,1,2,2,2,2,1,1,2,1,},
        {1,1,2,2,2,1,2,2,2,1,1,2,2,2,3,1,},
        {1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,},
        {1,1,1,4,1,1,1,1,1,1,1,1,4,1,1,1,}
    };

};

#endif // GAME_H
