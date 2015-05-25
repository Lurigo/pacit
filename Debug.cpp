#include "Debug.h"
#include "Player.h"
#include <QFont>

Debug::Debug(QGraphicsItem *parent)
{
    setPlainText(QString("Player coordinates: "));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("arial",12));
}

void Debug::updatePlayerCoordinates(int x, int y)
{
    setPlainText(QString("Player coordinates: ") + QString::number(x) + " ," + QString::number(y));
}



