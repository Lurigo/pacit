#ifndef PICKUP_H
#define PICKUP_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Pickup: public QObject, public QGraphicsPixmapItem
{     Q_OBJECT
public:
    Pickup(int x, int y, QGraphicsItem *parent=0);
private slots:
    void check();
};

#endif // PICKUP_H
