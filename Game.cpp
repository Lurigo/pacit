#include "Game.h"
#include "Teleport.h"
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

    // load map
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 24; j++)
        {
            if (MAP[j][i] == 1)
            {
                  Wall *wall = new Wall(i,j);
                  scene->addItem(wall);
            }
        }
    }

    // create player
    player = new Player(15,17);
    scene->addItem(player);

    // create teleports
    Teleport *teleport1 = new Teleport(9,-1,21,23,1,1);
    scene->addItem(teleport1);
    Teleport *teleport2 = new Teleport(10,-1,22,23,1,1);
    scene->addItem(teleport2);
    Teleport *teleport3 = new Teleport(9,7,2,18,2,2);
    scene->addItem(teleport3);
    Teleport *teleport4 = new Teleport(22,7,29,18,4,2);
    scene->addItem(teleport4);
    Teleport *teleport5 = new Teleport(9,24,21,0,3,3);
    scene->addItem(teleport5);
    Teleport *teleport6 = new Teleport(10,24,22,0,3,3);
    scene->addItem(teleport6);
    Teleport *teleport7 = new Teleport(21,-1,9,23,2,1);
    scene->addItem(teleport7);
    Teleport *teleport8 = new Teleport(22,-1,10,23,4,1);
    scene->addItem(teleport8);
    Teleport *teleport9 = new Teleport(22,24,10,0,3,3);
    scene->addItem(teleport9);
    Teleport *teleport10 = new Teleport(21,24,9,0,3,3);
    scene->addItem(teleport10);

    // create debug overlay
    debug = new Debug();
    scene->addItem(debug);

    show();
}

