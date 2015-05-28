#include "Wall.h"
#include "Game.h"

extern Game *game;

Wall::Wall(int x, int y, QGraphicsItem *parent)
{
    setRect(0,0,game->BLOCK_SIZE,game->BLOCK_SIZE);
    setPos(x*game->BLOCK_SIZE,y*game->BLOCK_SIZE);
    //game->scene->addItem(this);
}


