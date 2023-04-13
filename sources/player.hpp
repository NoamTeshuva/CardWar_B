#pragma once
#include "card.hpp"
#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
using namespace std;


namespace ariel{
class Player  {
private:
    std::string nameP;
    int numOfWins=0;
    int numOfDraws=0;
    std::stack<Card> originalStack;
    bool playNow;
    int cardesWon=0 ;
public: 
    Player ();
    Player  (string nameP);
    string getName() const { return nameP; }
    int getNumOfWins();
    int getNumOfDraws();
    int stacksize();
    int cardesTaken();
    void setNumOfWins();
    void setNumOfDraws(int num);
    void pushCardToOriginalStack(const Card& card);
    Card popCardFromOriginalStack();
    Card getTop();
    //void pushCardToCardesTakenStack(const Card& card);
    bool originalStackEmpty();
    int cardesTakenSize();
    bool playsNow();
    void incTaken();
    void setPlay(bool YorN);
    void incTakenDraw();
    
};

}

