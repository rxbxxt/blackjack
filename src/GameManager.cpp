#include "GameManager.h"

GameManager::GameManager(QGraphicsScene *scene) {
    _dealer = std::make_unique<Dealer>();
    _player = std::make_unique<Player>(); 
    _scene = scene;
}

void GameManager::printRandomCard() {
    //return _dealer->getRandomCard();
    auto card_item = _scene->addPixmap(*_dealer->getRandomCard());
    card_item->setPos(200, 200);
    
    //_scene->addPixmap(*card);
    //auto card_item = _scene->addPixmap(card);
    //card_item->setPos(200, 200);
}
