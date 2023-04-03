#include "Deck.h"
#include <random>
#include <vector>
using namespace std;


Card::Card() {
}

Card::Card(Suit suit, Value value) {
	this->suit = suit;
	this->value = value;
}

int Card::getNumericalValue(const Card& card) {
	if (card.value <= Ten) {
		return value;
	}
	else if (card.value == Jack) {
		return 10;
	}
	else if (card.value == Queen) {
		return 10;
	}
	else if (card.value == King) {
		return 10;
	}
	else if (card.value == Ace) {
		return 11;
	}
}


Card::Suit Card::getSuit() {
	return suit;
}

string Card::getStringSuit(const Card& c) {
	switch (c.suit) {
	case 0:
		return "Hearts";
	case 1:
		return "Diamonds";
	case 2:
		return "Spades";
	case 3:
		return "Clubs";
	}
}

string Card::getStringSuit() {
	switch (this->suit) {
	case 0:
		return "Hearts";
	case 1:
		return "Diamonds";
	case 2:
		return "Spades";
	case 3:
		return "Clubs";
	}
}


/*	case 0:
		return "\u2665";   unicode for use on replit, does not work on Visual Studio as is
	case 1:
		return "\u2666";
	case 2:
		return "\u2660";
	case 3:
		return "\u2663";
	}
}
*/



Card::Value Card::getValue() {
	return value;
}

string Card::getFace(const Card& c) {
	switch (c.value) {
	case 2:
		return "2";
	case 3:
		return "3";
	case 4:
		return "4";
	case 5:
		return "5";
	case 6:
		return "6";
	case 7:
		return "7";
	case 8:
		return "8";
	case 9:
		return "9";
	case 10:
		return "10";
	case 11:
		return "J";
	case 12:
		return "Q";
	case 13:
		return "K";
	case 14:
		return "A";
	}
}

string Card::getFace() {
	switch (this->value) {
	case 2:
		return "2";
	case 3:
		return "3";
	case 4:
		return "4";
	case 5:
		return "5";
	case 6:
		return "6";
	case 7:
		return "7";
	case 8:
		return "8";
	case 9:
		return "9";
	case 10:
		return "10";
	case 11:
		return "Jack";
	case 12:
		return "Queen";
	case 13:
		return "King";
	case 14:
		return "Ace";
	}
}

void shuffle(vector<Card>& deck) {	//CS201R SI
	random_device rd;
	auto rng = default_random_engine{ rd() }; // https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
	shuffle(begin(deck), end(deck), rng);
}

void CreateDeck(vector<Card>& deck) {
	Card card;
	for (int i = (int)Card::Suit::Hearts; i <= (int)Card::Suit::Clubs; i++) {
		for (int j = (int)Card::Value::Two; j <= (int)Card::Value::Ace; j++) {
			card.suit = (Card::Suit)i;
			card.value = (Card::Value)j;
			deck.push_back(card);
		}
	}
}

void Card::printCard(const Card& c) {
	cout << getFace(c) << " of " << getStringSuit(c) << endl;
}

void Card::printCard() {
	cout << this->getFace() << " of " << this->getStringSuit() << endl;
}

void printDeck(vector<Card>& deck) {
	for (int i = 0; i < deck.size(); ++i) {
		deck[i].printCard(deck[i]);
	}
}

Card drawCard(vector<Card>& deck) {
	Card drawnCard;
	drawnCard = deck[0];
	deck.erase(deck.begin());
	return drawnCard;
}