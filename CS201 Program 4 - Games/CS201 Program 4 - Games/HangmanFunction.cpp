#include "Hangman.h"

void hangmanMain() {						// All code was written in class, CS201R. Changes were made to spacing and while loop
	srand(time(0));							// was added to ask if user wants to play again.

	char gchar;

	ifstream wordList;
	wordList.open("wordList.txt");	//opens the folder with the words
	if (!wordList.is_open()) {
		cout << "File did not open";
		exit(0);
	}

	vector<string> inputList;
	bool playHangman = true;
	while (playHangman = true) {
		int randomPick, guessesLeft = 6;
		string word = "", rword = "", gword = "";
		cout << "\nHANGMAN";
		while (wordList >> word) {
			inputList.push_back(word);
		}

		randomPick = rand() % (inputList.size());		//picks a random word
		rword = inputList[randomPick];

		for (int i = 0; i < rword[i]; i++) { //prints out the spaces left, needed to guess
			gword += "?";
		}
		cout << " - your word is: " << gword << endl;

		cout << "You have " << guessesLeft << " guesses. " << endl;

		while (rword != gword && guessesLeft > 0) {	//allows user to input character until out of guesses or victory
			cout << "Enter your guess: ";
			cin >> gchar;
			if (charFound(gchar, rword)) {
				for (int i = 0; rword[i]; i++) {
					if (gchar == rword[i]) {
						gword[i] = gchar;
					}

				}
				cout << "Nice guess! You have " << guessesLeft << " guesses left." << endl;
			}
			else {
				guessesLeft--;	// decreases guessesleft
				cout << "		Sorry that is incorrect. You have " << guessesLeft << " guesses left" << endl;
			}
			cout << "Your current word is :  " << gword << endl;

		}
		if (guessesLeft == 0) {
			cout << "			You Lose" << endl;
		}
		else {
			cout << "			You Win" << endl;
		}
		cout << "			The word was " << rword << endl;

		playHangman = playHangmanAgain();
		if (playHangman == true) {
			continue;
		}
		else if (playHangman ==  false) {
			wordList.close();
			break;
		}
	}

}

bool charFound(char guess, string random) {		//checks to see if guess letter is in random word string
	for (int i = 0; random[i]; i++) {
		if (guess == random[i]) {
			return true;
		}
	}
	return false;
}

bool playHangmanAgain() { // Asks user if they would like to play again, returns true only from y or Y. Any other option exits.
	string hangmanChoice;
	cout << "\nWould you like to play again? (Press Y to continue)\n";
	cin >> hangmanChoice;
	if (hangmanChoice == "y" || hangmanChoice == "Y") {
		return true;
	}
	else {
		return false;
	}

}