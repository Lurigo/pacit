#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

#include "Player.h"
#include "Debug.h"

class Game: public QGraphicsView
{
public:
    Game(QWidget *parent=0);

    QGraphicsScene *scene;
    Player *player;
    Debug *debug;

};

#endif // GAME_H
