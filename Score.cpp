#include "Score.h"
#include "Game.h"
#include <QFont>

extern Game *game;

Score::Score(QGraphicsItem *parent)
{
    score = 0;

    // display text
    setPlainText(QString::number(score));
    setDefaultTextColor(Qt::gray);
    setFont(QFont("system",24));
    setPos(2,-2);
}

void Score::incScore(int n)
{
    score += n;
    setPlainText(QString::number(score));
    game->socket->writeDatagram(QString::number(score).toUtf8(),QHostAddress::Broadcast,8000);
}

int Score::getScore()
{
    return score;
}

