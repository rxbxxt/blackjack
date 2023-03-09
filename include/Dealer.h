#ifndef DEALER_H
#define DEALER_H

#include <QPixmap>
#include <vector>
#include <cstdint>
#include <sstream>
#include <random>
#include <algorithm>

#include "IBlackjackPlayer.h"

#define UNKNOWN_CARD ":/card/unknown"

#define CARD_WIDTH   125
#define CARD_HEIGHT  181.5

class Dealer : public IBlackjackPlayer {
public:
    Dealer(); 
    ~Dealer() override; 

    const std::pair<QPixmap*, uint8_t> &getCard();

    void setHandScore(int score) override;
    int  getHandScore() override;

private:
    std::vector <std::pair <QPixmap*, uint8_t>>  _cards_to_values;
    std::vector <std::pair<QPixmap*, uint8_t>>   _deck;
    int _hand_score;

    void loadDeck();
    void loadCards();
    void loadCardsHelper(const char *cardfile, int cardnum);

    const std::pair<QPixmap*, uint8_t> &getUnknownCard() const { 
        return _cards_to_values.front(); 
    }
};

#endif // DEALER_H