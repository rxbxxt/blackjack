#ifndef PLAYER_H
#define PLAYER_H

#include <QPixmap>
#include <vector>

class Player {
public:
    Player();

    const int &getBalance() const { return _balance; }
    void setBalance(int balance) { _balance = balance; }

private:
    int _balance;
    int _hand_score;
    std::vector <QPixmap*> _hand;
};

#endif // PLAYER_H