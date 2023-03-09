#ifndef BLACKJACKPLAYER_H 
#define BLACKJACKPLAYER_H 

class BlackjackPlayer {
public:
    BlackjackPlayer() { 
        _card_count = 0;
        _hand_score = 0;
    }

    int getHandScore()      { return _hand_score; }
    int getHandCardsCount() { return _card_count; }

    void setHandScore(int score)    { _hand_score = score; }
    void setHandCardsCount(int num) { _card_count = num;   }

    virtual ~BlackjackPlayer() = default;

private:
    int _card_count;
    int _hand_score;
};

#endif // BLACKJACKPLAYER_H 