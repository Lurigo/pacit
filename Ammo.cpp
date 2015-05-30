#include "Ammo.h"
#include <QFont>

Ammo::Ammo(QGraphicsItem *parent)
{
    ammo = 3;

    // display text
    setPlainText(QString("A:") + QString::number(ammo));
    setDefaultTextColor(Qt::green);
    setFont(QFont("system",10));
    setPos(90,12);
}

void Ammo::incAmmo()
{
    ammo += 3;
    setPlainText(QString("A:") + QString::number(ammo));
}

void Ammo::decAmmo()
{
    ammo--;
    setPlainText(QString("A:") + QString::number(ammo));
}

int Ammo::getAmmo()
{
    return ammo;
}
