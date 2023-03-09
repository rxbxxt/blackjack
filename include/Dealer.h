#ifndef DEALER_H
#define DEALER_H

#include <QPixmap>
#include <vector>
#include <cstdint>
#include <sstream>
#include <random>
#include <algorithm>

#include "BlackjackPlayer.h"

#define UNKNOWN_CARD ":/card/unknown"

#define CARD_WIDTH   125
#define CARD_HEIGHT  181.5

class Dealer : public BlackjackPlayer {
public:
    Dealer(); 
    ~Dealer() override; 

    const std::pair<QPixmap*, uint8_t> &getCard();

private:
    std::vector <std::pair <QPixmap*, uint8_t>>  _cards_to_values;
    std::vector <std::pair<QPixmap*, uint8_t>>   _deck;

    void loadDeck();
    void loadCards();
    void loadCardsHelper(const char *cardfile, int cardnum);

    const std::pair<QPixmap*, uint8_t> &getUnknownCard() const { 
        return _cards_to_values.front(); 
    }
};

#endif // DEALER_H