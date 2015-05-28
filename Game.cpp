#include "Game.h"
#include "Wall.h"
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
    player = new Player(16,12);
    scene->addItem(player);

    // create teleport
    teleport = new Teleport(4,4,8,4,3);
    scene->addItem(teleport);
    Teleport *teleport2 = new Teleport(8,8,4,8,1);
    scene->addItem(teleport2);

    // add a wall
    Wall *wall = new Wall(2,2);
    scene->addItem(wall);

    // create debug overlay
    debug = new Debug();
    scene->addItem(debug);

    show();
}
