#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "card.h"

// StandardDeck simulates the functionality of a standard deck of 52 cards. (No jokers here!)
// The core functionality is given below, and some details might be missing.
// Bummer.
// In other words, you might have to modify this .h file!

class Deck {
	private: 
		Card *deck;								// pointer to record the location of the array of cards in memory
		int numCards;							// stores the number of cards currently in the deck
		int capacity; // the amount of cards that're in the deck

	public:
		// Class management
		Deck();
		virtual ~Deck();

		// get/set functions
		bool isEmpty();							// returns whether or not the deck is empty
		int getNumCards();						// returns the number of cards remaining in the deck
		Card displayCard(int i);				// displays the ith card of the deck
		void printDeck();						// print a nicely formatted list of the cards in deck order
		// void makeDeck();                   // generates cards in the deck

		// Core functionality
		virtual bool addCard(Card c);					// add c to the end of the deck if there is space, fail otherwise
		virtual Card dealCard();						// deal the top card (largest valid index) of the deck -- remove it from the deck, and return it
		virtual void shuffle();							// Shuffles the deck of cards by performing at least 3*numCards random swaps (random sort from 248!)
		virtual bool mergeDecks(Deck *, bool);	// add cards from input to this deck, then empty the input deck. bool for shuffle afterwards (default = false)
		virtual Card getTopCard();                      // reteurns the card on top of the deck
};

#endif
