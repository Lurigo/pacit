#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>

class Player: public QObject, public QGraphicsRectItem
{       Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
private slots:
    void move();
private:
    int dir;
};

#endif // PLAYER_H
