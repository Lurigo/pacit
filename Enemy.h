#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Enemy: public QObject, public QGraphicsPixmapItem
{   Q_OBJECT
public:
    Enemy(int x, int y, QGraphicsItem *parent=0);
private slots:
    void move();
private:
    void NodeSetup();
    int getPX();
    int getPY();
    int ox, oy;
};

#endif // ENEMY_H
