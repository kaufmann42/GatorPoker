#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "person.h"
#include "turn.h"

using namespace std;

Turn::Turn(vector<Person*>& player, vector<bool>& fold, int b, int p) {

	pot = p;
	bigBlind = b;
	bet = 2*b;
	n = 0;
	raiseNum = 0;
	playerNum = 0;
	gameStart = true;

	cout << endl << endl;
	cout<< "\n~~The Turn Round~~" << endl ;
	cout<< "The current bet is $" << bet << endl << endl;

	while(true) {
		
		if(n == player.size()){
			break;
		}

		if(count(fold.begin(),fold.end(),false) == 1){
			break;
		}

		if(raiseNum == 4) {
			break;
		}

		if((unsigned int)playerNum == player.size()){
			playerNum = 0;
		}

		if(fold[playerNum] == false) {
			
			if(playerNum == 0) {
				
				cout << "Cards on the table:" << endl << endl;
				player[playerNum]->showTable(4);

				cout << player[playerNum]->getName() << " you have $" << player[playerNum]->getMoney() << endl;
				cin.clear();
				cout << player[playerNum]->getName() << " would you like to (1) see your cards (2) fold (3) call (4) bet: " << endl;
				cin >> decision;
				
				
				while(cin.fail() || (decision != 1 && decision != 2 && decision != 3 && decision != 4))
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "\nInvalid input.\n\n";
					cout << "Would you like to (1) see your cards (2) fold (3) call (4) raise: " << endl;
					cin >> decision;


				}				
				
				
				
				cout << endl;
			}

			else{
				aidecision = player[playerNum]->aiDecision(1, bet);

				if(aidecision > 0) {
					decision = 4;
				}
				else{
					decision = -aidecision;
				}
			}

			if(decision == 1) {
					cin.clear();
					player[playerNum]->showHand();
					cout << endl;
					cout << player[playerNum]->getName() << " would you like to (2) fold (3) call (4) bet: " << endl;
					cin >> decision;
					
					
										
					while(cin.fail() || (decision != 2 && decision != 3 && decision != 4))
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "\nInvalid input.\n\n";
						cout << "Would you like to (2) fold (3) call (4) raise: " << endl;
						cin >> decision;
					}
					
				}

			if(decision == 2) {
				if(playerNum == 0) {
					fold[playerNum] = true;
					cout << endl;
				}

				else{
					cout << "Player " << player[playerNum]->getName() << " folded" << endl;
					fold[playerNum] = true;
					cout << endl;
				}
					
			}

			if(decision == 3) {
				if(playerNum > 0) {
					
					cout << "Player " << player[playerNum]->getName() << " checked" << endl;
					
				}
			}

			if(decision == 4) {
			
				if(playerNum == 0) {
					moneyLost = bet;
					if(player[playerNum]->getMoney() >= moneyLost) {
						pot = pot + moneyLost;
						player[playerNum]->setLivePot(moneyLost);
						player[playerNum]->setMoney(player[playerNum]->getMoney() - moneyLost);
						raiseNum++;
						n = 0;
					}
					else if(player[playerNum]->getMoney() == moneyLost) {
						pot = pot + moneyLost;
						player[playerNum]->setLivePot(moneyLost);
						player[playerNum]->setMoney(player[playerNum]->getMoney() - moneyLost);
						break;
						
					}

					else if(player[playerNum]->getMoney() < moneyLost) {
						pot = pot + player[playerNum]->getMoney();
						player[playerNum]->setMoney(0);
						break;
						
					}
				}
				
				else {
					
					moneyLost = bet;

					if(player[playerNum]->getMoney() >= moneyLost){
						cout << "Player " << player[playerNum]->getName() << " called $" << bet << endl;
						cout << endl;
						pot = pot + moneyLost;
						player[playerNum]->setLivePot(moneyLost);
						player[playerNum]->setMoney(player[playerNum]->getMoney() - moneyLost);
					}

					if(player[playerNum]->getMoney() == moneyLost) {
						pot = pot + moneyLost;
						player[playerNum]->setLivePot(moneyLost);
						player[playerNum]->setMoney(player[playerNum]->getMoney() - moneyLost);
						break;
						
					}

					if(player[playerNum]->getMoney() < moneyLost) {
						pot = pot + player[playerNum]->getMoney();
						player[playerNum]->setMoney(0);
						break;
						
					}
				}
			}
	
		}
		playerNum++;
		n++;
	}
}


int Turn::getBigBlind() {
	return bigBlind;
}
int Turn::getPot() {
	return pot;
}
