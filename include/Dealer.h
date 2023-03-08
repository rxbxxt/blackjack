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

    QPixmap *getCard();

private:
    std::vector <QPixmap*>  _deck;
    std::vector <QPixmap*>  _cards;
    std::vector <uint8_t>   _values;

    void loadDeck();
    void loadCards();
    void loadCardsHelper(const char *cardfile, int cardnum);

    QPixmap *getUnknownCard() { return _cards.front(); }
};

#endif // DEALER_H