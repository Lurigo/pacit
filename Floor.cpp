#include "Floor.h"
#include "Game.h"

extern Game *game;

Floor::Floor(int x, int y, QGraphicsItem *parent)
{
    // Set floor size, position and colour
    setRect(0,0,game->BLOCK_SIZE,game->BLOCK_SIZE);
    setPos(x*game->BLOCK_SIZE,y*game->BLOCK_SIZE);
    setBrush(* new QBrush(Qt::lightGray));
}


