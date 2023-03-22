#include "Hangman.h"
#include "Program4.h"
#include "Blackjack.h"

string mainMenuChoice;

int main() {
	while (mainMenuChoice != "q" || mainMenuChoice != "Q") {
		cout << "Games List\n"
			 << "B - Blackjack\n"
			 << "C - Craps\n"
			 << "H - Hangman\n"
			 << "T - TicTacToe\n"
			 << "W - War\n"
			 << "Q - Quit\n"
			 << "What game would you like to play?\n";

		cin >> mainMenuChoice;

		if (mainMenuChoice == "q" || mainMenuChoice == "Q") {
			exit;
		}
		else if (mainMenuChoice == "b" || mainMenuChoice == "B") {

		}
		else if (mainMenuChoice == "c" || mainMenuChoice == "C") {

		}
		else if (mainMenuChoice == "h" || mainMenuChoice == "H") {
			hangmanMain();
			continue;
		}
		else if (mainMenuChoice == "t" || mainMenuChoice == "T") {

		}
		else if (mainMenuChoice == "w" || mainMenuChoice == "W") {

		}
		else {
			cout << "Please enter a single letter from the list provided.\n";
			continue;
		}
	}
	

	return 0;
}