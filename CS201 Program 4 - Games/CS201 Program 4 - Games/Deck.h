#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


struct Card {
	enum Suit {					// https://www.youtube.com/watch?v=JF6RDcXnVKI
		Hearts,
		Diamonds,				//https://www.youtube.com/watch?v=qR7LTxfvtd4
		Spades,					// CS201R SI
		Clubs,					// I used various sources to generate the deck and cards
	};							// Used enumerate, but realized that I don't know mapping,
	// so the best use of enumerate and printing the suit/value strings
	enum Value {				// was not used
		Two = 2,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,
		Ace
	};
	Card();
	Card(Suit suit, Value value);

	int getNumericalValue(const Card& card);
	Suit getSuit();
	Value getValue();
	void printCard(const Card& c);
	void printCard();
	string getStringSuit(const Card& c);
	string getStringSuit();
	string getFace(const Card& c);
	string getFace();


	Suit suit;
	Value value;
};


struct Deck {
	vector<Card> cards;
};

void CreateDeck(vector<Card>& deck);
void shuffle(vector<Card>& deck);
void printDeck(vector<Card>& deck);
Card drawCard(vector<Card>& deck);