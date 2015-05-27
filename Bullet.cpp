#include "Bullet.h"
#include "Player.h"
#include "Game.h"
#include <QTimer>
#include <QDebug>

extern Game *game; // External object

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    setRect(0,0,5,5);

    //connect
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(10);
    dir = game->player->getDir();
}

void Bullet::move()
{
    if (dir == 1) // Up
    {
        if (pos().y() > -5)
            setPos(x(),y()-5);
        else
        {
            scene()->removeItem(this);
            delete this;
            qDebug() << "Bullet deleted";
        }
    }
    else if (dir == 2) // Right
    {
        if (pos().x() < 1024)
            setPos(x()+5,y());
        else
        {
            scene()->removeItem(this);
            delete this;
            qDebug() << "Bullet deleted";
        }
    }
    else if (dir == 3) // Down
    {
        if (pos().y() < 768)
            setPos(x(),y()+5);
        else
        {
            scene()->removeItem(this);
            delete this;
            qDebug() << "Bullet deleted";
        }
    }
    else if (dir == 4) // Left
    {
        if (pos().x() > -5)
            setPos(x()-5,y());
        else
        {
            scene()->removeItem(this);
            delete this;
            qDebug() << "Bullet deleted";
        }
    }
}

