#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "card.h"
#include "Graphics.h"

class Person
{
public:
	Person(string name, int money, bool ai);
	int handCheck();		//returns handcode
	void setRank(double i);	//the winnercheck in the daaemon will set the ranking value 
	double getRank();			//returns the value of the 
	int getMoney(); 		//returns the amount of money this person has
	void setMoney(int i);
	void addMoney(int i);	//adds money to the current pot;
	void addCard(Card p, int pos);   //position 0 and 1 is the persons hand
	void showHand();
	void toString();
	string getName();
	bool getAI();
	Card getCard(int pos);  //returns card object at position pos
	void setLivePot(int num);
	void clearLivePot();
	int getLivePot();
	void showTable(int num);

	//ai functions

	int aiDecision(int maxamount, int callAmount);      //returns decision to either fold, call, or raise


private:
	string name;
	int money;
	bool in;		//still playing or not
	double ranking;
	int livePot;    //how much money the player has put into the pot
	bool ai;		//if this player is an AI
	Card hand[7];
	Graphics *g;

	int aiType;

};

#endif