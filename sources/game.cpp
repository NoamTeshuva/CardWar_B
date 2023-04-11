#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace ariel;



int randomNumber() {
    srand(time(nullptr));
    return rand() % 52;
}


Card* createDeck(){
    Card* deck = new Card[52];
    int i = 0;
    for (int num = 0; num <= 13; num++) {
        for (int type = 0; type <= 3; type++) {
            deck[i++] = Card(static_cast<ariel::cardType>(type), static_cast<ariel::cardNum>(num));
        }
    }
    return deck;
}
Game :: Game (Player player1, Player player2 )
{
    this->player1=player1;
    this->player2=player2;
    this->counterTurns=0;

Card* gameDeck=createDeck();
for ( int i = 0 ; i<26; i++)
{
    int k= randomNumber(); 
        while (gameDeck[k].getNum()!=JOKERN&&gameDeck[k].getType()!=JOKER)
        {
        k= randomNumber();    
        }
    player1.pushCardToOriginalStack(gameDeck[k]);
    gameDeck[k]=Card(JOKER,JOKERN);
    
    int j= randomNumber(); 
        while (gameDeck[j].getNum()!=JOKERN&&gameDeck[j].getType()!=JOKER)
        {
        j= randomNumber();    
        }    
    player2.pushCardToOriginalStack(gameDeck[j]);
    gameDeck[j]=Card(JOKER,JOKERN);
    }
}




/*
variables
*/
static string lastTurnString;
static int numOfTurnsPlayed =0;


void Game::playTurn(){
numOfTurnsPlayed++;
/*
Check if the platyrs is the same player in that cas is an error and don ket it play.
*/
if(&player1==&player2)
{
    return;
}


/*
Regular turn
*/
// if (counterTurns==0)
// {
// Card* gameDeck=createDeck();
// for ( int i = 0 ; i<26; i++)
// {
//     int k= randomNumber(); 
//         while (gameDeck[k].getNum()!=JOKERN&&gameDeck[k].getType()!=JOKER)
//         {
//         k= randomNumber();    
//         }
//     player1.originalStack.push(gameDeck[k]);
//     gameDeck[k]=Card(JOKER,JOKERN);
    
//     int j= randomNumber(); 
//         while (gameDeck[j].getNum()!=JOKERN&&gameDeck[j].getType()!=JOKER)
//         {
//         j= randomNumber();    
//         }    
//     player2.originalStack.push(gameDeck[j]);
//     gameDeck[j]=Card(JOKER,JOKERN);
//     }
// }

/*
Regular turn
*/

    int drawDeck;
   // std::vector<Card> drawDeck;
    Card card1 = player1.getTop();
    player1.popCardFromOriginalStack();
    Card card2 = player2.getTop();
    player2.popCardFromOriginalStack();
    
    if (card1.getNum()!=ACE&&card2.getNum()!=TWO||card1.getNum()!=TWO&&card2.getNum()!=ACE)
    {
        if(card1.getNum()>card2.getNum())
        {
        lastTurnString=player1.getName() + "Played" + card1.cardNumToString(card1.getNum()) + " of"
        + card1.cardTypeToString(card1.getType()) + lastTurnString=player2.getName()
         + "played"+ card2.cardNumToString(card2.getNum()) + "of" 
         +  card2.cardTypeToString(card2.getType()) + "."+ player1.getName()+  "wins." ;
        player1.pushCardToCardesTakenStack(card1);
        player1.pushCardToCardesTakenStack(card2);
        player1.cardesWon++;
        }
        
        if(card1.getNum()<card2.getNum())
        {
            lastTurnString = player2.getName() + " played " + card2.cardNumToString(card2.getNum()) + " of " 
                + card2.cardTypeToString(card2.getType()) + ". " + player1.getName() + " played " 
                + card1.cardNumToString(card1.getNum()) + " of " + card1.cardTypeToString(card1.getType())
                + ". " + player2.getName() + " wins.";
        player2.pushCardToCardesTakenStack(card1);
        player2.pushCardToCardesTakenStack(card2);
        player2.cardesWon++;
        }

/*
Draw
*/
    while (card1.getNum() == card2.getNum()) {
           lastTurnString = player1.getName() + " played " + card1.cardNumToString(card1.getNum()) + " of "
        + card1.cardTypeToString(card1.getType()) + ", " + player2.getName() + " played " 
        + card2.cardNumToString(card2.getNum()) + " of " + card2.cardTypeToString(card2.getType()) 
        + ". Draw.";
        // drawDeck.push_back(card1);
        // drawDeck.push_back(card2);
        drawDeck++;
        drawDeck++;
        Card card3 = player1.getTop();
        Card card4 = player2.getTop();
//        drawDeck.push_back(card3);
  //      drawDeck.push_back(card4);
        if (player1.originalStackEmpty() || player2.originalStackEmpty()) {
            while (drawDeck!=0)
            {
            // Card card5 = drawDeck.back();
            // drawDeck.pop_back();
            // player1.pushCardToCardesTakenStack(card5);
            // Card card6 = drawDeck.back();
            // drawDeck.pop_back();
            // player2.pushCardToCardesTakenStack(card6);
            player1.cardesWon++;
            drawDeck--;
            player2.cardesWon++;
            drawDeck--;
            }
            break;
        }
       
        player1.popCardFromOriginalStack();
        player2.popCardFromOriginalStack();
        card1 = player1.getTop();
        card2 = player2.getTop();
            
        if (card1.getNum() > card2.getNum()) {
        lastTurnString= lastTurnString + player1.getName() + " played " + card1.cardNumToString(card1.getNum()) + " of "
        + card1.cardTypeToString(card1.getType()) + ", " + player2.getName() + " played " 
        + card2.cardNumToString(card2.getNum()) + " of " + card2.cardTypeToString(card2.getType()) 
        + ". " + player1.getName() + " wins.";
            while (drawDeck!=0) {
            // player1.pushCardToCardesTakenStack(card);
            player1.cardesWon++;
            }
        //drawDeck.clear();
            break;
            }
        
        if (card1.getNum() < card2.getNum()) {
        lastTurnString =lastTurnString +  player1.getName() + " played " + card1.cardNumToString(card1.getNum()) + " of "
        + card1.cardTypeToString(card1.getType()) + ", " + player2.getName() + " played " 
        + card2.cardNumToString(card2.getNum()) + " of " + card2.cardTypeToString(card2.getType()) 
        + ". " + player2.getName() + " wins.";
            while (drawDeck!=0) {
            //player2.pushCardToCardesTakenStack(card);
            player2.cardesWon++;
            }
            //drawDeck.clear();
            break;
        }
        if (card1.getNum() == card2.getNum())
        {
        //     for (const auto& card : drawDeck) {
        //     player1.pushCardToCardesTakenStack(card);
        //     player2.pushCardToCardesTakenStack(card);
        //     }
        //     drawDeck.clear();
        //     break;
            counterTurns++;
            continue;
        }
    counterTurns++;
    }
}

    /*
    The case which tyo is bigger than ace
    */
    if (card1.getNum()==ACE&&card2.getNum()==TWO||card1.getNum()==TWO&&card2.getNum()==ACE){
        if(card1.getNum()<card2.getNum())
        {
        player1.pushCardToCardesTakenStack(card1);
        player1.pushCardToCardesTakenStack(card2);
         }
        if(card1.getNum()>card2.getNum())
        {
        player2.pushCardToCardesTakenStack(card1);
        player2.pushCardToCardesTakenStack(card2);
        }
    }

if(counterTurns<26){
counterTurns++;
}
else{
    printStats();
    printWiner();
}


};



