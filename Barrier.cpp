#include "Barrier.h"
#include "Game.h"

extern Game *game;

Barrier::Barrier(int x, int y, QGraphicsItem *parent)
{
    // Set wall position and texture
    setPos(x*game->BLOCK_SIZE,y*game->BLOCK_SIZE);
    setPixmap(QPixmap(":/images/barrier.png"));
}

