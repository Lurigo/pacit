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
    for (int i = 0; i < MAPX; i++)
    {
        for (int j = 0; j < MAPY; j++)
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
            }
            else if (MAP[j][i] == 4)
            {
                Teleport *teleport = new Teleport(i,j-1);
                scene->addItem(teleport);
            }
            else if (MAP[j][i] == 5)
            {
                Floor *floor = new Floor(i,j-1);
                scene->addItem(floor);
                Barrier *barrier = new Barrier(i,j-1);
                scene->addItem(barrier);
            } else {
                Floor *floor = new Floor(i,j-1);
                scene->addItem(floor);
            }
        }
    }

    // load pickup sound effect
    collected = new QMediaPlayer;
    collected->setMedia(QUrl("qrc:/sounds/pickup.wav"));

    // create ammo display
    ammo = new Ammo();
    scene->addItem(ammo);

    // create score display
    score = new Score();
    scene->addItem(score);

    // create health display
    health = new Health();
    scene->addItem(health);

    // create player
    player = new Player(15,18);
    scene->addItem(player);

    // create enemy entities
    Enemy *enemy1 = new Enemy(15,12);
    scene->addItem(enemy1);

    // create debug overlay
    debug = new Debug();
    //scene->addItem(debug);

    show();
}

void Game::playCollect()
{
    if (collected->state() == QMediaPlayer::PlayingState){
        collected->setPosition(0);
    }
    else if (collected->state() == QMediaPlayer::StoppedState){
        collected->play();
    }
}

