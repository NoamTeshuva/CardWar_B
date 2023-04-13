#include "game.hpp"
#include "player.hpp"
#include "card.hpp"
#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <bits/stdc++.h>
using namespace ariel;
using namespace std;


// took from gpt
void shuffle(Card deck[], size_t size)
{
    // Seed the random number generator
    std::srand(std::time(0));

    // Iterate through the deck from the last card to the first
    for (size_t i = size - 1; i > 0; --i)
    {
        // Generate a random index between 0 and i (inclusive)
        size_t j = static_cast<size_t>(std::rand()) % (i + 1);

        // Swap the cards at index i and j
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}


void splitDeck (Player& player1, Player& player2, Card deck[])
{
    for(int i=0; i<52 ; i++)
    {
        if(i<26){
        player1.pushCardToOriginalStack(deck[i]);
        }
        else
        player2.pushCardToOriginalStack(deck[i]);
    } 
}

Game::Game(Player& player1, Player& player2) : player1(player1), player2(player2)
{
    std::vector<std::string> logVector;
    Card gameDeck[52];
    if (player1.playsNow() || player2.playsNow())
    {
        throw string("in a middle of a game");
    }
    else{
    lastTurnString="";
    log="";
    drawInThisGame=0;
    counterTurns=0;
    player1.setPlay(true);
    player2.setPlay(true);
    int i = 0;
      for (size_t i = 0; i < 52; i++)
    {
        gameDeck[i] = Card((i % 4),(i % 13)) ;
    } 
    
    shuffle(gameDeck , 52);
    splitDeck(player1 , player2 , gameDeck);
    }


}
void Game::playTurn() {
    /*
    Check if the players are the same, in that case, it's an error and don't let them play.
    */
    if (&player1 == &player2) {
        throw runtime_error("Error: both players are the same.");
    }
    if (player1.stacksize() == 0)
    {
        throw "game is over";
    }
    
    // if (counterTurns == 26) {
    //     throw("Too many games.");
    // }

    int drawDeck = 0;
    Card card1 = player1.getTop();
    player1.popCardFromOriginalStack();
    Card card2 = player2.getTop();
    player2.popCardFromOriginalStack();

    
        /*
        Alice Wins
        */
    if (card1.compare(card2) > 0) {
            lastTurnString = player1.getName() + " Played " + card1.cardNumToString(card1.getNum()) + " of " +
                              card1.cardTypeToString(card1.getType()) + player2.getName() + " played " +
                              card2.cardNumToString(card2.getNum()) + " of " +
                              card2.cardTypeToString(card2.getType()) + "." + player1.getName() + " wins.\n";
            player1.incTaken();
            player1.setNumOfWins();

        }

        /*
        Bob win
        */

      else  if (card1.compare(card2) < 0) { 
            lastTurnString = player2.getName() + " played " + card2.cardNumToString(card2.getNum()) + " of " +
                              card2.cardTypeToString(card2.getType()) + ". " + player1.getName() + " played " +
                              card1.cardNumToString(card1.getNum()) + " of " +
                              card1.cardTypeToString(card1.getType()) + ". " + player2.getName() + " wins.\n";
            player2.incTaken();
            player2.setNumOfWins();
        }

        /*
        Draw
        */
        else  {
            while (card1.compare(card2) == 0 && player1.stacksize()>0) {
                drawInThisGame++;
                if (player1.stacksize()==1) {
                    player1.incTakenDraw();
                    player2.incTakenDraw();
                    
                    player1.popCardFromOriginalStack();
                    player2.popCardFromOriginalStack();
                   
                    player1.incTakenDraw();
                    player2.incTakenDraw();
                    break;
                }

                if (drawDeck == 0) {
                    drawDeck = 2;
                }

                lastTurnString = lastTurnString + player1.getName() + " played " +
                                  card1.cardNumToString(card1.getNum()) + " of " +
                                  card1.cardTypeToString(card1.getType()) + ", " + player2.getName() + " played " +
                                  card2.cardNumToString(card2.getNum()) + " of " +
                                  card2.cardTypeToString(card2.getType()) + ". Draw. \n";

                /*upside down card*/
        player1.popCardFromOriginalStack();
        player2.popCardFromOriginalStack();
        drawDeck++;
        drawDeck++;


        card1 = player1.getTop();
        card2 = player2.getTop();
        player1.popCardFromOriginalStack();
        player2.popCardFromOriginalStack();
        drawDeck++;
        drawDeck++;



        if (card1.compare(card2) > 0) {
        player1.setNumOfWins();
        while (drawDeck!=0) {
            player1.incTakenDraw();
            drawDeck--;
            }
        break;
        

        lastTurnString= lastTurnString + (player1.getName() + " played " + card1.cardNumToString(card1.getNum()) + " of "
        + card1.cardTypeToString(card1.getType()) + ", " + player2.getName() + " played " 
        + card2.cardNumToString(card2.getNum()) + " of " + card2.cardTypeToString(card2.getType()) 
        + ". " + player1.getName() + " wins.\n");
        }
        
        

       else if (card1.compare(card2) <0) {
        player2.setNumOfWins();
            while (drawDeck!=0) {
            player2.incTakenDraw();
            drawDeck--;
            }
        break;
        lastTurnString =lastTurnString + (player1.getName() + " played " + card1.cardNumToString(card1.getNum()) + " of "
        + card1.cardTypeToString(card1.getType()) + ", " + player2.getName() + " played " 
        + card2.cardNumToString(card2.getNum()) + " of " + card2.cardTypeToString(card2.getType()) 
        + ". " + player2.getName() + " wins.\n");
    }
    
    


        else  {
        Card card1 = player1.getTop();
        player1.popCardFromOriginalStack();
        
        Card card2 = player2.getTop();
        player2.popCardFromOriginalStack();
        
        drawDeck++;
        drawDeck++;
        }
    
    if(player1.stacksize()==0 && card1.compare(card2) ==0 ){
        while (drawDeck!=0)
        {
          player1.incTakenDraw();
          drawDeck--; 
        player2.incTakenDraw();
          drawDeck--;     
        }    
    }  
    }
 }
    if(counterTurns<27){
    counterTurns++;
    }
 log=log + "\n"+ lastTurnString;

};


void Game::printLastTurn(){
std::cout << lastTurnString << std::endl;
};

void Game::playAll(){
while ( player1.stacksize()>0)
{

playTurn();

}
};

//used gpt

void Game::printWiner(){
    
    player1.setPlay(false);
    player2.setPlay(false);
    
    if(player1.cardesTakenSize()>player2.cardesTakenSize())
    {
     std::cout << player1.getName() + " won" << std::endl;  
    }
    if(player1.cardesTakenSize()<player2.cardesTakenSize())
    {
     std::cout << player2.getName() + " won" << std::endl;  
    }
    if(player1.cardesTakenSize()==player2.cardesTakenSize())
    {
    std::cout << " there was a draw" << std::endl;  
    }

};

//used gpt

    void Game ::printStatsOfPlayer(Player& player){
    float winRate = (float)player.getNumOfWins() / (float)counterTurns;
    float drawRate = (float)drawInThisGame / (float)counterTurns;
    float lossRate = 1 - winRate - drawRate;
    cout << "Player " << player.getName() << " Statistics:" << endl;
    
    if(winRate!=0){
    cout << "Win Rate: " << winRate * 100 << "%" << endl;
    }
    if(winRate==0){
    cout << "Loss Rate: " << 0 << "%" << endl;
    }
    
    if(lossRate!=0){
    cout << "Loss Rate: " << lossRate * 100 << "%" << endl;
    }
    if(lossRate==0){
    cout << "Loss Rate: " << 0 << "%" << endl;
    }
    cout << "Draw Rate: " << drawRate * 100 << "%" << endl;
    cout << "Total Games Played: " << counterTurns << endl;
    cout << "Cards Won: " << player.cardesTakenSize() << endl;
};
//used gpt

void Game::printStats(){
    cout << "-------------------" << endl;
    printStatsOfPlayer(player1);
    cout << "-------------------" << endl;
    printStatsOfPlayer(player2);
    cout << "-------------------" << endl;
    cout << "Total Draws: " << drawInThisGame << endl;

};


void Game::printLog(){
cout << log << endl;
};

