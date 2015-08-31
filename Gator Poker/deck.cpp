#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "deck.h"
#include "person.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

using namespace std;

Deck::Deck()
{

	nm=0;
	count=0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			deck[count] = Card(j, i);
			nm++;
			count++;
		}
		nm = 0;
	}





	//SHUFFLE 
	int n = 0;
	srand( time(NULL) );
	while (n<10000)
	{
		int randomone = rand()%51;
		int randomtwo = rand()%51;

		Card temp = deck[randomone];//this creates a temporary card
		deck[randomone] = deck[randomtwo];
		deck[randomtwo] = temp; 
		n++;

		/*
		cout<< "Swapping position: " <<  randomone << " Card: with position: " << randomtwo <<  endl;
		*/
	}
 


}

//returns a card
Card Deck::getCard(int position)
{
	return deck[position];
}


//removes a card
void Deck::removeCard(int i)
{ 
	deck[i] = Card(20, 20);
}

void Deck::dealHand(vector<Person*>& pA, int size)
{

  
	// Deal Individual Cards to Slot [0] and [1]
	for (int i = 0; i < size; i++)
	{
		pA[i]->addCard(deck[2 * i], 0);
		pA[i]->addCard(deck[2 * i + 1], 1);
	}

	// Deal Shared Cards to Slots [2] to [6]
	for (int i = 0; i < size; i++)
	{
		pA[i]->addCard(deck[2 * size], 2);
		pA[i]->addCard(deck[2 * size + 1], 3);
		pA[i]->addCard(deck[2 * size + 2], 4);
		pA[i]->addCard(deck[2 * size + 3], 5);
		pA[i]->addCard(deck[2 * size + 4], 6);
	}
}
