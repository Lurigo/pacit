#ifndef BARRIER_H
#define BARRIER_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Barrier: public QGraphicsPixmapItem
{
public:
    Barrier(int x, int y, QGraphicsItem *parent=0);
};

#endif // BARRIER_H
