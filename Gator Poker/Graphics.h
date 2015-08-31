#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <iostream>
#include <string>

using namespace std;

class Graphics{


public:
	Graphics();
	void printSingleCards(string card);
	void printDoubleCard(string card1, string card2);
	void printLogo();
	void printCredits();
	void printFlop(string card1, string card2, string card3, string card4, string card5);
	string convertCorner(string card);
	string convertSuit(string card);

};
#endif