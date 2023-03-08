#include "Dealer.h"
#include <iostream>
#include <sstream>
#include <random>

Dealer::Dealer() {
    _cards.reserve(53);
    _values.reserve(53);
    loadCards();
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
    QPixmap card_(cardfile);
    auto card = new QPixmap(card_.scaled(CARD_WIDTH, CARD_HEIGHT));
    _cards.push_back(card);

    if       (cardnum <= 10) { _values.push_back(cardnum); } // { 2, 3, .. 10 } & { 0 }
    else if  (cardnum < 14)  { _values.push_back(10); }      // { J, Q, K }
    else                     { _values.push_back(11); }      // { A }
}

QPixmap *Dealer::getRandomCard() {
    std::random_device dev;
    std::mt19937_64 rng(dev());
    std::uniform_int_distribution<size_t> rnd(0, _cards.size() - 1);

    auto card = _cards.begin();
    std::advance(card, rnd(rng));

    return *card;
}