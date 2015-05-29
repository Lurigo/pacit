#include "Bullet.h"
#include "Player.h"
#include "Game.h"
#include <QTimer>
#include <QDebug>

extern Game *game; // External object

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    setRect(0,0,game->BULLET_SIZE,game->BULLET_SIZE);

    //connect
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(game->BULLET_INTERVAL);
    dir = game->player->getDir();
}

void Bullet::move()
{
    if (dir == 1) // Up
    {
        if (pos().y() > -game->BULLET_SIZE)
            setPos(x(),y()-game->STEP_SIZE);
        else
        {
            scene()->removeItem(this);
            delete this;
            qDebug() << "Bullet deleted";
        }
    }
    else if (dir == 2) // Right
    {
        if (pos().x() < game->WINDOW_WIDTH)
            setPos(x()+game->STEP_SIZE,y());
        else
        {
            scene()->removeItem(this);
            delete this;
            qDebug() << "Bullet deleted";
        }
    }
    else if (dir == 3) // Down
    {
        if (pos().y() < game->WINDOW_HEIGHT)
            setPos(x(),y()+game->STEP_SIZE);
        else
        {
            scene()->removeItem(this);
            delete this;
            qDebug() << "Bullet deleted";
        }
    }
    else if (dir == 4) // Left
    {
        if (pos().x() > -game->BULLET_SIZE)
            setPos(x()-game->STEP_SIZE,y());
        else
        {
            scene()->removeItem(this);
            delete this;
            qDebug() << "Bullet deleted";
        }
    }
}

