#pragma once

# include <iostream>

using namespace std;
namespace ariel{

enum cardType {CLUBS,DIAMONDS,HEARTS,SPADES};
enum cardNum {TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,
PRINCE,QUEEN,KING,ACE};

class Card {
    private:
    int num;
    int type;
    bool isNull;
    public:
    Card(int type =0,int n =0); 
    int getType();
    int getNum();
    bool getIsNull() const { return isNull; }
    int compare(Card& card2);

string cardNumToString(int num);
string cardTypeToString(int type);

    
};

}
    

