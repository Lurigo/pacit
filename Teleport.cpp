#include "Teleport.h"
#include "Game.h"
#include "Player.h"

#include <typeinfo>
#include <QList>
#include <QTimer>

extern Game *game;

Teleport::Teleport(int x, int y, int destx, int desty, int dir, int shift, QGraphicsItem *parent)
{
    // Set teleporter size, position and colour
    setRect(0,0,game->BLOCK_SIZE,game->BLOCK_SIZE);
    switch (shift)
    {
        case 1: setPos(x*game->BLOCK_SIZE,y*game->BLOCK_SIZE-4); break;
        case 2: setPos(x*game->BLOCK_SIZE,y*game->BLOCK_SIZE);   break;
        case 3: setPos(x*game->BLOCK_SIZE,y*game->BLOCK_SIZE+4); break;
    }

    setBrush(* new QBrush(Qt::green));

    // Set destination coordinates and direction
    destX = destx;
    destY = desty;
    Dir = dir;

    // Connect timer to detector function
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(detect()));

    timer->start(game->PING);
}

void Teleport::detect()
{
    // Check if the player is present
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if ((typeid(*(colliding_items[i])) == typeid(Player)))
        {
            // Teleports the player to the indicated location
            game->player->setPos(destX*game->BLOCK_SIZE,destY*game->BLOCK_SIZE);
            game->player->updateDir(Dir);
            return;
        }
    }
}


