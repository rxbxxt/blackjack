#include "GameSceneManager.h"

GameSceneManager::~GameSceneManager() {
    delete _button_deal.data();
    delete _button_hit.data();
    delete _button_stand.data();
    delete _deal_text;
    delete _balance_text;
    delete _playerscore_text;
    delete _dealerscore_text;
}

void GameSceneManager::clearDealScene() {
    removeDealItems();
    _scene->removeItem(_balance_text);
    delete _deal_text;
    delete _balance_text;
    delete _playerscore_text;
    delete _dealerscore_text;
    _deal_text = nullptr;
    _balance_text = nullptr;
    _playerscore_text = nullptr;
    _dealerscore_text = nullptr;
}

void GameSceneManager::removeDealItems() {
    _scene->removeItem(_button_deal.get());
    for (auto &chip : _chips) {
        _scene->removeItem(chip);
    }
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
    removeDealItems();
    initHitStandScene();
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
    _scene            = scene;
    _bet_sum          = 0;
    _button_deal      = nullptr;
    _deal_text        = nullptr;
    _balance_text     = nullptr;
    _playerscore_text = nullptr;
    _dealerscore_text = nullptr;
    _resolution_x     = resolution_x;
    _resolution_y     = resolution_y;
    _dealer           = std::make_unique<Dealer>();
    _player           = std::make_unique<Player>();
    _font             = std::make_unique<QFont>();

    _chips.reserve(6);
    _font->setPointSize(FONT_SIZE);
    initDealSceneButtons();
    initHitStandSceneButtons();
    initDealSceneChips();
}

void GameSceneManager::start() {
    _bet_sum = 0;
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
        _chips.push_back(chip);

        connect(_chips.back(), &Chip::clicked, this, [=](){
            emit bet(chip_value);
        });

        ++x;
    }
}

void GameSceneManager::initButton(QPointer<Button> &button,
                    const char *button_text,
                    int button_y, int button_x) {
    button = new Button(button_text);
    if (button_x == -1) {
        button_x = _resolution_x / 2.0f - button->boundingRect().width() / 2.0f;
    }
    button->setPos(button_x, button_y);
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

void GameSceneManager::initHitStandScene() {
    for (int i = 0; i < 2; ++i) {
        dealCards(i);
    }
    addHitStandSceneItems();
}

void GameSceneManager::dealCards(int cardnum) {
    auto playerpair = _dealer->getCard();
    dealCard(playerpair, *_player, cardnum, PLAYERCARD_Y);

    auto dealerpair = _dealer->getCard();
    dealCard(dealerpair, *_dealer, cardnum, DEALERCARD_Y);

    std::stringstream score_text;
    score_text << "Your score: " << _player->getHandScore();
    setMessage(&_playerscore_text, score_text.str().c_str(), SCORE_X, PLAYER_SCORE_Y);

    score_text.str("");
    score_text << "Dealer score: " << _dealer->getHandScore();
    setMessage(&_dealerscore_text, score_text.str().c_str(), SCORE_X, DEALER_SCORE_Y);
}

void GameSceneManager::dealCard(std::pair<QPixmap*, uint8_t> &card_to_value,
                                IBlackjackPlayer &blackjack_player,
                                int card_number,
                                int card_position_y) {
    auto card = card_to_value.first;
    auto cardvalue = card_to_value.second;
    drawCard(card, CARD_X + (card_number * card->width() / 2), card_position_y);
    blackjack_player.setHandScore(blackjack_player.getHandScore() + cardvalue);
}

void GameSceneManager::drawCard(QPixmap *card, int x, int y) {
    auto card_item = _scene->addPixmap(*card); 
    card_item->setPos(x, y);
}

void GameSceneManager::initHitStandSceneButtons() {
    initButton(_button_hit, "Hit", BUTTON_HIT_Y, BUTTON_STAND_HIT_X);
    initButton(_button_stand, "Stand", BUTTON_STAND_Y, BUTTON_STAND_HIT_X);
    connect(_button_hit.get(), SIGNAL(clicked()), this, SLOT(hit()));
    connect(_button_stand.get(), SIGNAL(clicked()), this, SLOT(stand()));
}

void GameSceneManager::addHitStandSceneItems() {
    _scene->addItem(_button_hit.get());
    _scene->addItem(_button_stand.get());
}

void GameSceneManager::stand() {
}

void GameSceneManager::hit() {
}
