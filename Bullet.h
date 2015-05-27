#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsRectItem>

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent=0);

public slots:
    void move();

private:
    int dir;

};

#endif // BULLET_H
