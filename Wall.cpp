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

//    // Connect timer to detector function
//    QTimer *timer = new QTimer(this);
//    connect(timer,SIGNAL(timeout()),this,SLOT(detect()));

//    timer->start(game->BULLET_INTERVAL); // Set to detect at same rate as bullet to avoid clipping errors
}

void Wall::detect()
{
//    // Checks for any bullets colliding with the wall
//    QList<QGraphicsItem *> colliding_items = collidingItems();
//    for (int i = 0, n = colliding_items.size(); i < n; ++i)
//    {
//        // Deletes the bullet if detected
//        if ((typeid(*(colliding_items[i])) == typeid(Bullet)))
//        {
//            scene()->removeItem(colliding_items[i]);
//            delete colliding_items[i];
//            return;
//        }
//    }
}


