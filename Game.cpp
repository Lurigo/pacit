#include "Game.h"

Game::Game(QWidget *parent)
{
    // create and set up scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create player
    player = new Player();
    scene->addItem(player);

    debug = new Debug();
    scene->addItem(debug);

    show();
}
