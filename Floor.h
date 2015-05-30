#ifndef FLOOR_H
#define FLOOR_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Floor: public QGraphicsPixmapItem
{
public:
    Floor(int x, int y, QGraphicsItem *parent=0);
};

#endif // FLOOR_H
