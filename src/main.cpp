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
#include <time.h>
using namespace std;  // We will almost always use the standard namespace.

#include "game/game.h"
#include "board/ConnectFourBoard.h"
#include "heuristic/heuristic.h"
#include "heuristic/simple_heuristic.h"
#include "heuristic/simple_two.h"
#include "flag_parser/flag_parser.h"
#include "player/computer_player/ComputerPlayer.h"
#include "player/human_player/HumanPlayer.h"

// Function prototypes
void gooey();
void console();


void run_test();


int main( int argc, char** argv)
{
	FlagOptions fo;
	if( !parse_flags(argc, argv, fo) ) {
		return EXIT_FAILURE;
	}

	srand(time(NULL));

/*
	ConnectFourBoard *theBoard = new ConnectFourBoard;

	Player* p_one;
	Player* p_two;

	Heuristic * h_one;
	Heuristic * h_two;


	Game g;


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

	g.construct_game(theBoard, p_one, p_two);
	g.play_game();
	
*/




	run_test();




	//g.construct_game(theBoard, p_one, p_two);
	//g.play_game();

	return EXIT_SUCCESS;
}


void run_test() {

	Player* p_one;
	Player* p_two;

	Heuristic * h_one;
	Heuristic * h_two;


	ConnectFourBoard *theBoard;

	ofstream ofs("simple_data_depths_2.txt");

	for( int i = 1; i <= 10; i+=1) {
		if( i > 1 && i % 2 != 0 ) continue;
		for( int j = 1; j <= 10; j+=1) {
			if( j > 1 && j % 2 != 0 ) continue;
			ofs << "Player 1 Depth: " << i << " ,Player 2 Depth: " << j << endl;
			for( int z = 0; z < 25; z++) {
				Game g;
				theBoard = new ConnectFourBoard;
				p_one = new ComputerPlayer(true, theBoard);
				p_two = new ComputerPlayer(false, theBoard);

				h_one = new SimpleHeuristic(29, false, i);
				h_two = new SimpleHeuristic(29,false,  j);

				p_one->setHeuristic(h_one);
				p_two->setHeuristic(h_two);

				g.construct_game(theBoard, p_one, p_two);
				g.play_game();


				char winner = theBoard->getWinner();
				if( winner == ' ' )
				{
					ofs << "-,0,";
				}
				else
				{
					ofs << winner << ",1,";
					
				}
				ofs << g.numMoves << endl;
				g.numMoves = 0;
				delete theBoard;
			}
			ofs << endl << endl;
		}
	}

	ofs.close();
}