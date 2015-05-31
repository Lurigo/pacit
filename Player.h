#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

class Player: public QObject, public QGraphicsPixmapItem
{       Q_OBJECT
public:
    Player(int x, int y);
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
    QMediaPlayer *bulletsound;
    QMediaPlayer *walking;
    QMediaPlayer *stuck;
    void playWalk();
    void playStuck();
};

#endif // PLAYER_H
