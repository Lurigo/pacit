#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsRectItem>

class Player: public QObject, public QGraphicsRectItem
{       Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
    int getX();
    int getY();
    int getDir();
    void updateDir(int d);

private slots:
    void move();

private:
    int dir;
    int xpos, ypos;
};

#endif // PLAYER_H
