#ifndef RIVER_H
#define RIVER_H
#include <string>
#include <vector>
#include "person.h"

using namespace std;

class River {

private:
	unsigned int n;
	int raiseNum;
	int playerNum;
	int smallBlind;
	int bigBlind;
	int bet;
	int oldBet;
	int pot;
	int aidecision;
	int moneyLost;
	double decision;
	bool gameStart;

public:
	River(vector<Person*>& players, vector<bool>& fold, int b, int p);
	int getBigBlind();
	int getPot();

};
#endif