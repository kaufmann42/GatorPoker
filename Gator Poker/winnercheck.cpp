#include <iostream>
#include <string>
#include <float.h>
#include <vector>
#include <iomanip>
#include "person.h"

using namespace std;


class WinnerCheck
{



	/*		The Brainchild: "Thumb Print Values"


			8**         StraightFlush
			7**			Four of a Kind
			6**			Full House
			5**			Flush
			4**			Straight
			3**			Three of a Kind
			2**			Two Pair
			1**			One Pair
			 **			High Card


			The way this winner check works is it looks through the '7' ( 2 cards from the
			hand and the other 5 from the table) card hand of each player. It then assigns
			that hand a unique thumbprint number and pushes that to the player. This is the
			players rank. Whoever has the highest thumbprint value wins. The first digit of
			the three digit thumbprint states the type of hand they have, and the consecutive
			numbers represent the cards that form that hand. That way, each hand is unique and 
			the greatest thumbprint value wins. If the thumbprints are the same, then the players
			have a tie.



	*/

public:

static void winnercheck(vector<Person*>& players, int numberofplayers)
{

	for(int i = 0; i < numberofplayers; i ++)
	{

		players[i]->setRank(handval(*players[i]));
	}


}



static double handval(Person &player)
{



	int * playeronehandvals = new int[14];    

	/*
	Visual Representation of a Persons hand tallied up by value 

		 _____________________________________________________________
		|  A  |  2  | 3 | 4 | 5 | 6 | 7 | 8  |9 |10  |J  | Q | K | A  |  <---------- Value
		|_____|_____|___|___|___|___|___|____|__|____|___|___|___|____|
		|     |     |   |   |   |   |   |    |  |    |   |   |   |    |
		|_____|_____|___|___|___|___|___|____|__|____|___|___|__ |____|  <---------- Count

	*/




	//initializes it to zero
	for (int i = 0; i < 14; ++i)
	{
		playeronehandvals[i] = 0; 
	}

	//tallies up values
	for (int i = 0; i < 7; ++i)
	{
		playeronehandvals[player.getCard(i).getVal() -1 ]++;
	}

	playeronehandvals[13] = playeronehandvals[0];



/*
	Visual Representation of a Persons hand tallied up by suits 

		 ____________________
		|  S  |  H  | C | D |   <---------- Suits
		|_____|_____|___|___|
		|     |     |   |   |
		|_____|_____|___|___|  <---------- Count


*/


	int * playeronesuitcount = new int[4];
	//initializes the counts to zero
	for (int i = 0; i < 4; ++i)
		{
			playeronesuitcount[i] = 0; 
		}

	//tallies up values
	for (int i = 0; i < 7; ++i)
	{
		playeronesuitcount[player.getCard(i).getSuit() ]++;
	}




	

		if(hasStraightFlush(playeronehandvals,playeronesuitcount, player)  != -1)
		{
			return hasStraightFlush(playeronehandvals, playeronesuitcount, player);
		}

		if(hasFourofaKind(playeronehandvals) != -1)
		{
			return hasFourofaKind(playeronehandvals);
		}

		if(hasFullHouse(playeronehandvals) != -1)
		{
			return hasFullHouse(playeronehandvals);
		}

		if(hasFlush(playeronehandvals, playeronesuitcount, player) != -1)
		{
			return hasFlush(playeronehandvals, playeronesuitcount, player);
		}

		if(hasStraight(playeronehandvals) != -1)
		{
			return hasStraight(playeronehandvals);
		}

		if(hasThreeofaKind(playeronehandvals) != -1)
		{
			return hasThreeofaKind(playeronehandvals);
		}

		if(hasTwoPair(playeronehandvals) != -1)
		{
			return hasTwoPair(playeronehandvals);
		}

		if(hasOnePair(playeronehandvals) != -1)
		{
			return hasOnePair(playeronehandvals);
		}

		if(highCard(playeronehandvals) != -1)
		{
			return highCard(playeronehandvals);
		}

		return -1;







		//

}


static double highCard(int* amountofcards)
{

	double sequentialvalues = 0;
	double dividingFactor = 1.0;
	

	int counter = 0;
	for(int k= 13; k >=1; k--)
	{

		if(amountofcards[k] >0 && counter < 5)
				{
					sequentialvalues += (k+1)*dividingFactor;

					dividingFactor= dividingFactor/100;

					

				if(++counter == 5)
				{
					break;
				}

				}
	}

	if(sequentialvalues > 0)
	{
		return sequentialvalues;
	}

	return -1;
}


//pass a tallied up array of 14 values
//returns value of one pair, -1 if it is not a one pair 
static double hasOnePair(int*  amountofcards)
{

	
	for(int i = 13; i >= 1; --i)
	{
		if(amountofcards[i] == 2)
		{

			double sequentialvalues = 0.0;
			double dividingFactor = 1.0/100;

			int counter = 0;
			for(int k = 13; k >= 1; k--)
			{
				if(amountofcards[k] >0 && k!= i && counter < 3)
				{
					//cout << "Found card at " << k+1 << endl;
					sequentialvalues += (k+1)*dividingFactor;
					//cout << sequentialvalues<< "bye" << endl;

					dividingFactor= dividingFactor/100;
					//cout << dividingFactor << "hi" << endl;

					++counter;
				}

				if(counter == 3)
				{
					break;
				}
			}
			

			return i + 1.0000000 + 100.0000000 + sequentialvalues;
		}
	}

	return -1;


}


//returns the highest value of the two pair, if there is no two pair, it will return -1
static double hasTwoPair(int * amountofcards)
{

	int paircount = 0;
	int secondhigh = -1;
	int highCard = -1;
	for(int i = 13; i >= 1; --i)
	{


		if(amountofcards[i] == 2)
		{
			
			++paircount;
			if(highCard != -1)
			{
				secondhigh = i;
				break;

			}

			else
			{
				highCard = i;
			}
			
		}

	}

	if(paircount == 2)
		{
			int kicker = -1;

			for(int k = 13; k>= 1 ; --k)
			{
				//bug at and sign 
				if(amountofcards[k] > 0 && (k != highCard && k!=secondhigh) )
				{
					kicker = k;
					break;
				}

			}

			return 200.0 + (highCard+ 1.00) + ((secondhigh +1.00)/100.0) + ((kicker+1.0)/10000.0);
		}


	return -1;
}

static double hasThreeofaKind(int * amountofcards)
{

	int triple = -1;
	for(int i = 1; i < 14; ++i)
	{
		if(amountofcards[i] == 3)
		{
			triple = i;
		}

	}


	if(triple != -1)
		{
			double sequentialvalues = 0.0;
			double dividingFactor = 1.0/100;
			int count = 0;
			
			for(int k = 13; k >= 1; k--)
			{
				if(amountofcards[k] >0 && k!= triple && count < 2)
				{
					sequentialvalues += (k+1)*dividingFactor;
					dividingFactor= dividingFactor/100;
					count++;
				}
			}
			return triple + 1.0000000 + 300.0000000 + sequentialvalues;

			
		}


	return -1;
}


//returns highest value in the straight, if there is none it will return -1
static double hasStraight(int * amountofcards)
{
	int amountinarow = 0;
	for(int i = 13; i >= 0; --i)
	{


		while(i >= 0 && (amountofcards[i] != 0) && amountinarow < 5)
		{

			++amountinarow;
			--i;
			

		}

		if(amountinarow >=5)
		{
			return i + 6 + 400;
		}

		amountinarow = 0;

	}

	return -1;
}



//returns type of suit that is highest, otherwise it is -1 
static double hasFlush(int * amountofcards, int * suits, Person& p)
{
	int suit;
	int count = 0;
	double sequentialvalues = -1;
	double dividingFactor = 1.0;
	for(int i = 0; i < 4; ++i)
	{
		if(suits[i] >= 5)
		{
			suit = i;
		}
	}

	for (int j = 14; j > 0; j = j - 1)
	{	
		for (int q = 0; q < 7; q++)
		{
			if (p.getCard(q).getVal() == j && p.getCard(q).getSuit() == suit && count < 5)
			{
				sequentialvalues += j*dividingFactor;
				dividingFactor = dividingFactor/100;
				count++;
			}
		}
	}

	if (count == 5)
	{
		return 500.0 + 1 + sequentialvalues;
	}

	return -1;
}





//returns triple.double otherwise returns -1
static double hasFullHouse(int * vals)
{
	if(hasOnePair(vals) > 0 && hasThreeofaKind(vals) > 0 && hasOnePair(vals) != hasThreeofaKind(vals))
	{
		return double(int(hasThreeofaKind(vals) - 300.0)) + (double(int(hasOnePair(vals) - 100.0))/100.0) + 600.0;
	}

	return -1;
}



//returns the suit of the four of the kind,   -1 if the Person does not have 4OK
static double hasFourofaKind(int* vals)
{

	int quad = -1;

	for(int i = 0; i < 14; ++i)
	{
		if(vals[i] == 4)
		{
			quad = i;
		}
	}


	if(quad != -1)
		{
			double sequentialvalues = 0.0;
			double dividingFactor = 1.0/100;
			int count = 0;
			
			for(int k = 13; k >= 1; k--)
			{
				if(vals[k] >0 && k!= quad && count < 1)
				{
					sequentialvalues += (k+1)*dividingFactor;
					dividingFactor= dividingFactor/100;
					count++;
				}
			}
			return quad + 1.0000000 + 700.0000000 + sequentialvalues;
		}


	return -1;
}


static double hasStraightFlush(int* vals, int* suits, Person &p)
{


	if(hasStraight(vals) == -1 || hasFlush(vals,suits,p) == -1 )
	{
		return -1;
	}



	int highCard  = int(hasStraight(vals)-400);
	int suit = -1;

	for(int i = 0; i < 4; ++i)
	{
		if(suits[i] >= 5)
		{
			suit = i;
		}
	}

	int count = 0; 

	for (int j = highCard; j > highCard - 5; j = j - 1)
	{	
		for (int q = 0; q < 7; q++)
		{
			if (p.getCard(q).getVal() == j && p.getCard(q).getSuit() == suit)
			{ count++; }
			else
			{ continue; }
		}
	}

	if (count == 5)
	{
		return 800 + highCard;
	}
	else if (highCard == 5)
	{
		return -1;
	}

	count = 0; 

	for (int j = highCard - 1; j > highCard - 6; j = j - 1)
	{	
		for (int q = 0; q < 7; q++)
		{
			if (p.getCard(q).getVal() == j && p.getCard(q).getSuit() == suit)
			{ count++; }
			else
			{ continue; }
		}
	}

	if (count == 5)
	{
		return 800 + highCard - 1;
	}
	else if (highCard == 6)
	{
		return -1;
	}

	


	count = 0; 

	for (int j = highCard - 2; j > highCard - 7; j = j - 1)
	{	
		for (int q = 0; q < 7; q++)
		{
			if (p.getCard(q).getVal() == j && p.getCard(q).getSuit() == suit)
			{ count++; }
			else
			{ continue; }
		}
	}

	if (count == 5)
	{
		return 800 + highCard - 2;
	}

	return -1;
}










};
