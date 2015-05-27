#include "Game.h"
#include <QKeyEvent>

Game::Game(QWidget *parent)
{
    // create and set up scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    // create player
    player = new Player();
    scene->addItem(player);

    debug = new Debug();
    scene->addItem(debug);

    show();
}
