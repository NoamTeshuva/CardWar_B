#pragma once

#include <random>

namespace ariel{

enum cardType {CLUBS,DIAMONDS,HEARTS,SPADES,JOKER};
enum cardNum {TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,
PRINCE,QUEEN,KING,ACE,JOKERN};

class Card {
    private:
    cardNum num;
    cardType type;
    bool isNull;
    public:
    Card();
    Card(cardType type, cardNum num);
    
    cardType getType();
    cardNum getNum();
    bool getIsNull() const { return isNull; }

    std::string cardNumToString(cardNum num);
std::string cardTypeToString(cardType type);

    
};

}
    

