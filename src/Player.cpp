#include "Player.h"

Player::Player() {
    _hand_score = 0;
    _balance    = 1000;
}

int Player::getBalance() {
    return _balance;
}

void Player::setBalance(int balance) {
    _balance = balance;
}

void Player::setHandScore(int score) {
    _hand_score = score;
}

int Player::getHandScore() {
    return _hand_score;
}
