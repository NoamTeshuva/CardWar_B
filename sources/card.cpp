#include "card.hpp"
using namespace ariel;
using namespace std;


Card::Card(){};
Card::Card(cardType type, cardNum num) {
    this-> type = type;
    this-> num = num;

}

cardType Card::getType()  {
    return type;
}

cardNum Card::getNum()  {
    return num;
}


string Card:: cardNumToString(cardNum num) {
    switch (num) {
        case TWO: return "TWO";
        case THREE: return "THREE";
        case FOUR: return "FOUR";
        case FIVE: return "FIVE";
        case SIX: return "SIX";
        case SEVEN: return "SEVEN";
        case EIGHT: return "EIGHT";
        case NINE: return "NINE";
        case TEN: return "TEN";
        case PRINCE: return "PRINCE";
        case QUEEN: return "QUEEN";
        case KING: return "KING";
        case ACE: return "ACE";
        case JOKERN: return "JOKERN";
        default: return "UNKNOWN";
    }
    }

    
string Card:: cardTypeToString(cardType type) {
    switch(type) {
        case CLUBS:
            return "Clubs";
        case DIAMONDS:
            return "Diamonds";
        case HEARTS:
            return "Hearts";
        case SPADES:
            return "Spades";
        case JOKER:
            return "Joker";
        default:
            return "Invalid Card Type";
    }
}



