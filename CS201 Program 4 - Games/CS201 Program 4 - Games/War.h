#include "Deck.h"

void warMain();
void dealGameOfWar(vector<Card>& deck, vector<Card>& player, vector<Card>& comp);
//int coinFlip();
void playWar(vector<Card>& player, vector<Card>& comp);
void oneCardWar(vector<Card>& player, vector<Card>& comp);
void cardWar(vector<Card>& player, vector<Card>& comp, vector<Card>& holdHand);
void emptyHoldHand(vector<Card>& player, vector<Card>& holdHand);
bool playWarAgain();