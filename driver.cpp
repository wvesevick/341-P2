#include <iostream>
#include "standarddeck.h"


int main(){
    int numberTies = 0;
    int numberP1Wins = 0;
    int numberp2Wins = 0;
    int averageScoreP1 = 0;
    int averageScoreP2 = 0;
    int winningAverage = 0;
    int averageRemainingCards = 0;

	
    for(int i = 0; i < 100; i++){
    
		srand(time(0));
		StandardDeck *p1Deck = new StandardDeck();
		StandardDeck *p2Deck = new StandardDeck();
		StandardDeck *battleground = new StandardDeck();
	
		battleground->makeDeck();

		cout << battleground->getNumCards() << endl;
		cout << p1Deck->getNumCards() << endl;
		cout << p1Deck->getNumCards() << endl;
		
    battleground->shuffle();	
    
    for (int i = 0; i < battleground->getNumCards()/2; i++){
        Card deltCard1 = battleground->dealCard();
        p1Deck->addCard(deltCard1);
        Card deltCard2 = battleground->dealCard();
        p2Deck->addCard(deltCard2);
    }
    
    int whosTurn = 1;
    
    while ((!p1Deck->isEmpty() && !p2Deck->isEmpty())){
        if(whosTurn == 1){
            if(battleground->isEmpty()){
                Card deltCard1 = p1Deck->dealCard();
                battleground->addCard(deltCard1);
                whosTurn = 2;
            }
            else {
                Card currentBattleCard = battleground->getTopCard();
                Card deltCard1 = p1Deck->dealCard();
                
                    
                if (currentBattleCard.getFace() == deltCard1.getFace()){
                    battleground->addCard(deltCard1);
                    p1Deck->mergeDecks(battleground, false);
                    whosTurn = 1;
                    }
                else{
                    battleground->addCard(deltCard1);
                    whosTurn = 2;
                }
            }
            
        }
        else{
            if(battleground->isEmpty()){
                Card deltCard2 = p2Deck->dealCard();
                battleground->addCard(deltCard2);
                whosTurn = 1;
            }
            else {
                Card currentBattleCard = battleground->getTopCard();
                Card deltCard2 = p2Deck->dealCard();
                battleground->addCard(deltCard2);
                    if (currentBattleCard.getFace() == deltCard2.getFace()){
                        p2Deck->mergeDecks(battleground, false);
                    whosTurn = 2;
                    }
                else{
                    whosTurn = 1;
                    }
                }
            }
        }
		
    if (p1Deck->isEmpty() && p2Deck->getNumCards() ==1) {
        cout << "tie" << endl;
        numberTies++;
        
    }
    else{
        if(p1Deck->isEmpty() && !p2Deck->isEmpty()){
            cout << "Player 2 wins!" << endl;
            numberp2Wins++;
            winningAverage += p2Deck->getNumCards();
        }
        else{
            cout << "Player 1 wins!" << endl;
            numberP1Wins++;
            winningAverage += p1Deck->getNumCards();
        }
		
    }

        averageScoreP1 += p1Deck->getNumCards();
        averageScoreP2 += p2Deck->getNumCards();
        averageRemainingCards += battleground->getNumCards();
        
       
		
        battleground->mergeDecks(p1Deck, false);
        battleground->mergeDecks(p2Deck, false);
	

		delete p1Deck;
		delete p2Deck;
		delete battleground;
		
		
}

    
    cout << "Number of ties: " << numberTies << endl;
    cout << "Number of wins by Player 1: " << numberP1Wins << endl;
    cout << "Number of wins by Player 2: " << numberp2Wins << endl;
    cout << "Average Player 1 score: " << averageScoreP1 / 100 << endl;
    cout << "Average Player 2 score: " << averageScoreP2 / 100 << endl;
    cout << "Average remaining cards: " << averageRemainingCards / 100 << endl;
    cout << "Average winning score: " << winningAverage / 100 << endl;
    
    return 0;
}
