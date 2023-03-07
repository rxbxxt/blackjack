#ifndef PLAYER_H
#define PLAYER_H

#include <QPixmap>
#include <vector>

class Player {
public:
    Player();

private:
    int _balance;
    int _hand_score;
    std::vector <QPixmap*> _hand;
};

#endif // PLAYER_H