#include "Hangman.h"
#include "Program4.h"
#include "Blackjack.h"
#include "War.h"
#include "Craps.h"

string mainMenuChoice;


int main() {
	while (mainMenuChoice != "q" || mainMenuChoice != "Q") {
		cout << "\nGames List\n"
			 << "B - Blackjack\n"
			 << "C - Craps\n"
			 << "H - Hangman\n"
			 << "T - TicTacToe\n"
			 << "W - War\n"
			 << "Q - Quit\n"
			 << "What game would you like to play?\n";

		mainMenuChoice = "";
		cin >> mainMenuChoice;

		if (mainMenuChoice == "q" || mainMenuChoice == "Q") {
			return 0;
		}
		else if (mainMenuChoice == "b" || mainMenuChoice == "B") {
			blackjackMain();
			continue;
		}
		else if (mainMenuChoice == "c" || mainMenuChoice == "C") {
			crapsMain();
			continue;
		}
		else if (mainMenuChoice == "h" || mainMenuChoice == "H") {
			hangmanMain();
			continue;
		}
		else if (mainMenuChoice == "t" || mainMenuChoice == "T") {

		}
		else if (mainMenuChoice == "w" || mainMenuChoice == "W") {
			warMain();
			continue;
		}
		else {
			cout << "Please enter a single letter from the list provided.\n";
			continue;
		}
	}
	

	return 0;
}