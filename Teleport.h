#ifndef TELEPORT_H
#define TELEPORT_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Teleport: public QObject, public QGraphicsRectItem
{       Q_OBJECT
public:
    Teleport(int x, int y, int destx, int desty, int dir, QGraphicsItem *parent=0);
public slots:
    void detect();
private:
    int destX;
    int destY;
    int Dir;
};

#endif // TELEPORT_H
