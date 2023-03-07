#include "Player.h"

Player::Player() {
    _hand.reserve(5);
    _hand_score = 0;
    _balance    = 1000;
}