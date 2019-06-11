#include "game.h"

Game::Game(QWidget * device)
{
    if(device != nullptr)
        scene = new QGraphicsScene(device);
    else
        scene = new QGraphicsScene(this);

    setScene(scene);
    house = new House();
    data  = new Database();
}
