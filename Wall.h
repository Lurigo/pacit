#ifndef WALL_H
#define WALL_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Wall: public QObject, public QGraphicsRectItem
{       Q_OBJECT
public:
    Wall(int x, int y, QGraphicsItem *parent=0);
public slots:
    void detect();
};

#endif // WALL_H
