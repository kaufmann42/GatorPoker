#include <iostream>
#include <string>
#include "Graphics.h"

using namespace std;

Graphics::Graphics() {

}

void Graphics::printSingleCards(string card){
	string corner;
	string suit;
	corner = convertCorner(card);
	suit = convertSuit(card);
	if (suit.compare("S") == 0)
	{
		cout << " _______" << endl;
		cout << "| " << corner << " .   |" << endl;
		cout << "|  /.\\  |" << endl;
		cout << "| (_._) |" << endl;
		cout << "|   |   |" << endl;
		cout << "| ____" << corner << " |\n";
	}
	if (suit.compare("C") == 0)
	{
		cout << " _______" << endl;
		cout << "| " << corner << " _   |" << endl;
		cout << "|  ( )  |" << endl;
		cout << "| (_'_) |" << endl;
		cout << "|   |   |" << endl;
		cout << "| ____ " << corner << "|\n" ;
	}
	if (suit.compare("H") == 0)
	{
		cout << " _______" << endl;
		cout << "|" << corner << " _ _  |" << endl;
		cout << "| ( v ) |" << endl;
		cout << "|  \\ /  |" << endl;
		cout << "|   .   |" << endl;
		cout << "| _____" << corner << "|\n" ;
	}
	if (suit.compare("D") == 0)
	{
		cout << " _______ " << endl;
		cout << "| " << corner << " ^   |" << endl;
		cout << "|  / \\  |" << endl;
		cout << "|  \\ /  |" << endl;
		cout << "|   .   |" << endl;
		cout << "| ____ " << corner << "|\n" ;
	}
}
//prints out two cards in the form of a players hand.
//INPUT: First card value, second card value, and the suit.
void Graphics::printDoubleCard(string card1, string card2) {
	string corner1;
	string corner2;
	string suit2;
	string suit1;
	corner1 = convertCorner(card1);
	corner2 = convertCorner(card2);
	suit2 = convertSuit(card2);
	suit1 = convertSuit(card1);
	cout << "\n ______" << endl;   //changed this
	cout << "|" << corner1 << " ____|_" << endl;
	cout << "|" << suit1 << "|" << corner2 << "     |" << endl;

	if (suit2.compare("S") == 0)
	{
		cout << "| |  /\\  |" << endl;
		cout << "| | /  \\ |" << endl;
		cout << "| |( -- )|" << endl;
		cout << "|_|  )(  |" << endl;
	}

	if (suit2.compare("C") == 0)
	{
		cout << "| |  ..  |" << endl;
		cout << "| | (  ) |" << endl;
		cout << "| |( )( )|" << endl;
		cout << "|_|  ||  |" << endl;
	}

	if (suit2.compare("D") == 0)
	{
		cout << "| |  /\\  |" << endl;
		cout << "| | /  \\ |" << endl;
		cout << "| | \\--/ |" << endl;
		cout << "|_|  \\/  |" << endl;
	}

	if (suit2.compare("H") == 0)
	{
		cout << "| | _  _ |" << endl;
		cout << "| |/ \\/ \\|" << endl;
		cout << "| |\\    /|" << endl;
		cout << "|_| \\__/ |" << endl;
	}

	cout << "  |_____" << corner2 << "|" << endl;
}
//prints the logo of our game
void Graphics::printLogo() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" <<endl;
	cout<<"\t\t                      _.---._     .---." << endl;
	cout<<"\t\t             __...---' .---. `---'-.   `." << endl;
	cout<<"\t\t   ~ -~ -.-''__.--' _.'( | )`.  `.  `._ :" << endl;
	cout<<"\t\t  -.~~ .'__-'_ .--'' ._`---'_.-.  `.   `-`." << endl;
	cout<<"\t\t   ~ ~_~-~-~_ ~ -._ -._``---. -.    `-._   `." << endl;
	cout<<"\t\t     ~- ~ ~ -_ -~ ~ -.._ _ _ _ ..-_ `.  `-._``--.._" << endl;
	cout<<"\t\t      ~~-~ ~-_ _~ ~-~ ~ -~ _~~_-~ -._  `-.  -. `-._``--.._.--''. ~ -~_" << endl;
	cout<<"\t\t          ~~ -~_-~ _~- _~~ _~-_~ ~-_~~ ~-.___    -._  `-.__   `. `. ~ -_~" << endl;
	cout<<"\t\t              ~~ _~- ~~- -_~  ~- ~ - _~~- _~~ ~---...__ _    ._ .` `. ~-_~" << endl;
	cout<<"\t\t                 ~ ~- _~~- _-_~ ~-_ ~-~ ~_-~ _~- ~_~-_~  ~--.....--~ -~_ ~" << endl;
	cout<<"\t\t                      ~ ~ - ~  ~ ~~ - ~~-  ~~- ~-  ~ -~ ~ ~ -~~-  ~- ~-~" << endl;
	cout<< "\n\n" << endl;	
	cout<< " 	    ██████╗  █████╗ ████████╗ ██████╗ ██████╗     ██████╗  ██████╗ ██╗  ██╗███████╗██████╗ " <<  endl;
	cout <<"	   ██╔════╝ ██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗    ██╔══██╗██╔═══██╗██║ ██╔╝██╔════╝██╔══██╗ " << endl;
	cout<< "	   ██║  ███╗███████║   ██║   ██║   ██║██████╔╝    ██████╔╝██║   ██║█████╔╝ █████╗  ██████╔╝ " << endl;
	cout<< "	   ██║   ██║██╔══██║   ██║   ██║   ██║██╔══██╗    ██╔═══╝ ██║   ██║██╔═██╗ ██╔══╝  ██╔══██╗ " << endl;
	cout <<"	   ╚██████╔╝██║  ██║   ██║   ╚██████╔╝██║  ██║    ██║     ╚██████╔╝██║  ██╗███████╗██║  ██║ " << endl;
	cout <<"	    ╚═════╝ ╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝    ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝	" << endl;
	cout <<" \n\t\t\t\t\t     Welcome to the Swamp..." << endl;
	cout << "\n\n" << endl;
	cout << "\t        :.~.:.~.:.~.:.~.:.~.:.~.:.~.:.~.:.~.:.< >.:.~.:.~.:.~.:.~.:.~.:.~.:.~.:.~.:" << endl;
	cout << "\t\t                                    _.---._" << endl;
	cout << "\t\t          .-------.  .-------.    .'.-----.'.    .-------.  .-------." << endl;
	cout << "\t\t          |   *   |  | ** ** |   /  | .^. |  \\   |  / \\  |  |   _   |" << endl;
	cout << "\t\t          | *   * |  |*  *  *|  :   |(_ _)|   :  | /   \\ |  | _( )_ |" << endl;
	cout << "\t\t          |*     *|  | *   * |  :   |  ^  |   :  | \\   / |  |(_ . _)|" << endl;
	cout << "\t\t          |  * *  |  |   *   |   \\  |     |  /   |  \\ /  |  |   I   |" << endl;
	cout << "\t\t          |  * *  |  |       |    '.'-----'.'    |       |  |       |" << endl;
	cout << "\t\t          '-------'  '-------'      `'---'`      '-------'  '-------'" << endl;
	cout << "\t\t                                      ) (" << endl;
	cout << "\t\t                                    _(   )_" << endl;
	cout << "\t\t                                   (_______)" << endl;
	cout << "\n\n" << endl;







}
//prints the credits of the game
void Graphics::printCredits() {
	cout << "  ___________  _______________________________________" << endl;
	cout << "/\\          \\|                                       \\" << endl;
	cout << "|:::\\::,,..          Thanks For Playing!         .,::\\" << endl;
	cout << "|::::\\::,,..                                      ,,::\\" << endl;
	cout << " \\::::\\::,,,,,,                                   ..,::\\" << endl;
	cout << "   ``` \\::,,,...      Developers:                 ..,,::\\" << endl;
	cout << "       |::,,,,.         Nicolas Fry                 ,,::|" << endl;
	cout << "      /::,,...            Team Leader            ..,,::/" << endl;
	cout << "     /::,,..            Sergey Rogachev         ..,,::/" << endl;
	cout << "    /::,,..               Developer            ..,,::/" << endl;
	cout << "   |::,,..              Ryan Feeney            .,,::|" << endl;
	cout << "    \\::,,..               Developer            ..,,::\\" << endl;
	cout << "     \\::,,..            Jeffery Hung            ..,,::\\" << endl;
	cout << "      \\::,,..             Developer              ..,,::\\" << endl;
	cout << "       \\::,,..          Daniel D.                  .,,::\\" << endl;
	cout << "        \\::,,.            Developer                 .,,::\\" << endl;
	cout << "    _____\\::..         John Kaufmann                ..::\\" << endl;
	cout << "   /::::::\\::..          Developer & Graphic Artist  ..::\\" << endl;
	cout << "  l:::::::l::..                                     .....::l" << endl;
	cout << "  l:::::::/::..                                      ..::/" << endl;
	cout << "   \\:::::/::,...                                      ::/" << endl;
	cout << "    \\::/::,.......                                ..,::/" << endl;
	cout << "     \\/_____________________________________/|____________/" << endl;
}
//Enter cards and suits: S = spades ~ D = diamonds ~ H = hearts ~ C = clubs
//you DO NOT have to enter anything if you do not want to, a '?' will appear otherwise.
void Graphics::printFlop(string card1, string card2, string card3, string card4, string card5) {
	string suit;
	string suit1;
	string suit2;
	string suit3;
	string suit4;
	string suit5;
	string corner1;
	string corner2;
	string corner3;
	string corner4;
	string corner5;
	corner1 = convertCorner(card1);
	corner2 = convertCorner(card2);
	corner3 = convertCorner(card3);
	corner4 = convertCorner(card4);
	corner5 = convertCorner(card5);
	suit1 = convertSuit(card1);
	suit2 = convertSuit(card2);
	suit3 = convertSuit(card3);
	suit4 = convertSuit(card4);
	suit5 = convertSuit(card5);
	if (suit5.compare("C") == 0)
	{
		suit = "| | | | |    ,    |\n| | | | |   / \\   | \n| | | | |  (_ _)  | \n| | | | |   /_\\   | ";
	}
	else if (suit5.compare("H") == 0)
	{
		suit = "| | | | |   _ _   |\n| | | | |  / ^ \\  | \n| | | | |  \\   /  | \n| | | | |   \\ /   | ";
	}
	else if (suit5.compare("S") == 0)
	{
		suit = "| | | | |    _    |\n| | | | |   (_)   | \n| | | | |  (_)_)  | \n| | | | |   /_\\   | ";
	}
	else if (suit5.compare("D") == 0)
	{
		suit = "| | | | |    /\\   |\n| | | | |   <  >  | \n| | | | |    \\/   | \n| | | | |    '    | ";
	}
	else {
		suit = "| | | | |    ??   |\n| | | | |   ?  ?  | \n| | | | |   ?  ?  | \n| | | | |    ??   | ";
	}


	cout << "~GATOR POKER FLOP~" << endl;
	cout << " _ _ _ _ _________ " << endl;
	cout << "|" << corner1 << "|" << corner2 << "|" << corner3 << "|" << corner4 << "|" << corner5 << "        |" << endl;
	cout << "|" << suit1 << "|" << suit2 << "|" << suit3 << "|" << suit4 << "|" << suit5 << "        |" << endl;
	cout << suit << endl;
	cout << "| | | | |        " << suit5 << "|" << endl;
	cout << "|_|_|_|_|________" << corner5 << "|" << endl;
	cout << "SUITS KEY:" << endl;
	cout << "S = spades ~ D = diamonds ~ H = hearts ~ C = clubs" << endl;
}
//converts the given string into characters and returns a suit and a character.
//INPUT: CARD STRING
//OUTPUT: CARD IN APPROPRIATE STRING FORM
string Graphics::convertCorner(string card) {
	for (unsigned int i = 0; i < card.size(); i++)
	{
		if (card.at(i) == 'A' && card.at(i + 1) == 'c' && card.at(i + 2) == 'e')
		{
			return "A";
		}
		else if (card.at(i) == 'K' && card.at(i + 1) == 'i' && card.at(i + 2) == 'n')
		{
			return "K";
		}
		else if (card.at(i) == 'Q' && card.at(i + 1) == 'u' && card.at(i + 2) == 'e')
		{
			return "Q";
		}
		else if (card.at(i) == 'J' && card.at(i + 1) == 'a' && card.at(i + 2) == 'c')
		{
			return "J";
		}
		else if (card.at(i) == 'O' && card.at(i + 1) == 'n' && card.at(i + 2) == 'e')
		{
			return "1";
		}
		else if (card.at(i) == 'D' && card.at(i + 1) == 'e' && card.at(i + 2) == 'u')
		{
			return "2";
		}
		else if (card.at(i) == 'T' && card.at(i + 1) == 'h' && card.at(i + 2) == 'r')
		{
			return "3";
		}
		else if (card.at(i) == 'F' && card.at(i + 1) == 'o' && card.at(i + 2) == 'u')
		{
			return "4";
		}
		else if (card.at(i) == 'F' && card.at(i + 1) == 'i' && card.at(i + 2) == 'v')
		{
			return "5";
		}
		else if (card.at(i) == 'S' && card.at(i + 1) == 'i' && card.at(i + 2) == 'x')
		{
			return "6";
		}
		else if (card.at(i) == 'S' && card.at(i + 1) == 'e' && card.at(i + 2) == 'v')
		{
			return "7";
		}
		else if (card.at(i) == 'E' && card.at(i + 1) == 'i' && card.at(i + 2) == 'g')
		{
			return "8";
		}
		else if (card.at(i) == 'N' && card.at(i + 1) == 'i' && card.at(i + 2) == 'n')
		{
			return "9";
		}
		else if (card.at(i) == 'T' && card.at(i + 1) == 'e' && card.at(i + 2) == 'n')
		{
			return "10";
		}
	}
	return "?";
}
//converts a string to the appropriate form for a the suit of a card
string Graphics::convertSuit(string card) {
	for (unsigned int i = 0; i < card.size(); i++)
	{
		if (card.at(i) == 'D' && card.at(i + 1) == 'i' && card.at(i + 2) == 'a')
		{
			return "D";
		}
		else if (card.at(i) == 'H' && card.at(i + 1) == 'e' && card.at(i + 2) == 'a')
		{
			return "H";
		}
		else if (card.at(i) == 'C' && card.at(i + 1) == 'l' && card.at(i + 2) == 'u')
		{
			return "C";
		}
		else if (card.at(i) == 'S' && card.at(i + 1) == 'p' && card.at(i + 2) == 'a')
		{
			return "S";
		}
	}
	return "?";
}