void Game::printLastTurn(){
std::cout << lastTurnString << std::endl;
};

void Game::playAll(){
while (player1.stacksize()>0)
{
playTurn();
}
};

void Game::printWiner(){
    if(player1.cardesTakenSize()>player2.cardesTakenSize())
    {
     std::cout << player1.getName() + "won" << std::endl;  
    }
    if(player1.cardesTakenSize()<player2.cardesTakenSize())
    {
     std::cout << player2.getName() + "won" << std::endl;  
    }
    if(player1.cardesTakenSize()==player2.cardesTakenSize())
    {
    std::cout << "there was a draw" << std::endl;  
    }
};


    void Game ::printStatsOfPlayer(Player& player){
    float winRate = (float)player.getNumOfWins() / (float)numOfTurnsPlayed;
    float drawRate = (float)player.getNumOfDraws() / (float)numOfTurnsPlayed;
    float lossRate = 1 - winRate - drawRate;
    cout << "Player " << player.getName() << " Statistics:" << endl;
    cout << "Win Rate: " << winRate * 100 << "%" << endl;
    cout << "Loss Rate: " << lossRate * 100 << "%" << endl;
    cout << "Draw Rate: " << drawRate * 100 << "%" << endl;
    cout << "Total Games Played: " << numOfTurnsPlayed << endl;
    cout << "Cards Won: " << player.cardesTakenSize() << endl;
};

void Game::printStats(){
    cout << "-------------------" << endl;
    printStatsOfPlayer(player1);
    cout << "-------------------" << endl;
    printStatsOfPlayer(player2);
    cout << "-------------------" << endl;
    cout << "Total Draws: " << player1.getNumOfDraws() << endl;

};


void Game::printLog(){



};

