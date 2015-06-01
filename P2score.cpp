#include "P2score.h"
#include <QFont>

P2Score::P2Score(QGraphicsItem *parent)
{
    // display text
    setPlainText(0);
    setDefaultTextColor(Qt::gray);
    setFont(QFont("system",24));
    setPos(900,-2);
}

//void P2Score::update(int n)
//{
//    setPlainText(QString::number(score));
//}

