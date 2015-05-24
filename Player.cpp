#include "Player.h"
#include <QKeyEvent>
#include <QTimer>

/* Direction values:
 * -----------------
 *        ^ 1
 *        |
 *    4 <- -> 2
 *        |
 *        v 4
 \ * * * * * * * * */

Player::Player()
{
    dir = 0; // Initialise direction indicator

    setRect(0,0,50,50); // Set player object size
    setPos(400,300); // Set player start position
    setFlag(QGraphicsItem::ItemIsFocusable); // Make player focusable, for key events
    setFocus();

    QTimer *timer = new QTimer(); // Create and set up QTimer for momvement
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(25); // Set timer interval and start
}

void Player::keyPressEvent(QKeyEvent *event) // Checks for pressed keys
{
    if (event->key() == Qt::Key_Up)
    {
        dir = 1;
    }
    else if (event->key() == Qt::Key_Right)
    {
        dir = 2;
    }
    else if (event->key() == Qt::Key_Down)
    {
        dir = 3;
    }
    else if (event->key() == Qt::Key_Left)
    {
        dir = 4;
    }
}

void Player::move()
{
    if (dir == 1) // Up
    {
        if (pos().y() > 0)
            setPos(x(),y()-5);
    }
    else if (dir == 2) // Right
    {
        if (pos().x() < 750)
            setPos(x()+5,y());
    }
    else if (dir == 3) // Down
    {
        if (pos().y() < 550)
            setPos(x(),y()+5);
    }
    else if (dir == 4) // Left
    {
        if (pos().x() > 0)
            setPos(x()-5,y());
    }
    else setPos(x(),y());
}
