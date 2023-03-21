#include "card.h"

string Card::suit[] = {"No Suit", "Spades", "Hearts", "Diamonds", "Clubs"};
string Card::face[] = {"Joker", "Ace", "Two", "Three", "Four", "Five", "Six",  
                       "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	   
Card::Card() {} // constructor

Card::Card(int getFace, int getSuit){ // non-default constructor
	faceVal = getFace;
	suitVal = getSuit;
}

Card::~Card() {} // destructor

string Card::getSuit(){ // gets suit value
	return suit[suitVal];
}

string Card::getFace(){
	return face[faceVal];
}

string Card::print(){
	
	return face[faceVal] + " of " + suit[suitVal];
}

void Card::initialize(int faces, int suits){
	faceVal = faces;
	suitVal = suits;
}
