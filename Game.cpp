#include "Game.h"

Game::Game(QWidget *parent)
{
    // create and set up scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(WINDOW_WIDTH,WINDOW_HEIGHT);

    setWindowTitle("PACSCII alpha");

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
            else if (MAP[j][i] == 2)
            {
                Floor *floor = new Floor(i,j-1);
                scene->addItem(floor);
                Pickup *pickup = new Pickup(i,j-1);
                scene->addItem(pickup);
            }
            else if (MAP[j][i] == 3)
            {
                Floor *floor = new Floor(i,j-1);
                scene->addItem(floor);
                Powerup *powerup = new Powerup(i,j-1);
                scene->addItem(powerup);
            } else {
                Floor *floor = new Floor(i,j-1);
                scene->addItem(floor);
            }
        }
    }

    // create ammo display
    ammo = new Ammo();
    scene->addItem(ammo);

    // create score display
    score = new Score();
    scene->addItem(score);

    // create player
    player = new Player(8,7);
    scene->addItem(player);

    // create enemy entities
    Enemy *enemy1 = new Enemy(7,5);
    scene->addItem(enemy1);

    // create debug overlay
    debug = new Debug();
    scene->addItem(debug);

    show();
}

