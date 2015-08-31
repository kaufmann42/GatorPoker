#include <iostream>
#include <string>
#include "card.h"
using namespace std;


Card::Card()
{
	
}


Card::Card(int val, int suit)
{
	if (val == 1){ name = "Ace"; }
	if (val == 2){ name = "Deuce"; }
	if (val == 3){ name = "Three"; }
	if (val == 4){ name = "Four"; }
	if (val == 5){ name = "Five"; }
	if (val == 6){ name = "Six"; }
	if (val == 7){ name = "Seven"; }
	if (val == 8){ name = "Eight"; }
	if (val == 9){ name = "Nine"; }
	if (val == 10){ name = "Ten"; }
	if (val == 11){ name = "Jack"; }
	if (val == 12){ name = "Queen"; }
	if (val == 13){ name = "King"; }
	this->val = val;
	this->suit = suit;
}

string	Card::getName()
{
	return name;
}
int Card::getVal()
{
	return val;
}
int Card::getSuit()
{
	return suit;
}
string Card::toString()
{


	//string tempName = "";

	if (suit == 0 && val != 0)   
	/*
	we added val !=0 because if for whatever reason in a 
	deck/hand the position is null, this will prevent the 
	toString from printing "of Spades." Encountered this when
	testing  -NF
	*/
	{
		tempName = name.append(" of Spades");
	}
	if (suit == 1)
	{
		tempName = name.append(" of Hearts");
	}

	if (suit == 2)
	{
		tempName = name.append(" of Clubs");
	}

	if (suit == 3)
	{
		tempName = name.append(" of Diamonds");
	}
	return tempName;
}
