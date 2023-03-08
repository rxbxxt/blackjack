#ifndef DEALER_H
#define DEALER_H

#include <QPixmap>
#include <vector>
#include <cstdint>

#define UNKNOWN_CARD ":/card/unknown"

#define CARD_WIDTH   125
#define CARD_HEIGHT  181.5

class Dealer {
public:
    Dealer(); 
    ~Dealer(); 

    QPixmap *getRandomCard();

private:
    std::vector <QPixmap*>  _cards;
    std::vector <uint8_t>   _values;

    void loadCards();
    void loadCardsHelper(const char *cardfile, int cardnum);
};

#endif // DEALER_H