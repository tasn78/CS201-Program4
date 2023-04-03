#include "Deck.h"
#include "War.h"
#include <random>
#include <vector>


void dealGameOfWar(vector<Card>& deck, vector<Card>& player, vector<Card>& comp) {
	for (int i = 0; i < deck.size(); ++i) {
		if (i % 2 == 0) {
			player.push_back(deck[i]);

		}
		else if (i % 2 == 1) {
			comp.push_back(deck[i]);
		}
	}
}

void warMain() {
	while (true) {
		vector<Card> warDeck;
		vector<Card> player, comp;
		cout << "\nWAR\n\n";
		CreateDeck(warDeck);
		shuffle(warDeck);
		dealGameOfWar(warDeck, player, comp);
		playWar(player, comp);
		bool warAgain = playWarAgain();
		if (warAgain == false) {
			break;
		}
		else if (warAgain == true) {
			warDeck.clear();
			player.clear();
			comp.clear();
			continue;
		}
		break;
	}
}

/*int coinFlip() {							Created to decide who goes first, but since computer is dealer it will draw to player first
	int headsOrTails;
	cout << "Tossing a coin to see who goes first..." << endl;
	headsOrTails = rand() % 2 + 1;
	if (headsOrTails == 1) {
		cout << "Heads! Player wins and will go first." << endl;
		return 1;
	}
	else {
		cout << "Tails! Computer wins and will go first." << endl;
		return 2;
	}
}
*/

void playWar(vector<Card>& player, vector<Card>& comp) {
	while (player.size() >= 10 || comp.size() >= 10) {
		cout << "\nPlayer: " << player.size() << " :" << endl;
		printDeck(player);
		cout << "\nComputer :" << comp.size() << " :" << endl;
		printDeck(comp);
		cout << endl;
		oneCardWar(player, comp);

		if (player.size() < 10) {
			cout << "The computer wins!" << endl;
			break;
		}
		else if (comp.size() < 10) {
			cout << "*** You win!! ***" << endl;
			break;
		}
	}

}

void oneCardWar(vector<Card>& player, vector<Card>& comp) {
	vector<Card> holdHand;
	Card playerCard, compCard;
	playerCard = drawCard(player);
	compCard = drawCard(comp);
	cout << "\tPlayer:\t" << playerCard.getStringSuit() << " "
		<< playerCard.getFace() << "  :  Computer: " <<
		compCard.getStringSuit() << " " << compCard.getFace() 
		<< endl << endl;

	if (playerCard.value == compCard.value) {
		holdHand.push_back(playerCard);
		holdHand.push_back(compCard);
		cardWar(player, comp, holdHand);
	}
	else if (playerCard.value > compCard.value) {
		player.push_back(playerCard);
		player.push_back(compCard);
	}
	else if (playerCard.value < compCard.value) {
		comp.push_back(playerCard);
		comp.push_back(compCard);
	}
}

void cardWar(vector<Card>& player, vector<Card>& comp, vector<Card>& holdHand) {
	Card playerCard, compCard;
	while (true) {
		for (int i = 0; i < 3; ++i) {
			playerCard = drawCard(player);
			compCard = drawCard(comp);
			holdHand.push_back(playerCard);
			holdHand.push_back(compCard);
		}
		cout << "Hold :" << endl;
		printDeck(holdHand);
		cout << "\nPlayer hand: " << player.size() << " :  Computer hand:" << comp.size() << " :  "
			" Hold Hand: " << holdHand.size() << endl;

		playerCard = drawCard(player);
		compCard = drawCard(comp);

		if (playerCard.value == compCard.value) {
			holdHand.push_back(playerCard);
			holdHand.push_back(compCard);
			continue;
		}
		else if (playerCard.value > compCard.value) {
			player.push_back(playerCard);
			player.push_back(compCard);
			emptyHoldHand(player, holdHand);
			break;
		}
		else if (playerCard.value < compCard.value) {
			comp.push_back(playerCard);
			comp.push_back(compCard);
			emptyHoldHand(comp, holdHand);
			break;
		}
	}
}

void emptyHoldHand(vector<Card>& player, vector<Card>& holdHand) {		// Inserts holdHand to player/computer hand
	player.insert(player.end(), holdHand.begin(), holdHand.end());		// https://stackoverflow.com/questions/2551775/appending-a-vector-to-a-vector
	holdHand.clear();
}

bool playWarAgain() {
	string warChoice;
	cout << "\nWould you like to play War again? (Press Y to continue): ";
	cin >> warChoice;
	if (warChoice == "Y" || warChoice == "y") {
		return true;
	}
	else {
		return false;
	}

}