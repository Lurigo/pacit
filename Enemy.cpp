#include "Enemy.h"
#include "Game.h"
#include "Player.h"
#include "QTimer"
//#include "SearchNode.h"

extern Game *game;

Enemy::Enemy(int x, int y, QGraphicsItem *parent)
{
    // Set enemy position and texture
    setPixmap(QPixmap(":/images/enemy.png"));
    setPos((x*game->BLOCK_SIZE),((y-1)*game->BLOCK_SIZE));
    ox = x;
    oy = y;

    // Create and set up QTimer for movement
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(game->PING*8); // Set timer interval and start
}

void Enemy::move()
{
    int curX = pos().x()/32;
    int curY = (pos().y()+32)/32;

    if (getPX() > curX)
    {
        if (game->MAP[curY][curX+1] != 1)
            setPos(x()+game->BLOCK_SIZE,y());
    }
    else if (getPY() > curY)
    {
        if (game->MAP[curY+1][curX] != 1)
            setPos(x(),y()+game->BLOCK_SIZE);
    }
    else {
        if (getPX() < curX)
        {
            if (game->MAP[curY][curX-1] != 1)
                setPos(x()-game->BLOCK_SIZE,y());
            else setPos(x()+game->BLOCK_SIZE,y());
        }
        else if (getPY() < curY)
        {
            if (game->MAP[curY-1][curX] != 1)
                setPos(x(),y()-game->BLOCK_SIZE);
            else setPos(x(),y()+game->BLOCK_SIZE);
        }
    }
    if ((getPX() == curX) && (getPY() == curY))
    {
        game->health->decHealth();
        setPos((ox*game->BLOCK_SIZE),((oy-1)*game->BLOCK_SIZE));
    }

}

void Enemy::NodeSetup()
{
//    for(int i = 0; i < game->MAPX; i++)
//    {
//        for (int j = 0; j < game->MAPY; j++)
//        {
//            SearchNode *node = new SearchNode();
//            node->cX = i;
//            node->cY = j;

//            if (game->MAP[j][i] == 1)
//            {
//                searchNodes[j][i].
//            } else {

//            }

//        }
//    }
}

int Enemy::getPX()
{
    return (game->player->getX()/32);
}

int Enemy::getPY()
{
    return (game->player->getY()+32)/32;
}


