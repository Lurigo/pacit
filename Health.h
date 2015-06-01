#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem
{
public:
    Health(QGraphicsItem *parent=0);
    void decHealth();
    int getHealth();
private:
    int health;
};

#endif // HEALTH_H
