#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>

using namespace std;

class Card	//prime object
{	 

	/*
	Suit hierarchy 

	Name		int
	
	Spade   =   0
	Heart	=	1
	Diamond =	2
	Club	=	3


	Value Hierarchy
	Ace		= 1
	Two 	= 2
	.......
	Jack	= 11
	Queen 	= 12
	King	= 13

	*/


	public:
		Card();
		Card(int val, int suit);	//sets the name, val, and suit of the card

		string	getName();						//returns the name of the card
		int getVal();							//returns the value of the card
		int getSuit(); 							//returns the suit of the card
		string toString();								
	
	private:

		string name;
		string tempName;
		int val;
		int suit;

};
#endif