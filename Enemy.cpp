#include "Enemy.h"
#include "Game.h"
#include "QTimer"

extern Game *game;

Enemy::Enemy(int x, int y, QGraphicsItem *parent)
{
    // Set enemy position and texture
    setPixmap(QPixmap(":/images/enemy.png"));
    setPos((x*game->BLOCK_SIZE),((y-1)*game->BLOCK_SIZE));

    // Create and set up QTimer for movement
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(game->PING*8); // Set timer interval and start
}

void Enemy::move()
{

}


