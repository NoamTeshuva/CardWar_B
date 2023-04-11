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
    std::stack<Card> cardesTakenStack;
public: 
    Player ();
    Player  (string nameP);
    string getName() const { return nameP; }
    int cardesWon=0 ;

    
    
    // std::string name;
        int getNumOfWins();
        int getNumOfDraws();
        int stacksize();
        int cardesTaken();
        void setNumOfWins(int num);
        void setNumOfDraws(int num);
        void pushCardToOriginalStack(const Card& card);
        Card popCardFromOriginalStack();
        Card getTop();
        void pushCardToCardesTakenStack(const Card& card);
        bool originalStackEmpty();
        int cardesTakenSize();
};

}

