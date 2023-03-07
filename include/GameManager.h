#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <memory>

#include "Dealer.h"
#include "Player.h"

class GameManager {
public:
    GameManager(QGraphicsScene *scene);

    void printRandomCard();

private:
    QGraphicsScene *_scene;

    std::unique_ptr <Dealer> _dealer;
    std::unique_ptr <Player> _player;
};

#endif // GAMEMANAGER_H