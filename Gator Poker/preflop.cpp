#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "person.h"
#include "preflop.h"

using namespace std;

PreFlop::PreFlop(vector<Person*>& player, vector<bool>& fold) {

	n = 0;
	pot = 0;
	raiseNum = 0;
	playerNum = 0;
	gameStart = true;

	cout << "\n~~PreFlop Round~~" << endl << endl << endl;

	while(true) {
		
		if(n >= player.size()){
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
			if(playerNum == 0 && gameStart == true) {
				
				//finds 10% amount of lowest players hand to set as small blind
				
				int smallestamount = player[0]->getMoney();
				for(unsigned int i = 1; i < player.size(); ++i)
				{
					if(player[i]->getMoney() < smallestamount)
					{
						smallestamount = player[i]->getMoney();
					}
				}
				
				if(smallestamount * .1 < 1)
				{
						smallestamount = 1;
				}
				
				else
				{
					smallestamount = smallestamount * .1;
				}
				
				
				cout << player[playerNum]->getName() << " you have $" << player[playerNum]->getMoney() << endl;
				cin.clear();
				cout<< player[0]->getName() << " Please set the anti (Maximum Value is $" << smallestamount << ")" << endl;
				cin >> smallBlind;
				cout << "\n" << endl;
				
				while(cin.fail() || (smallBlind > smallestamount) || smallBlind < 1)
				{
					cin.clear();
					cin.ignore(10000, '\n');
					cout << "\nInvalid input.\n\n";
					cout << " Please set the anti (Maximum Value is $" << smallestamount << ")" << endl;
					cin >> smallBlind;
					cout << "\n" << endl;
				}
				
				
				cout << endl;
				player[playerNum]->setLivePot(smallBlind);
				player[playerNum]->setMoney(player[playerNum]->getMoney() - smallBlind);
				playerNum++;
				n++;
				pot = pot + smallBlind;

				bigBlind = smallBlind;     
				bet = bigBlind;
				player[playerNum]->setLivePot(bigBlind);
				player[playerNum]->setMoney(player[playerNum]->getMoney() - bigBlind);
				cout << player[playerNum]->getName() << " called " << bigBlind << endl;
				cout << "\n" << endl;
				pot = pot + bigBlind;
				gameStart = false;
			}
			else{
				
				if(playerNum == 0) {
					cout << player[playerNum]->getName() << " you have $" << player[playerNum]->getMoney() << endl;
					cin.clear();
					cout << player[playerNum]->getName() << " Would you like to (1) see your cards (2) fold (3) call (4) bet: " << endl;
					cin >> decision;
					
					
					while(cin.fail() || (decision != 1 && decision != 2 && decision != 3 && decision != 4))
					{
						cin.clear();
						cin.ignore(10000, '\n');
						cout << "\nInvalid input.\n\n";
						cout << "Would you like to (1) see your cards (2) fold (3) call (4) bet: " << endl;
						cin >> decision;
					}
					
					
					
					cout << endl;
				}

				else{
					
					tempMoney = 0;

					for(unsigned int i = 0; i < player.size(); i++) {
						money = player[i]->getMoney();
						if(money > tempMoney) {
							tempMoney = money;
						}
					}
					aidecision = player[playerNum]->aiDecision(tempMoney, bet);

					if(aidecision > 0) {
						decision = 4;
						bet = aidecision;
					}
					else{
						decision = -aidecision;
					}
				}

				if(decision == 1) {
						cin.clear();
						player[playerNum]->showHand();
						cout << endl;
						cout << player[playerNum]->getName() << " Would you like to (2) fold (3) call (4) bet: " << endl;
						cin >> decision;
						cout << "\n" << endl;
						
						
						while(cin.fail() || (decision != 2 && decision != 3 && decision != 4))
						{
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "\nInvalid input.\n\n";
							cout << "Would you like to (2) fold (3) call (4) bet: " << endl;
							cin >> decision;
							cout << "\n" << endl;
						}
						
						
						cout << endl;
					}

				if(decision == 2) {
					if(playerNum == 0) {
						fold[playerNum] = true;
						cout << endl << endl;
					}

					else{
						cout << "Player " << player[playerNum]->getName() << " folded" << endl;
						fold[playerNum] = true;
						cout << endl;
					}
					
						
				}

				if(decision == 3) {
					if(playerNum == 0) 
					{

						moneyLost = bet - player[playerNum]->getLivePot();

						if(player[playerNum]->getMoney() > moneyLost) {
							pot = pot + moneyLost;
							player[playerNum]->setLivePot(moneyLost);
							player[playerNum]->setMoney(player[playerNum]->getMoney() - moneyLost);

							
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
						
						moneyLost = bet - player[playerNum]->getLivePot();

						if(player[playerNum]->getMoney() >= moneyLost){
							cout << "Player " << player[playerNum]->getName() << " called $" << bet << endl;
							cout << endl;
							cout << "\n" << endl;
							pot = pot + moneyLost;
							player[playerNum]->setLivePot(moneyLost);
							player[playerNum]->setMoney(player[playerNum]->getMoney() - moneyLost);
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
					
				}

				if(decision == 4) 
				{
				
					if(playerNum == 0) {
						cin.clear();
						oldBet = bet;
						cout << "How much would you like to bet: " << endl;
						cin >> bet;
						cout << "\n" << endl;
						moneyLost = bet - player[playerNum]->getLivePot();

						if(player[playerNum]->getMoney() >= moneyLost) {
							pot = pot + moneyLost;
							player[playerNum]->setLivePot(moneyLost);
							player[playerNum]->setMoney(player[playerNum]->getMoney() - moneyLost);

						}/*

						else if(player[playerNum]->getMoney() == moneyLost) {
							pot = pot + moneyLost;
							player[playerNum]->setLivePot(moneyLost);
							player[playerNum]->setMoney(player[playerNum]->getMoney() - moneyLost);
							break;
						}*/

						else if(player[playerNum]->getMoney() < moneyLost) {
							pot = pot + moneyLost;
							player[playerNum]->setLivePot(moneyLost);
							player[playerNum]->setMoney(player[playerNum]->getMoney() - moneyLost);
							break;
						}
					}
					
					else {
						moneyLost = bet - player[playerNum]->getLivePot();
						
						if(player[playerNum]->getMoney() >= moneyLost){
							cout << "Player " << player[playerNum]->getName() << " raised $" << bet << endl;
							cout << endl;
							pot = pot + moneyLost;
							player[playerNum]->setLivePot(moneyLost);
							player[playerNum]->setMoney(player[playerNum]->getMoney() - moneyLost);

						}

						/*else if(player[playerNum]->getMoney() == moneyLost) {
							pot = pot + moneyLost;
							player[playerNum]->setLivePot(moneyLost);
							player[playerNum]->setMoney(player[playerNum]->getMoney() - moneyLost);
							break;
							
						}*/

						else if(player[playerNum]->getMoney() < moneyLost) {
							pot = pot + player[playerNum]->getMoney();
							player[playerNum]->setMoney(0);
							break;
						}
						
					}
					//cout << "BOOM";
					raiseNum++;
					
					
				}
			}
		}
		playerNum++;
		n++;
		//end while loop
	}
}


int PreFlop::getBigBlind() {
	return bigBlind;
}
int PreFlop::getPot() {
	return pot;
}
