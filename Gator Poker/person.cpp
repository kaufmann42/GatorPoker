#include <iostream>
#include <string>
#include "person.h"
#include "card.h"
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Graphics.h"

using namespace std;

Person::Person(string name, int money, bool ai)
{
	this->name = name;
	this->money = money;
	this->ai = ai;
	this->livePot = 0;



	/*
	*	This next portion of code assigns the type of player the AI will be.
	*	When you play poker, there will always be different types of people.
	*	Sometimes you will get the person who acts at random and has no idea what is going on,
	*	othertimes you will have someone who looks for specific patterns when playing,
	*	other people are so skilled, that they know strategies to win etc.
	*/


	if(ai)
	{
		//three different levels of AI
		//this chooses one and designates the AI type
		srand(time(NULL));
		aiType = rand() % 2;     //either going to be 0,1,2

	}

	else 
	{	
		ai = -1;
	}
}

int Person::getMoney()
{
	return money;
}

void Person::setMoney(int i)
{
	money = i;
}

void Person::addMoney(int i)
{
	money += i;
}

void Person::setRank(double i)
{
	ranking = i;
}

double Person::getRank()
{
	return ranking;
}

void Person::addCard(Card p, int pos)
{
	hand[pos] = p;
}

string Person::getName()
{
	return name;
}

void Person::showHand()
{
	g = new Graphics();

	Card tempCard1 = hand[0];
	Card tempCard2 = hand[1];
	
	g->printDoubleCard(tempCard1.toString(), tempCard2.toString());


}

Card Person::getCard(int pos)
{
	return hand[pos];
}


void Person::toString()
{

	cout << getName() << " has $" << getMoney() << " and has the following hand: ";
	showHand();

}

int Person::handCheck()
{
	return 0;
}

int Person::getLivePot() 
{
	
	return livePot;
}

void Person::setLivePot(int num)
{
	
	livePot = livePot + num; 
}

void Person::clearLivePot()
{
	
	livePot = 0;
}

void Person::showTable(int num)
{

	g = new Graphics();
	for (int i = 2; i < 2 + num; i++){

		g->printSingleCards(hand[i].toString());
		
	}
	cout << endl << endl;
}

int Person::aiDecision(int maxamount, int callAmount)
{
	
		
	//This AI is the inexperienced player who randomly plays the game of poker
	//We designed this to have a heavy weight of randomly choosing to call and raise over folding.


	int counter = 0;
	int num =0;
	
 	srand(time(NULL));
	num = rand() % 10 + 1;    //generates number between 1-10
	

	if(num >= 1 && num <= 5)
	{
		return -3;   //this means there is a 50% chance of calling
	}

	if(num >=6 && num <= 7)
	{
		return -2;  //there is a 20% chance of folding
	}

	if(num >= 8 && num <= 10)    //30% chance of raising
	{

		srand(time(NULL));
	
		int amount = (callAmount * 1.15) + 1; 

		if(amount > maxamount)
		{
			return maxamount;
		}

		return amount;
	}
    std::cout << "ERROR IN AI LOOK AT LINE 168" << endl;
	return -4;

}
bool Person::getAI() 
{
	return ai;
}




