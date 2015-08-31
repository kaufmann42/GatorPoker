#ifndef PREFLOP_H
#define PREFLOP_H
#include <iostream>
#include <string>
#include <vector>
#include "person.h"

using namespace std;

class PreFlop {

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
	int money;
	int tempMoney;
	double decision;
	bool gameStart;

public:
	PreFlop(vector<Person*>& players, vector<bool>& fold);
	int getBigBlind();
	int getPot();

};
#endif
