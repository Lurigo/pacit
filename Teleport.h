#ifndef TELEPORT_H
#define TELEPORT_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QMediaPlayer>

class Teleport: public QObject, public QGraphicsRectItem
{       Q_OBJECT
public:
    Teleport(int x, int y, QGraphicsItem *parent=0);
public slots:
    void detect();
private:
    int destX;
    int destY;
    QMediaPlayer *tp;
};

#endif // TELEPORT_H
