#include "Powerup.h"
#include "Game.h"
#include "Player.h"
#include "Ammo.h"
#include <QTimer>

extern Game *game;

Powerup::Powerup(int x, int y, QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPos(x*game->BLOCK_SIZE,y*game->BLOCK_SIZE);
    setPixmap(QPixmap(":/images/powerup.png"));

    // load sound effect
    collected = new QMediaPlayer;
    collected->setMedia(QUrl("qrc:/sounds/powerup.wav"));

    // Connect timer to detector function
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(check()));

    timer->start(game->PING*8);
}

void Powerup::check()
{
    if ((game->player->getX() == pos().x()) && (game->player->getY() == pos().y()))
    {
        collected->play();
        game->ammo->incAmmo();
        scene()->removeItem(this);
        delete this;
    }
}


