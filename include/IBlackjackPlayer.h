#ifndef IBLACKJACKPLAYER_H 
#define IBLACKJACKPLAYER_H 

class IBlackjackPlayer {
public:
    virtual int getHandScore() = 0;
    virtual void setHandScore(int score) = 0;
    virtual ~IBlackjackPlayer() {}
};

//IBlackjackPlayer::~IBlackjackPlayer() {};

#endif // IBLACKJACKPLAYER_H 