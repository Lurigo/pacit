#ifndef POWERUP_H
#define POWERUP_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Powerup: public QObject, public QGraphicsPixmapItem
{     Q_OBJECT
public:
    Powerup(int x, int y, QGraphicsItem *parent=0);
private slots:
    void check();
};

#endif // POWERUP_H
