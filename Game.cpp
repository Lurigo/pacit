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
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            if (MAP[j][i] == 1)
            {
                  Wall *wall = new Wall(i,j-1);
                  scene->addItem(wall);
            }
        }
    }

    // create player
    player = new Player(8,7);
    scene->addItem(player);

    // create debug overlay
    debug = new Debug();
    scene->addItem(debug);

    show();
}

