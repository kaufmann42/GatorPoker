#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include "person.h"
#include "deck.h"
#include "winnercheck.cpp"
#include "preflop.h"
#include "flop.h"
#include "turn.h"
#include "river.h"
#include "Graphics.h"

using namespace std;

int main() {

	int n;
	int buyIn;
	double rank;
	int winner;
	unsigned int j;
	double winningRank;
	int gameNum;
	int tempMoney;
	int pot;
	int money;
	int start;
	bool endGame;
	int decisionS;
	string name;
	vector<Person*> player;
	vector<bool> fold;
	PreFlop *preFlop;
	Flop *flop;
	Turn *turn;
	River *river;
	Graphics *g;
	
	g = new Graphics();

	g->printLogo();

	cout << "Welcome to Gator Poker. Would you like to play the game (1) or run test cases (2): " << endl;
	cin >> start;


	//validator
	while(cin.fail() || (start != 1 && start != 2))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\nInvalid input.\n\n";
			cout << "Press (1) to play the game or (2) to run test cases: " << endl;
			cin >> start;
		}

	//endvalidator




	if(start == 1) 
	{

		cin.clear();
		cout<< "\nEnter number of players: " << endl;
		cin >> n;


		//validator

		while(cin.fail() || (n < 3 || n > 8))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\nInvalid input.\n\n";
			cout << "Please enter a number between 3 and 8 players" << endl;
			cin >> n;
		}


		//endvalidator




		cin.clear();

		cout << "\nWhat is your name?" << endl;
		

		//input name, Validates it so you can put a whole name line
		cin.ignore(10000, '\n');
		getline(cin, name);
		//end input player one name


		cin.clear();


		//Enter game buy in amount
		cout << "\nEnter the buy-in amount between $100 and $1,000: \n" << endl;
		cin >> buyIn;
		while(cin.fail() || (buyIn < 100 || buyIn > 1000))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\nInvalid input.\n\n";
			cout << "Please enter an amount between $100 and $1,000" << endl;
			cin >> buyIn;
		}

		cout << endl;
		cout << "\n\n" << endl;

		


		//This loop initializes all of the players
		for(int i = 0; i < n; i++)
		{
			if(i == 0)
			{
				player.push_back(new Person(name, buyIn, false));
			}
			else 
			{
				if(i == 1)
				{
					cin.clear();
					cin.ignore(10000, '\n');
				}

				cout << "\nPlease enter name of A.I. " << i << ":" << endl;
				getline(cin, name);
				cout << endl;
				player.push_back(new Person(name, buyIn, true));
			}
		}

		gameNum =0;
		endGame = false;



		/*
		This is the start of the game. Each itteration of this loop is one game.
		A game consists of 4 betting rounds: the pre-flop, flop, turn, and river.
		After each 4 rounds the players go to a showdown to see who won the money.
		If at anytime someone goes all in, everone goes straight to the showdown.
		*/
		while(true) 
		{
		
			cout << "=================================================================\n\n\n" << endl;
			for(unsigned int i = 0; i < player.size(); ++i)
			{
				cout << player[i]->getName() << " has $" << player[i]->getMoney() << endl;
			}


			//if this is not the first game you can choose to stop playing
			if(gameNum > 0) 
			{
				
				
			
				cin.clear();
				cout << "Would you like to play another game? Press (1) to Continue. Press (2) to Exit" << endl;
				cin >> decisionS;

				while(cin.fail() || (decisionS <1 || decisionS > 2))
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "\nInvalid input.\n\n";
					cout << "Press (1) to Continue. Press (2) to Exit" << endl;
					cin >> decisionS;
				}

				if( decisionS == 2)
				{
					break;
				}

			}

			Deck *d = new Deck();
			d->dealHand(player,n);

			fold.clear();

			for(int i = 0; i < n; i++)
			{
				fold.push_back(false);
			}

			//starts preFlop round
			preFlop = new PreFlop(player, fold);
			pot = preFlop->getPot();
			endGame = false;

			//checks to make sure no one is all-in
			for(unsigned int i = 0; i < player.size(); i++)
			{
				if(player[i]->getMoney() == 0) {
					endGame = true;
				}
			}

			if(count(fold.begin(),fold.end(),false) == 1)
			{
				endGame = true;
			}	

			//if the no one went all-in start the flop round
			if(endGame == false) 
			{

				flop = new Flop(player,fold, preFlop->getBigBlind(), preFlop->getPot());
				pot = flop->getPot();

				//checks to make sure no one is all-in
				for(unsigned int i = 0; i < player.size(); i++)
				{
					if(player[i]->getMoney() == 0) 
					{
						endGame = true;
					}
				}

				if(count(fold.begin(),fold.end(),false) == 1){
					endGame = true;
				}
				//if the no one went all-in start the river round
				if(endGame == false) {

					turn = new Turn(player,fold, flop->getBigBlind(), flop->getPot());
					pot = turn->getPot();

					//checks to make sure no one is all-in
					for(unsigned int i = 0; i < player.size(); i++)
					{
						if(player[i]->getMoney() == 0) 
						{
							endGame = true;
						}
					}

					if(count(fold.begin(),fold.end(),false) == 1)
					{
						endGame = true;
					}
					//if the no one went all-in start the river round
					if(endGame == false) 
					{
						river = new River(player, fold, turn->getBigBlind(), turn->getPot());
						pot = river->getPot();
					}
				}
			}

			//This determines the ranks
			WinnerCheck::winnercheck(player,n);

			rank = 0;
			winningRank = 0;
			winner = 0;


			//displays table
			cout<<"The Table:" << endl;
			player[0]->showTable(5);

			//Lays down the cards for all players still in the game the table
			for(unsigned int i = 0; i < player.size(); ++i)
			{
				cout << player[i]->getName() << " has the following hand: ";
				player[i]->showHand();
			}

			//These loops determines the actual winner
			for(int i = 0; i < n; i++) 
			{
				rank = player[i]->getRank();
				if(rank > winningRank && fold[i] == false) 
				{
					winner = i;
					winningRank = rank;

				}
			}

			int count = 1;
			for(int i = 0; i < n; i++) 
			{
				rank = player[i]->getRank();
				if(rank == winningRank && fold[i] == false && i!= winner) 
				{
					count++;

				}
			}

			for(int i = 0; i < n; i++) 
			{
				rank = player[i]->getRank();
				if(rank == winningRank && fold[i] == false) 
				{
					if (count > 1)
					{
						cout << "There was a tie!" << endl;
					}
				
					player[i]->addMoney(int(pot/count));

					cout << player[i]->getName() << " won $" << int(pot/count) << endl;

				}
			}



			j = 0;
			//This deletes the player if they lost all of their money at the end of the game
			while(j < player.size()) {

				if(player[j]->getMoney() == 0) 
				{
					cout << player[j]->getName() << " busted out" << endl;
					player.erase(player.begin() + j); 
					fold.erase(fold.begin() + j);
					j = -1;
					n--;
				}
				j++;
			}

			if(player[0]->getAI() == true) 
			{
				break;
			}

			for(int i = 0; i < n; i++) 
			{
				player[i]->clearLivePot();
			}
			pot = 0;
			gameNum++;

		}
		
		//Once only 1 player is left
		//or the player chooses to stop playing anymore
		//the overall winner is determined

		for(int i = 0; i < n; i++) 
		{
			tempMoney = player[i]->getMoney();
			if(tempMoney > money) 
			{
				money = tempMoney;
				winner = i;
			}
		}

		cout << "The winner is " << player[winner]->getName() << " with a total of $" << player[winner]->getMoney() << endl << endl;
		g->printCredits();

	}




	//   'Test Console code'
	else{
		

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nWelcome to the test console!\n\n\n\n\n" << endl;

	 	cout<< "\n\nPlease enter buy in amount (between 100 and 1000): ";
	 	int buyInTestConsole = 0;
	 	cin.clear();
	 	cin >> buyInTestConsole;

	 	while(cin.fail() || (buyInTestConsole < 100  || buyInTestConsole > 1000))
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\nInvalid input.\n\n";
			cout << " Please enter buy in amount (between 100 and 1000): "<< endl;
			cin >> buyInTestConsole;
		}
		
		Person* one = new Person("Player 1", buyInTestConsole, false);
		Person* two = new Person("Player 2", buyInTestConsole, false);
		Person* three = new Person("Player 3", buyInTestConsole, false);

		vector<Person*> test;

		test.push_back(one);
		test.push_back(two);
		test.push_back(three);


		cout<< "\n\nWould you like to randomly deal the cards?\n\n Press (1) for Yes, or (2) for no\n" << endl;
		int dealMethod = -1;

		cin >> dealMethod;

		while(cin.fail() || (dealMethod != 1 && dealMethod != 2) )
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\nInvalid input.\n\n";
			cout << "Would you like to randomly deal the cards?\n\n Press (1) for Yes, or (2) for no\n" << endl;
			cin >> dealMethod;	
		}
		//If the user chooses to randomly deal the cards it will
		if(dealMethod == 1)
		{
			Deck * d = new Deck();
			d->dealHand(test, 3);
		}


		//The user can manually test cases to see if they work
		else
		{
			cout << "\n\nYou are now going to enter Five cards that will be on the table\n\n";
			cout << "Values:\n\nACE..................1\nDeuce................2\nThree................3\n*******\nJack.................11\nQueen................12\nKing.................13" ;
			cout << "\nSuits:\n 0...........Spades\n1..........Hearts\n2.............Clubs\n3..............Diamonds" << endl;
			for(int i = 2; i < 7; i++)
			{
				cout<< "Please enter the card value for the " << i-1 << "(st/nd/rd/th) card on the table " << endl;
				int tableCardVal = -1;
				cin >> tableCardVal;

				while(cin.fail() || (tableCardVal < 1 || tableCardVal > 13) )
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "\nInvalid input.\n\n";
					cout << "Please enter the card value for the " << i-1 << "(st/nd/rd/th) card on the table  " << endl;
					cin >> tableCardVal;
				}


				cout<< "Please enter the suit value for the " << i-1 << "(st/nd/rd/th) card on the table " << endl;
				int tableSuitVal = -1;
				cin >> tableSuitVal;


				while(cin.fail() || (tableSuitVal < 0 || tableSuitVal > 3) )
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "\nInvalid input.\n\n";
					cout << "Please enter the suit value for the " << i-1 << "(st/nd/rd/th) card on the table  " << endl;
					cin >> tableSuitVal;
				}


				for(int k = 0; k < 3; k++)
				{
		
					test[k]->addCard(Card(tableCardVal, tableSuitVal)  , i);
				}

			}


			cout<< "\n\n\n\n\nYou are now going to pass the cards to the indivitual players.." << endl;

			for(int i  = 0; i < 3; ++i)
			{

				
				for(int k = 0; k <2; k++)
				{

					int handCardVal = -1;
					int handSuitVal = -1;

					cout<< "Please enter the card value for the " << k+1 << "(st/nd) card in the player" << i+1<< "'s  hand  " << endl;
					cin >> handCardVal;

					while(cin.fail() || (handCardVal < 1 || handCardVal > 13) )
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "\nInvalid input.\n\n";
						cout<< "Please enter the card value for the " << k+1 << "(st/nd) card in the player" << i+1<< "'s  hand  " << endl;
						cin >> handCardVal;
					}


					cout<< "Please enter the suit value for the " << k+1 << "(st/nd) card in the player" << i+1<< "'s  hand  " << endl;
					cin >> handSuitVal;


					while(cin.fail() || (handSuitVal < 0 || handSuitVal > 3) )
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "\nInvalid input.\n\n";
						cout << "Please enter the suit value for the " << k+1 << "(st/nd) card in the player" << i+1<< "'s  hand  " << endl;
						cin >> handSuitVal;
					}


					test[i]->addCard(Card(handCardVal,handSuitVal), k);

				}

			}



		}
		//end passing cards to players




		for(int i = 0; i < 3; i++)
		{
			test[i]->toString();
			cout << "\n\n" << endl;

		}

		cout<< "The cards on the table are: \n\n" << endl;

		for(int i =2; i <7; ++i)
		{
			cout << test[0]->getCard(i).toString() << endl;

		}

		WinnerCheck::winnercheck(test,3);
		for(int i = 0; i < 3; i++)
		{
			cout.precision(8);
			cout << test[i]->getName() << " rank: " <<fixed <<  test[i]->getRank() << endl;
			cout << "\n" << endl;

		}


		cout << "Thumb Print Guide:\n\n" << endl;

		cout << "\t8**			StraightFlush" << endl;
		cout << "\t7**			Four of a Kind" << endl;
		cout <<	"\t6**			Full House"		<< endl;
		cout <<	"\t5**			Flush"			<< endl;
		cout <<	"\t4**			Straight"		<< endl;
		cout <<	"\t3**			Three of a Kind"<< endl;
		cout <<	"\t2**			Two Pair"		<< endl;
		cout <<	"\t1**			One Pair"		<< endl;
		cout <<	"\t **			High Card"		<< endl;

		


	}
	//end test console

}
