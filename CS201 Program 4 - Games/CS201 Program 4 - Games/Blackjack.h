#pragma once

#include <string>
#include <iostream>
using namespace std;

enum class Suit {
	Hearts,
	Diamonds,
	Spades,
	Clubs,
};

enum class Value {
	Ace,
	Two,
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
};

class Card {
private:
	Suit suit;
	Value value;
	
public:
	Card(Suit suit, Value value);

	int getNumericalValue(bool totalExceeded);
	Suit getSuit();
	Value getValue();

	string get_representation();


};
