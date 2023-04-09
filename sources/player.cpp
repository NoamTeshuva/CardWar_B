
#include "player.hpp"
#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>



using namespace ariel;


Player::Player() {
    originalStack = std::stack<Card>();
    cardesTakenStack = std::stack<Card>();
    this->nameP= "Noam";
    int numOfwins=0;
    int numOfDraws=0;
}

Player::Player(string nameP) {

    this->nameP = nameP;
    originalStack = std::stack<Card>();
    cardesTakenStack = std::stack<Card>();
    int numOfwins=0;
    int numOfDraws=0;
    int numOfGamesPlayed;
}

int Player::getNumOfWins() { return numOfWins;};    

int Player::getNumOfDraws() {  return numOfDraws;};

void Player::setNumOfWins(int num) { numOfWins = num; }

void Player::setNumOfDraws(int num) { numOfDraws = num; }

int Player::stacksize(){return originalStack.size();}

int Player::cardesTaken(){return cardesTakenStack.size();};