#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "card.h"
using namespace std;

class Deck
{	
	string names[13];
	public:
		Deck();
		void dealHand(vector<Person*>& pA, int size);		//push cards to player
		Card getCard(int position);		//returns object card at position
		void removeCard(int position); 	//delete card from the deck at position
		Card deck[52];
		
	
	private:
		int nm;
		int count;
		 
};
#endif

