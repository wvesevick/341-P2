#include "deck.h"

Deck::Deck(){ // Defualt constructor
    capacity = 52;  //sets the size of the deck
    deck = new Card[capacity]; //
    numCards = -1;
}

Deck::~Deck(){
    delete [] deck;
}

bool Deck::isEmpty(){
    if (numCards == 0){
        return true;
    }
	else{ 
		return false;
	}
}

int Deck::getNumCards(){
	return numCards;
}

Card Deck::displayCard(int countCard){
    Card tempCard = deck[countCard];
    return tempCard;
}

void Deck::printDeck(){
    int countCard = 0;
    for(int i = 0; i < numCards; i++){
        cout << deck[countCard].print() << endl;
        countCard++;
    }
}

// void Deck::makeDeck(){
//     int countCard = 0; //our spot in the array
//     for(int i = 1; i < 14; i++){
//         for(int j = 1; j < 5; j++){
//             Card newCard(i,j);
//             deck[countCard] = newCard;
//             countCard++;
//         }
//
//     }
//     numCards = 52;
// }


// Core functionality

bool Deck::addCard(Card newCard){
    if (numCards < 52){
		cout << getNumCards() << endl;
		cout << "seg faults after this" << endl;
        deck[numCards] = newCard;
        numCards++;
        return true;		
    }
    else {
        return false;
    }
}

Card Deck::dealCard(){
		Card tempCard = deck[numCards-1];
		numCards--;
        return tempCard;
}

void Deck::shuffle() {
    for(int i = 1; i < 4; i++){
        for(int j = 0; j < numCards; j++){
            int randomNum = rand() % 52;
            Card tempCard = deck[j];
            deck[j] = deck[randomNum];
            deck[randomNum] = tempCard;
            
        }
    }
}

bool Deck::mergeDecks(Deck * middleDeck, bool shouldShuffle){
    if (middleDeck->getNumCards() + this->getNumCards() >= 52){
        return false;
    }
    while(!middleDeck->isEmpty() && middleDeck->getNumCards() >= 0){
        Card tempCard = middleDeck->dealCard();
		cout << middleDeck->getNumCards() << endl;
        this->addCard(tempCard);      
	    }    
    if(shouldShuffle == true){
        this->shuffle();
    }
    return true;
}

Card Deck::getTopCard(){
	return deck[numCards-1];
}
