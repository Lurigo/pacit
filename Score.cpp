#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent)
{
    score = 0;

    // display text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::gray);
    setFont(QFont("system",10));
    setPos(16,48);
}

void Score::incScore(int n)
{
    setPlainText(QString("Ammo: ") + QString::number(score));
    score += n;
}

