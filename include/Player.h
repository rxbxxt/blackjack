#ifndef PLAYER_H
#define PLAYER_H

#include <QPixmap>
#include <vector>

#include "IBlackjackPlayer.h"

class Player : public IBlackjackPlayer {
public:
    Player();
    ~Player() override {}

    int getBalance();
    int getHandScore() override;

    void setBalance(int balance);
    void setHandScore(int score) override;

private:
    int _balance;
    int _hand_score;
};

#endif // PLAYER_H