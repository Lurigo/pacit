#include "Wall.h"
#include "Game.h"
#include "Bullet.h"

#include <typeinfo>
#include <QList>
#include <QTimer>

extern Game *game;

Wall::Wall(int x, int y, QGraphicsItem *parent)
{
    // Set wall size, position and colour
    setRect(0,0,game->BLOCK_SIZE,game->BLOCK_SIZE);
    setPos(x*game->BLOCK_SIZE,y*game->BLOCK_SIZE);
    setBrush(* new QBrush(Qt::gray));
}


