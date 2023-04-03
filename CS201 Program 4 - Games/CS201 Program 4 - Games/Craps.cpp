#include "Craps.h"

using namespace std;


void crapsMain() {
	cout << "WELCOME TO CRAPS!\n\n";
    float netWorth = 50.00;
    playCraps(netWorth);
}

void playCraps(float& netWorth) {
    int die1, die2, total, point, newtotal;
    bool crapsAgain;
    while (netWorth > 0) {
        float betAmount = 0;

        cout << "Your net worth is: $" << fixed << setprecision(2) << netWorth << ".  ";
        betAmount = getCrapsBet(netWorth);
        srand(time(0));
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
        total = die1 + die2;
        cout << "You Rolled : " << die1 << " + " << die2 << " = " << total << "\n\n";

        if (total == 7 || total == 11) {
            cout << "\t\tYOU WIN!\n\n";
            netWorth += betAmount;
            crapsAgain = playCrapsAgain();
            if (crapsAgain == false) {
                break;
            }
            else if (crapsAgain == true) {
                continue;
            }
        }

        if (total == 2 ||
            total == 3 ||
            total == 12) {
            cout << "\t\tYOU LOSE!\n\n";
            netWorth -= betAmount;
            if (netWorth < 1) {
                break;
            }
            crapsAgain = playCrapsAgain();
            if (crapsAgain == false) {
                break;
            }
            else if (crapsAgain == true) {
                continue;
            }
        }

        else {
            point = total;
            die1 = rand() % 6 + 1;
            die2 = rand() % 6 + 1;
            newtotal = die1 + die2;
            cout << "\t\tPoint is: " << point << endl;
            cout << "\t\tYou Rolled : " << die1 << " + " << die2 << " = " << newtotal << endl;
            while (newtotal != point &&
                newtotal != 7) {
                die1 = rand() % 6 + 1;
                die2 = rand() % 6 + 1;
                newtotal = die1 + die2;
                cout << "\t\tYou Rolled : " << die1 << " + " << die2 << " = " << newtotal << endl;
            }
            if (newtotal == 7) {
                cout << "\t\tYOU LOSE!\n\n";
                netWorth -= betAmount;
                if (netWorth < 1) {
                    break;
                }
                crapsAgain = playCrapsAgain();
                if (crapsAgain == false) {
                    break;
                }
                else if (crapsAgain == true) {
                    continue;
                }
            }
            else {
                cout << "\t\tYOU WIN!\n\n";
                netWorth += betAmount;
                crapsAgain = playCrapsAgain();
                if (crapsAgain == false) {
                    break;
                }
                else if (crapsAgain == true) {
                    continue;
                }
            }
        }
    }
    if (netWorth < 1) {
        cout << "\nSorry you do not have enough money to play. You will have to leave the table." << endl << endl;
    }
}

float getCrapsBet(const float& netWorth) {
    float bet;
    while (true) {
        try {
            cout << "Please enter your bet: ";
            cin >> bet;
            cout << endl;
            if (cin.fail()) {     // https://cplusplus.com/forum/beginner/26821/ Used in case invalid cin is used such as a string or char
                throw runtime_error("Not a number");
            }
            if (bet > netWorth) {
                cout << "You can not bet more money than you have. Net worth: $" << netWorth << endl << endl;
                continue;
            }
            else if (bet < 1) {
                cout << "What kind of craps game do you think this is? Minimum bet is $1" << endl << endl;
                continue;
            }
            }
        catch (runtime_error e) {
            cout << "You have entered an invalid bet. Please enter 1-" << netWorth << endl << endl;
            cin.clear();                                         // I wanted to try something different than stof/stoi when getting a string instead of float/int
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // https://cplusplus.com/forum/beginner/130915/
            continue;
        }
        return bet;
    }
}

bool playCrapsAgain() {
    while (true) {
        string crapsChoice;
        cout << "\nWould you like to play again? (Press Y or N): ";
        cin >> crapsChoice;
        cout << endl;
        if (crapsChoice == "Y" || crapsChoice == "y") {
            return true;
        }
        else if (crapsChoice == "N" || crapsChoice == "n") {
            return false;
        }
        else {
            cout << "\nPlease enter Y or N\n\n";
            continue;
        }
    }
}