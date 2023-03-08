#include "Dealer.h"
#include <iostream>
#include <sstream>
#include <random>
#include <algorithm>

Dealer::Dealer() {
    _cards.reserve(53);
    _values.reserve(53);
    _deck.reserve(52);
    loadCards();
    loadDeck();
}

Dealer::~Dealer() {
    for (auto &card : _cards) {
        delete card;
    }
}

void Dealer::loadCards() {
    loadCardsHelper(UNKNOWN_CARD, 0);

    for (const auto &suit : {"clubs", "diamonds", "hearts", "spades"}) {
        for (int cardnum = 2; cardnum <= 14; ++cardnum) {
            std::stringstream ss;
            ss << ":/card/" << suit << "/" << cardnum;
            loadCardsHelper(ss.str().c_str(), cardnum);
        }
    }
}

void Dealer::loadCardsHelper(const char *cardfile, int cardnum) {
    auto card = new QPixmap(QPixmap(cardfile).scaled(CARD_WIDTH, CARD_HEIGHT));
    _cards.push_back(card);

    if       (cardnum <= 10) { _values.push_back(cardnum); } // { 2, 3, .. 10 } & { 0 }
    else if  (cardnum < 14)  { _values.push_back(10); }      // { J, Q, K }
    else                     { _values.push_back(11); }      // { A }
}

void Dealer::loadDeck() {
    _deck.clear();

    for (int i = 0; i < _deck.capacity(); ++i) {
        _deck.push_back(_cards[i+1]); // skip unknown card
    }

    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    
    std::shuffle(_deck.begin(), _deck.end(), rng);
}

QPixmap *Dealer::getCard() {
    auto card = _deck.back();
    _deck.pop_back();
    return card;
}
