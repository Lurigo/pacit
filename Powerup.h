#ifndef POWERUP_H
#define POWERUP_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Powerup: public QObject, public QGraphicsPixmapItem
{     Q_OBJECT
public:
    Powerup(int x, int y, QGraphicsItem *parent=0);
private slots:
    void check();
private:
    QMediaPlayer *collected;
};

#endif // POWERUP_H
