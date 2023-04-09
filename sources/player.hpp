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
public: 
    Player ();
    Player  (string nameP);
    string getName() const { return nameP; }
    std::stack<Card> originalStack;
    std::stack<Card> cardesTakenStack;

    
    // std::string name;
        int getNumOfWins();
        int getNumOfDraws();
        int stacksize();
        int cardesTaken();
        void setNumOfWins(int num);
        void setNumOfDraws(int num);
};

}

