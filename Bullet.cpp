#include "Bullet.h"
#include "Player.h"
#include "Game.h"
#include <QTimer>

extern Game *game; // External object

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set bullet texture
    setPixmap(QPixmap(":/images/bullet.png"));

    // create and connect timer to control movement
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(game->BULLET_INTERVAL*8);

    // get the player's direction to determine own movement direction
    dir = game->player->getDir();
}

void Bullet::move()
{
    int curX = pos().x()/32;
    int curY = (pos().y()+32)/32;

    if (dir == 1) // Up
    {
        if (game->MAP[curY-1][curX] != 1)
            setPos(x(),y()-game->STEP_SIZE*8);
        else
        {
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (dir == 2) // Right
    {
        if (game->MAP[curY][curX+1] != 1)
            setPos(x()+game->STEP_SIZE*8,y());
        else
        {
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (dir == 3) // Down
    {
        if (game->MAP[curY+1][curX] != 1)
            setPos(x(),y()+game->STEP_SIZE*8);
        else
        {
            scene()->removeItem(this);
            delete this;
        }
    }
    else if (dir == 4) // Left
    {
        if (game->MAP[curY][curX-1] != 1)
            setPos(x()-game->STEP_SIZE*8,y());
        else
        {
            scene()->removeItem(this);
            delete this;
        }
    }
}

