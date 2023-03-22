#include "Hangman.h"

void hangmanMain() {
	srand(time(0));

	int randomPick, guessesLeft = 6;		//variables used
	string word, rword, gword;
	char gchar;

	ifstream wordList;
	wordList.open("wordList.txt");	//opens the folder with the words
	if (!wordList.is_open()) {
		cout << "File did not open";
		exit(0);
	}

	vector<string> inputList;
	while (wordList >> word) {
		inputList.push_back(word);
	}

	randomPick = rand() % (inputList.size());		//picks a random word
	rword = inputList[randomPick];

	cout << "you have " << guessesLeft << " guesses Left " << endl;
	for (int i = 0; i < rword[i]; i++) { //prints out the spaces left, needed to guess
		gword += "?";
	}
	cout << gword;

	while (rword != gword && guessesLeft > 0) {	//allows user to input character until out of guesses or victory
		cout << "	guess a Letter" << endl;
		cin >> gchar;
		if (charFound(gchar, rword)) {
			for (int i = 0; rword[i]; i++) {
				if (gchar == rword[i]) {
					gword[i] = gchar;
				}

			}
			cout << "Good Job" << endl;
		}
		else {
			guessesLeft--;
			cout << "		Wrong, you have " << guessesLeft << " guesses left" << endl;
		}
		cout << gword << endl;


	}
	if (guessesLeft == 0) {
		cout << "			You Lose" << endl;

	}
	else {
		cout << "			you WIn" << endl;
	}
	cout << "			The word was " << rword << endl;

	wordList.close();

}

bool charFound(char guess, string random) {		//checks to see if guess letter is in random word string
	for (int i = 0; random[i]; i++) {
		if (guess == random[i]) {
			return true;
		}
	}
	return false;
}