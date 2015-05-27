#include "Teleport.h"
#include "Game.h"
#include "Player.h"

#include <typeinfo>
#include <QList>
#include <QTimer>

extern Game *game;

Teleport::Teleport(int x, int y, int destx, int desty, int dir, QGraphicsItem *parent)
{
    setRect(0,0,game->BLOCK_SIZE,game->BLOCK_SIZE);
    setPos(x,y);

    //set destination coordinates and direction
    destX = destx;
    destY = desty;
    Dir = dir;

    //connect
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(detect()));

    timer->start(30);
}

void Teleport::detect()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if ((typeid(*(colliding_items[i])) == typeid(Player)))
        {
            game->player->setPos(destX,destY);
            game->player->updateDir(Dir);
            return;
        }
    }
}


