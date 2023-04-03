#include "Deck.h"
#include "Blackjack.h"
#include <random>
#include <vector>



void startBlackjack(vector<Card>& deck, vector<Card>& player, vector<Card>& dealer) {
	Card newCard;
	newCard = drawCard(deck);
	player.push_back(newCard);
	newCard = drawCard(deck);
	dealer.push_back(newCard);
	newCard = drawCard(deck);
	player.push_back(newCard);
	newCard = drawCard(deck);
	dealer.push_back(newCard);
}


int addBlackjackHand(vector<Card>&hand) {
	int total = 0;
	for (int i = 0; i < hand.size(); ++i) {
		total += hand[i].getNumericalValue(hand[i]);
	}
	if (total > 21) {
		total = checkForAce(total, hand);
	}
	return total;
}

int checkForAce(int& total, vector<Card>& hand) {
	for (int i = 0; i < hand.size(); ++i) {
		if (hand[i].value == 14) {
			total -= 10;
			if (total <= 21) {
				return total;
			}
		}
	}
	return total;
}

void blackjackMain() {
	vector<Card> blackjackDeck;
	vector<Card> player, dealer;
	cout << "\nWELCOME TO BLACKJACK!\n\n";
	bool playBlackjackAgain;
	while (true) {
		clearTheBoard(blackjackDeck, player, dealer);
		int playerTotal = 0, dealerTotal = 0;

		CreateDeck(blackjackDeck);
		shuffle(blackjackDeck);
		startBlackjack(blackjackDeck, player, dealer);
		playerTotal = playerTurnBlackjack(blackjackDeck, player, playerTotal);
		if (playerTotal <= 21) {
			dealerTotal = dealerTurnBlackjack(blackjackDeck, dealer, dealerTotal);
			if (dealerTotal > 21) {
				cout << "\t\t******* DEALER BUSTS, PLAYER WINS!! *******\n";
			}
			else if (playerTotal == dealerTotal) {
				cout << "\t\t*** The game ended in a DRAW!! ***\n";
			}
			else if (dealerTotal > playerTotal) {
				cout << "***** PLAYER LOSES!! *****\n";
			}
			else if (playerTotal > dealerTotal) {
				cout << "***** PLAYER WINS!! *****\n";
			}
		}
		else if (playerTotal > 21) {
			cout << "\t\tOOPS = Player went over 21. COMPUTER WINS!!\n\n";
		}
		playBlackjackAgain = playBJAgain();
		if (playBlackjackAgain == false) {
			break;
		}
		else if (playBlackjackAgain == true) {
			continue;
		}
		break;
	}
}

int playerTurnBlackjack(vector<Card>& deck, vector<Card>& player, int& playerTotal) {
	while (true) {
		string playerInput;
		cout << "\nPlayer has the following cards:\n";
		printDeck(player);
		playerTotal = addBlackjackHand(player);
		cout << "\t\tTotal: " << playerTotal << endl << endl;
		if (playerTotal > 21) {
			return playerTotal;
		}
		else if (playerTotal == 21) {
			return playerTotal;
		}
		
		while (playerTotal < 21) {
			playerInput = "";
			cout << "\nWould you like to take another card? Y or N ";
			cin >> playerInput;

			if (playerInput == "Y" || playerInput == "y") {
				break;
			}
			else if (playerInput == "N" || playerInput == "n") {
				break;
			}
			else continue;
		}
		if (playerInput == "Y" || playerInput == "y") {
			Card newCard;
			newCard = drawCard(deck);
			player.push_back(newCard);
			continue;
		}
		else if (playerInput == "N" || playerInput == "n") {
			return playerTotal;
		}
	}
	return playerTotal;
}

int dealerTurnBlackjack(vector<Card>& deck, vector<Card>& dealer, int dealerTotal) {
	while (true) {
		cout << "\nComputer has the following cards:" << endl;
		printDeck(dealer);
		dealerTotal = addBlackjackHand(dealer);
		cout << "\t\tTotal: " << dealerTotal << endl << endl;
		if (dealerTotal == 21) {
			return dealerTotal;
		}
		else if (dealerTotal > 21) {
			return dealerTotal;
		}
		else if (dealerTotal > 17) {
			return dealerTotal;
		}
		else if (dealerTotal <= 17) {
			Card newCard;
			newCard = drawCard(deck);
			dealer.push_back(newCard);
			continue;
		}
		return dealerTotal;
	}
}

bool playBJAgain() {
	string BJchoice;
	cout << "\nWould you like to play again? (Press Y to continue): ";
	cin >> BJchoice;
	if (BJchoice == "Y" || BJchoice == "y") {
		return true;
	}
	else {
		return false;
	}

}

void clearTheBoard(vector<Card>& blackjackDeck, vector<Card>& player, vector<Card>& dealer) {
	blackjackDeck.clear();
	player.clear();
	dealer.clear();
}