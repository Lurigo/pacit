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

Player::Player(int x, int y)
{
    dir = 0; // Initialise direction indicator

    // Set player position and texture
    setPixmap(QPixmap(":/images/player_right.png"));
    setPos((x*game->BLOCK_SIZE),(y*game->BLOCK_SIZE));

    // Make player focusable, for key events
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    // Create and set up QTimer for movement
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(game->PING); // Set timer interval and start
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

void Player::updateDir(int d)
{
    dir = d;
}

void Player::move()
{
    if (dir == 1) // Up
    {
        setPixmap(QPixmap(":/images/player_up.png"));
        if (pos().y() > 0)
        {
            setPos(x(),y()-game->STEP_SIZE);
            xpos = pos().x(); // sets x-coordinate for debug overlay
            ypos = pos().y(); // sets y-coordinate for debug overlay
        }
    }
    else if (dir == 2) // Right
    {
        setPixmap(QPixmap(":/images/player_right.png"));
        if (pos().x() < (game->WINDOW_WIDTH-game->BLOCK_SIZE))
        {
            setPos(x()+game->STEP_SIZE,y());
            xpos = pos().x();
            ypos = pos().y();
        }
    }
    else if (dir == 3) // Down
    {
        setPixmap(QPixmap(":/images/player_down.png"));
        if (pos().y() < (game->WINDOW_HEIGHT-game->BLOCK_SIZE))
        {
            setPos(x(),y()+game->STEP_SIZE);
            xpos = pos().x();
            ypos = pos().y();
        }
    }
    else if (dir == 4) // Left
    {
        setPixmap(QPixmap(":/images/player_left.png"));
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
