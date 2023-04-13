#include "card.hpp"
using namespace ariel;
using namespace std;



Card::Card(int t,int n) {
this->num=n;
this->type=t;
}

int Card::getType()  {
    return (this->type);
}

int Card::getNum()  {
    return (this->num);
}


//took from gpt
int Card ::compare(Card& card2){
    int Diff = this->num - card2.getNum();
    if (Diff != 0)
    {
        if (Diff == 12)
        {
            Diff = -1;
        }
        else if (Diff == -12)
        {
            Diff = 1;
        }
        return Diff;
    }
    else
    {
        return 0;
    }
    
    
}


string Card:: cardNumToString(int num) {
    switch (num) {
        case 0: return "TWO";
        case 1: return "THREE";
        case 2: return "FOUR";
        case 3: return "FIVE";
        case 4: return "SIX";
        case 5: return "SEVEN";
        case 6: return "EIGHT";
        case 7: return "NINE";
        case 8: return "TEN";
        case 9: return "PRINCE";
        case 10: return "QUEEN";
        case 11: return "KING";
        case 12: return "ACE";
        default: return "UNKNOWN";
    }
    }

    
string Card:: cardTypeToString(int type) {
    switch(type) {
        case 0:
            return "Clubs";
        case 1:
            return "Diamonds";
        case 2:
            return "Hearts";
        case 3:
            return "Spades";
        default:
            return "Invalid Card Type";
    }
}



