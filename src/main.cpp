/* CSCI 498: Game Theory - Connect Four
 *
 * Co-Author: Daniel Zarrini - dzarrini
 *
 * Co-Author: Alex Patel - patel
 *
 */
#include <iostream>   // For cin, cout, endl, etc.
#include <fstream>    // For file i/o.
#include <iomanip>    // Output formatting
#include <cstdlib>    // Standard library
#include <string>     // The string class
#include <cmath>      // Standard math functions
#include <ctime>      // To use the system clock
using namespace std;  // We will almost always use the standard namespace.

#include "game/game.h"
#include "board/ConnectFourBoard.h"
#include "heuristic/heuristic.h"
#include "heuristic/simple_heuristic.h"
#include "flag_parser/flag_parser.h"
#include "player/computer_player/ComputerPlayer.h"
#include "player/human_player/HumanPlayer.h"

// Function prototypes
void gooey();
void console();



int main( int argc, char** argv)
{
	FlagOptions fo;
	if( !parse_flags(argc, argv, fo) ) {
		return EXIT_FAILURE;
	}

	ConnectFourBoard *theBoard = new ConnectFourBoard;

	Player* p_one;
	Player* p_two;

	Heuristic * h_one;
	Heuristic * h_two;

	if( fo.strategy == HeuristicStrategy::SIMPLE) {
		h_one = new SimpleHeuristic(29, false, fo.max_depth);
	}

	if( fo.whovwho == WhoVWho::PvP) {
		p_one = new HumanPlayer(true, theBoard);
		p_two = new HumanPlayer(false, theBoard);
	} else if (fo.whovwho == WhoVWho::CvP) {
		p_one = new ComputerPlayer(true, theBoard);
		p_two = new HumanPlayer(false, theBoard);

		p_one->setHeuristic(h_one);

	} else {
		int d_two;
		cout << "Depth Search for Computer Player 2: ";
		cin >> d_two;
		cin.ignore();
		h_two = new SimpleHeuristic(29, false, d_two);

		p_one = new ComputerPlayer(true, theBoard);
		p_two = new ComputerPlayer(false, theBoard);

		p_one->setHeuristic(h_one);
		p_two->setHeuristic(h_two);

	}

	//console();
	//Game::play_game();
	Game g;
	g.construct_game(theBoard, p_one, p_two);
	g.play_game();

	return EXIT_SUCCESS;
}
