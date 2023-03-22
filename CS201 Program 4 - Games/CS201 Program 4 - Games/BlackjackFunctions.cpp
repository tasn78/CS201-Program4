#include "Blackjack.h"

Card::Card(Suit suit, Value value) {
	this->suit = suit;
	this->value = value;
}

int Card::getNumericalValue(bool totalExceeded) {
	int temp = 0;
	switch (value) {
	case Value::Ace:
		if (totalExceeded) {
			return 1;
		}
		else {
			return 11;
		}
	case Value::Two:
		return 2;
	case Value::Three:
		return 3;
	case Value::Four:
		return 4;
	case Value::Five:
		return 5;
	case Value::Six:
		return 6;
	case Value::Seven:
		return 7;
	case Value::Eight:
		return 8;
	case Value::Nine:
		return 9;
	case Value::Ten:
	case Value::Jack:
	case Value::Queen:
	case Value::King:
		return 10;
	}
}

enum Suit Card::getSuit() {
	return suit;
}
enum Value Card::getValue() {
	return value;
}

string get_representation();