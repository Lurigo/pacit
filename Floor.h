#ifndef FLOOR_H
#define FLOOR_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Floor: public QGraphicsRectItem
{
public:
    Floor(int x, int y, QGraphicsItem *parent=0);
};

#endif // FLOOR_H
