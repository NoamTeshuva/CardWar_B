#include "player.hpp"
#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;


using namespace ariel;


Player::Player() {
    originalStack = std::stack<Card>();
    this->nameP= "Noam";
    playNow =false;
    int numOfwins=0;
    int numOfDraws=0;
    int cardesWon=0;
}

Player::Player(string nameP) {

    this->nameP = nameP;
    originalStack = std::stack<Card>();
    int numOfwins=0;
    int numOfDraws=0;
    int numOfGamesPlayed;
    int cardesWon=0;
    playNow=false;
}
void Player :: pushCardToOriginalStack(const Card& card) {
        originalStack.push(card);
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
bool Player :: playsNow(){ return playNow;}
void Player :: setPlay( bool YorN){this->playNow=true; return;};
bool Player :: originalStackEmpty(){return originalStack.empty();};
int Player::getNumOfWins() { return numOfWins;};    
int Player::getNumOfDraws() {  return numOfDraws;};
void Player::setNumOfWins() { numOfWins++;return; }
void Player::setNumOfDraws(int num) { numOfDraws = num; }
int Player::stacksize(){return originalStack.size();}
int Player::cardesTaken(){return cardesWon;};
void Player:: incTaken(){ cardesWon=cardesWon+2; return;};
void Player:: incTakenDraw(){ cardesWon++; return;};

