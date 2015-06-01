#include "Pickup.h"
#include "Game.h"
#include "Player.h"
#include <QTimer>

extern Game *game;

Pickup::Pickup(int x, int y, QGraphicsItem *parent)
{
    setPos(x*game->BLOCK_SIZE,y*game->BLOCK_SIZE);
    setPixmap(QPixmap(":/images/pickup.png"));

    // Connect timer to detector function
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(check()));

    timer->start(game->PING*8);
}

void Pickup::check()
{
    if ((game->player->getX() == pos().x()) && (game->player->getY() == pos().y()))
    {
        game->playCollect();
        game->score->incScore(175);
        scene()->removeItem(this);
        delete this;
    }
}
