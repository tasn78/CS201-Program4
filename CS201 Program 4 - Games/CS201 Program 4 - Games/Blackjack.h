#pragma once
#include "Deck.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void startBlackjack(vector<Card>& deck, vector<Card>& player, vector<Card>& dealer);
int checkForAce(int& total, vector<Card>& hand);
int addBlackjackHand(vector<Card>& hand);
void blackjackMain();
int playerTurnBlackjack(vector<Card>& deck, vector<Card>& player, int& playerTotal);
int dealerTurnBlackjack(vector<Card>& blackjackDeck, vector<Card>& dealer, int dealerTotal);
bool playBJAgain();
void clearTheBoard(vector<Card>& blackjackDeck, vector<Card>& player, vector<Card>& dealer);