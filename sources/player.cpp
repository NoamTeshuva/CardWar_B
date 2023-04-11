
#include "player.hpp"
#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;


using namespace ariel;


Player::Player() {
    originalStack = std::stack<Card>();
    cardesTakenStack = std::stack<Card>();
    this->nameP= "Noam";
    int numOfwins=0;
    int numOfDraws=0;
    int cardesWon=0;
}

Player::Player(string nameP) {

    this->nameP = nameP;
    originalStack = std::stack<Card>();
    cardesTakenStack = std::stack<Card>();
    int numOfwins=0;
    int numOfDraws=0;
    int numOfGamesPlayed;
    int cardesWon=0;
}
void Player :: pushCardToOriginalStack(const Card& card) {
        originalStack.push(card);
    }
void Player :: pushCardToCardesTakenStack(const Card& card) {
        cardesTakenStack.push(card);
    }
Card Player :: popCardFromOriginalStack() {
        if (originalStack.empty()) {
            throw std::runtime_error("Original stack is empty");
        }
        Card card = originalStack.top();
        originalStack.pop();
        return card;
    }

 Card Player:: getTop() {
    if (originalStack.empty()) {
        return Card();
    } else {
        return originalStack.top();
    }
}   

int Player :: cardesTakenSize(){return cardesWon;};

bool Player :: originalStackEmpty(){return originalStack.empty();};
int Player::getNumOfWins() { return numOfWins;};    

int Player::getNumOfDraws() {  return numOfDraws;};

void Player::setNumOfWins(int num) { numOfWins = num; }

void Player::setNumOfDraws(int num) { numOfDraws = num; }

int Player::stacksize(){return originalStack.size();}

int Player::cardesTaken(){return cardesWon;};
