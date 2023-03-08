#include "GameSceneManager.h"

GameSceneManager::~GameSceneManager() {
    delete _button_deal.data();
    delete _deal_text;
    delete _balance_text;
}

void GameSceneManager::clearDealScene() {
    _scene->removeItem(_button_deal.get());
    for (auto &chip : _chips) {
        _scene->removeItem(chip);
    }
    _scene->removeItem(_deal_text);
    _scene->removeItem(_balance_text);
    delete _deal_text;
    delete _balance_text;
    _deal_text = nullptr;
    _balance_text = nullptr;
}

void GameSceneManager::deal() { 
    if (_bet_sum == 0) return;

    _scene->removeItem(_button_deal.get());
    for (auto &chip : _chips) {
        _scene->removeItem(chip);
    }
    _deal_text->setPos(BETTED_TEXT_X, BETTED_TEXT_Y);
    _player->setBalance(_player->getBalance() - _bet_sum);
    addPlayerBalance();
}

void GameSceneManager::bet(int sum) { 
    int player_balance = _player->getBalance();
    
    if (player_balance < _bet_sum + sum) return;

    _bet_sum += sum; 

    std::stringstream deal_text;
    deal_text << "Your bet: $" << _bet_sum;
    setMessage(&_deal_text, deal_text.str().c_str(), DEAL_TEXT_X, DEAL_TEXT_Y);
}

GameSceneManager::GameSceneManager(QGraphicsScene *scene, 
                                   int resolution_x, int resolution_y) {
    _resolution_x = resolution_x;
    _resolution_y = resolution_y;
    _dealer = std::make_unique<Dealer>();
    _player = std::make_unique<Player>();
    _font   = std::make_unique<QFont>();
    _font->setPointSize(FONT_SIZE);
    _scene = scene;
    _button_deal = nullptr;
    _deal_text = nullptr;
    _balance_text = nullptr;
    _bet_sum = 0;
    _chips.reserve(6);
    initDealSceneButtons();
    initDealSceneChips();
}

void GameSceneManager::start() {
    addDealSceneItems();
    addPlayerBalance(); 
}

void GameSceneManager::addDealSceneItems() {
    _scene->addItem(_button_deal.get());
    for (auto &chip : _chips) {
        _scene->addItem(chip);
    }
}

void GameSceneManager::initDealSceneButtons() {
    initButton(_button_deal, "Deal", 300);
    connect(_button_deal.get(), SIGNAL(clicked()), this, SLOT(deal()));
}

void GameSceneManager::initDealSceneChips() {
    int x = 0;
    for (int chip_value : {1, 5, 25, 50, 100, 500}) {
        auto chip = new Chip(chip_value);
        chip->setPos(FIRST_CHIP_X + x * CHIP_HOVER_DIAMETER, CHIPS_HEIGHT);
        connect(chip, &Chip::clicked, this, [=](){ 
            emit bet(chip_value);
        });
        _chips.push_back(chip);
        ++x;
    }
}

void GameSceneManager::initButton(QPointer<Button> &button,
                                  const char *button_text,
                                  const int button_height) {
    button = new Button(button_text);
    int button_width = _resolution_x / 2.0f - button->boundingRect().width() / 2.0f;
    button->setPos(button_width, button_height);
}

void GameSceneManager::addPlayerBalance() {
    std::stringstream balance_text;
    balance_text << "Balance: $" << _player->getBalance();
    setMessage(&_balance_text, balance_text.str().c_str(), BALANCE_TEXT_X, BALANCE_TEXT_Y);
}

void GameSceneManager::setMessage(QGraphicsTextItem **textitem,
                                  const char *textmessage,
                                  int x, int y) {
    if (*textitem != nullptr) {
        _scene->removeItem(*textitem);
        delete *textitem;
        *textitem = nullptr;
    }
    *textitem = _scene->addText(textmessage);
    (*textitem)->setFont(*_font);
    (*textitem)->setDefaultTextColor(Qt::white);
    (*textitem)->setPos(x, y);
}
