#ifndef AMMO_H
#define AMMO_H

#include <QGraphicsTextItem>

class Ammo: public QGraphicsTextItem
{
public:
    Ammo(QGraphicsItem *parent=0);

    void incAmmo();
    void decAmmo();
    int getAmmo();

private:
    int ammo;
};

#endif // AMMO_H
