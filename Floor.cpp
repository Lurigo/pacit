#include "Floor.h"
#include "Game.h"

extern Game *game;

Floor::Floor(int x, int y, QGraphicsItem *parent)
{
    // Set floor position and texture
    setPos(x*game->BLOCK_SIZE,y*game->BLOCK_SIZE);
    setPixmap(QPixmap(":/images/floor.png"));
}


