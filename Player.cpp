#include "Player.h"
#include "Debug.h"
#include "Game.h"
#include "Bullet.h"
#include "Ammo.h"
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

    // load bullet sound effect
    bulletsound = new QMediaPlayer;
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.wav"));

    // load walking sound effect
    walking = new QMediaPlayer;
    walking->setMedia(QUrl("qrc:/sounds/walk.wav"));

    // load stuck sound effect
    stuck = new QMediaPlayer;
    stuck->setMedia(QUrl("qrc:/sounds/stuck.wav"));

    // load stuck sound effect
    dead = new QMediaPlayer;
    dead->setMedia(QUrl("qrc:/sounds/death.wav"));

    // Set player position and texture
    setPixmap(QPixmap(":/images/player_right.png"));
    setPos((x*game->BLOCK_SIZE),((y-1)*game->BLOCK_SIZE));

    // Make player focusable, for key events
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();

    // Create and set up QTimer for movement
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(game->PING*8); // Set timer interval and start
}

void Player::keyPressEvent(QKeyEvent *event) // Checks for pressed keys
{
    int curX = pos().x()/32;
    int curY = (pos().y()+32)/32;

    if (event->key() == Qt::Key_Up)
    {
        dir = 1;
        if (game->MAP[curY-1][curX] == 1) playStuck();
    }
    else if (event->key() == Qt::Key_Right)
    {
        dir = 2;
        if (game->MAP[curY][curX+1] == 1) playStuck();
    }
    else if (event->key() == Qt::Key_Down)
    {
        dir = 3;
        if (game->MAP[curY+1][curX] == 1) playStuck();
    }
    else if (event->key() == Qt::Key_Left)
    {
        dir = 4;
        if (game->MAP[curY][curX-1] == 1) playStuck();
    }
    else if (event->key() == Qt::Key_Space)
    {
        if (game->ammo->getAmmo() != 0)
        {
            Bullet *bullet = new Bullet();
            switch (dir)
            {
                case 0: bullet->setPos(x()+12,y()+12); break;
                case 1: bullet->setPos(x()+18,y()-8);  break;
                case 2: bullet->setPos(x()+32,y()+10); break;
                case 3: bullet->setPos(x()+8,y()+32); break;
                case 4: bullet->setPos(x(),y()+12);  break;
            }
            scene()->addItem(bullet);
            game->ammo->decAmmo();

            // play sound
            if (bulletsound->state() == QMediaPlayer::PlayingState){
                bulletsound->setPosition(0);
            }
            else if (bulletsound->state() == QMediaPlayer::StoppedState){
                bulletsound->play();
            }
        }
    }
}

int Player::getX()
{
    return xpos;
}

int Player::getY()
{
    return ypos;
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
    int curX = pos().x()/32;
    int curY = (pos().y()+32)/32;

    if (game->health->getHealth() == 0)
    {
        dead->play();
        setPos(-1*game->BLOCK_SIZE,-1*game->BLOCK_SIZE);
        scene()->removeItem(this);
        delete this;
    }

    if (dir == 1) // Up
    {
        setPixmap(QPixmap(":/images/player_up.png"));
        if ((game->MAP[curY-1][curX] != 1) && (game->MAP[curY-1][curX] != 5))
        {
            setPos(x(),y()-game->STEP_SIZE*8);
            xpos = pos().x(); // sets x-coordinate for debug overlay
            ypos = pos().y(); // sets y-coordinate for debug overlay
            playWalk();
        }
    }
    else if (dir == 2) // Right
    {
        setPixmap(QPixmap(":/images/player_right.png"));
        if ((game->MAP[curY][curX+1] != 1) && (game->MAP[curY][curX+1] != 5))
        {
            setPos(x()+game->STEP_SIZE*8,y());
            xpos = pos().x();
            ypos = pos().y();
            playWalk();
        }
    }
    else if (dir == 3) // Down
    {
        setPixmap(QPixmap(":/images/player_down.png"));
        if ((game->MAP[curY+1][curX] != 1) && (game->MAP[curY+1][curX] != 5))
        {
            setPos(x(),y()+game->STEP_SIZE*8);
            xpos = pos().x();
            ypos = pos().y();
            playWalk();
        }
    }
    else if (dir == 4) // Left
    {
        setPixmap(QPixmap(":/images/player_left.png"));
        if ((game->MAP[curY][curX-1] != 1) && (game->MAP[curY][curX-1] != 5))
        {
            setPos(x()-game->STEP_SIZE*8,y());
            xpos = pos().x();
            ypos = pos().y();
            playWalk();
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

void Player::playWalk() // play sound
{
    if (walking->state() == QMediaPlayer::PlayingState){
        walking->setPosition(0);
    }
    else if (walking->state() == QMediaPlayer::StoppedState){
        walking->play();
    }
}

void Player::playStuck() // play sound
{
    if (stuck->state() == QMediaPlayer::PlayingState){
        stuck->setPosition(0);
    }
    else if (stuck->state() == QMediaPlayer::StoppedState){
        stuck->play();
    }
}
