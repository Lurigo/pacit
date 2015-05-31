#ifndef PICKUP_H
#define PICKUP_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Pickup: public QObject, public QGraphicsPixmapItem
{     Q_OBJECT
public:
    Pickup(int x, int y, QGraphicsItem *parent=0);
private slots:
    void check();
private:
    QMediaPlayer *collected;
};

#endif // PICKUP_H
