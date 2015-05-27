#include "Game.h"
#include <QKeyEvent>

Game::Game(QWidget *parent)
{
    // create and set up scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);

    // create player
    player = new Player();
    scene->addItem(player);

    // create teleport
    teleport = new Teleport(256,128,256,512,1);
    scene->addItem(teleport);

    // create debug overlay
    debug = new Debug();
    scene->addItem(debug);

    show();
}
