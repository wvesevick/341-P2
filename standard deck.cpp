#include "standarddeck.h"

StandardDeck::StandardDeck(){ // Defualt constructor
    capacity = 52;  //sets the size of the deck
    deck = new Card[capacity]; //
    numCards = -1;
}

StandardDeck::~StandardDeck(){
    delete [] deck;
}

// bool StandardDeck::isEmpty(){
//     if (numCards == 0){
//         return true;
//     }
//     else {
//         return false;
//     }
// }
//
// int StandardDeck::getNumCards(){
// 	return numCards;
// }
//
// Card StandardDeck::displayCard(int countCard){
//     Card tempCard = deck[countCard];
//     return tempCard;
// }
//
// void StandardDeck::printDeck(){
//     int countCard = 0;
//     for(int i = 0; i < numCards; i++){
//         cout << deck[countCard].print() << endl;
//         countCard++;
//     }
// }

void StandardDeck::makeDeck(){
    int countCard = 0; //our spot in the array
    for(int i = 1; i < 14; i++){
        for(int j = 1; j < 5; j++){
            Card newCard(i,j);
            deck[countCard] = newCard;
            countCard++;
        }
        
    }
    numCards = 52;
}


// Core functionality
//
// bool StandardDeck::addCard(Card newCard){
//     if (numCards < 52){
//         deck[numCards] = newCard;
//         numCards++;
//         return true;
//     }
//     else {
//         return false;
//     }
// }
//
// Card StandardDeck::dealCard(){
//         Card tempCard = deck[numCards-1];
//         numCards--;
//         return tempCard;
// }
//
// void StandardDeck::shuffle() {
//     for(int i = 1; i < 4; i++){
//         for(int j = 0; j < numCards; j++){
//             int randomNum = rand() % 52;
//             Card tempCard = deck[j];
//             deck[j] = deck[randomNum];
//             deck[randomNum] = tempCard;
//
//         }
//     }
// }
//
// bool StandardDeck::mergeDecks(StandardDeck * middleDeck, bool shouldShuffle){
//     if (middleDeck->getNumCards() + this->getNumCards() >= 52){
//         return false;
//     }
//     while(!middleDeck->isEmpty()){
//         Card tempCard = middleDeck->dealCard();
//         this->addCard(tempCard);
//     }
//     if(shouldShuffle == true){
//         this->shuffle();
//     }
//     return true;
// }
//
// Card StandardDeck::getTopCard(){
// 	return deck[numCards-1];
// }
//
//
