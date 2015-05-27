#include "Player.h"
#include "Debug.h"
#include "Game.h"
#include "Bullet.h"
#include <QKeyEvent>
#include <QTimer>

extern Game *game;

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

    setRect(0,0,game->PLAYER_SIZE,game->PLAYER_SIZE); // Set player object size

    // Set player start position
    setPos(((game->WINDOW_WIDTH+game->PLAYER_SIZE)/2),((game->WINDOW_HEIGHT+game->PLAYER_SIZE)/2));
    setFlag(QGraphicsItem::ItemIsFocusable); // Make player focusable, for key events
    setFocus();

    QTimer *timer = new QTimer(); // Create and set up QTimer for movement
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(30); // Set timer interval and start
}

void Player::keyPressEvent(QKeyEvent *event) // Checks for pressed keys
{
    if (event->key() == Qt::Key_Up)
        dir = 1;
    else if (event->key() == Qt::Key_Right)
        dir = 2;
    else if (event->key() == Qt::Key_Down)
        dir = 3;
    else if (event->key() == Qt::Key_Left)
        dir = 4;
    //else if (event->key() == Qt::Key_F2)
        //game->scene->addItem(game->debug);
    else if (event->key() == Qt::Key_Space)
    {
        Bullet *bullet = new Bullet();
        switch (dir)
        {
            case 0: bullet->setPos(x()+14,y()+14); break;
            case 1: bullet->setPos(x()+14,y()-4);  break;
            case 2: bullet->setPos(x()+32,y()+14); break;
            case 3: bullet->setPos(x()+14,y()+32); break;
            case 4: bullet->setPos(x()-4,y()+14);  break;
        }
        scene()->addItem(bullet);
    }
}

int Player::getDir()
{
    return dir;
}

void Player::move()
{
    if (dir == 1) // Up
    {
        if (pos().y() > 0)
        {
            setPos(x(),y()-game->STEP_SIZE);
            xpos = pos().x(); // sets x-coordinate for debug overlay
            ypos = pos().y(); // sets y-coordinate for debug overlay
        }
    }
    else if (dir == 2) // Right
    {
        if (pos().x() < (game->WINDOW_WIDTH-game->PLAYER_SIZE))
        {
            setPos(x()+game->STEP_SIZE,y());
            xpos = pos().x();
            ypos = pos().y();
        }
    }
    else if (dir == 3) // Down
    {
        if (pos().y() < (game->WINDOW_HEIGHT-game->PLAYER_SIZE))
        {
            setPos(x(),y()+game->STEP_SIZE);
            xpos = pos().x();
            ypos = pos().y();
        }
    }
    else if (dir == 4) // Left
    {
        if (pos().x() > 0)
        {
            setPos(x()-game->STEP_SIZE,y());
            xpos = pos().x();
            ypos = pos().y();
        }
    }
    else // Stationary
    {
        setPos(x(),y());
        xpos = pos().x();
        ypos = pos().y();
    }
    game->debug->updatePlayerCoordinates(xpos,ypos); // Sends updated coordinates to debug overlay
}
