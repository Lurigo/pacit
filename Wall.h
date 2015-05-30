#ifndef WALL_H
#define WALL_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Wall: public QGraphicsPixmapItem
{
public:
    Wall(int x, int y, QGraphicsItem *parent=0);
};

#endif // WALL_H
