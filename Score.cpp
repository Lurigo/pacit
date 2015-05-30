#include "Score.h"
#include <QFont>

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
}

