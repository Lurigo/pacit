#ifndef WALL_H
#define WALL_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Wall: public QGraphicsRectItem
{
public:
    Wall(int x, int y, QGraphicsItem *parent=0);
};

#endif // WALL_H
