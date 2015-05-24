#include "Player.h"
#include <QKeyEvent>
#include <QTimer>

Player::Player()
{
    dir = 2;
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        dir = 4;
    }
    else if (event->key() == Qt::Key_Right)
    {
        dir = 2;
    }
    else if (event->key() == Qt::Key_Up)
    {
        dir = 1;
    }
    else if (event->key() == Qt::Key_Down)
    {
        dir = 3;
    }
}

void Player::move()
{
    if (dir == 1) // Up
    {
        if (pos().y() > 0)
            setPos(x(),y()-10);
    }
    else if (dir == 2) // Right
    {
        if (pos().x() < 700)
            setPos(x()+10,y());
    }
    else if (dir == 3) // Down
    {
        if (pos().y() < 500)
            setPos(x(),y()+10);
    }
    else if (dir == 4) // Left
    {
        if (pos().x() > 0)
            setPos(x()-10,y());
    }
    else setPos(x(),y());
}
