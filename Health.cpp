#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent)
{
    health = 3;

    // display text
    setPlainText(QString("H:") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("system",8));
    setPos(90,0);
}

void Health::decHealth()
{
    health--;
    setPlainText(QString("H:") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}
