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
#include "heuristic/simple_three.h"
#include "heuristic/simple_four.h"

#include "flag_parser/flag_parser.h"
#include "player/computer_player/ComputerPlayer.h"
#include "player/human_player/HumanPlayer.h"

#include <ctime>

// Function prototypes
void gooey();
void console();


void run_test();
void run_test_two();
void run_test_three();
void run_test_four();

void run_test_time();

void run_test_time();


int main( int argc, char** argv)
{

	
	FlagOptions fo;
	if( !parse_flags(argc, argv, fo) ) {
		return EXIT_FAILURE;
	}

	srand(time(NULL));


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
	
	





	//run_test();
	//run_test_two();
	//run_test_three();
	//run_test_four();
	//run_test_time();




	//g.construct_game(theBoard, p_one, p_two);
	//g.play_game();

	return EXIT_SUCCESS;
}



void run_test_time() {

	Player* p_one;
	Player* p_two;

	Heuristic * h_one;
	Heuristic * h_two;


	ConnectFourBoard *theBoard;

	ofstream ofs("time_data_per_move_MinMax.txt");

	double avg_time = 0;


	for( int i = 1; i <= 9; i+=1) {
		//if( i > 1 && i % 2 != 0 ) continue;

			//ofs << "Simple_1 vs. Simple_2 Depth: " << i << endl;
			for( int z = 0; z < 5; z++) {
				Game g;
				theBoard = new ConnectFourBoard;
				p_one = new ComputerPlayer(true, theBoard);
				p_two = new ComputerPlayer(false, theBoard);

				h_one = new SimpleHeuristic(29, false, i);
				h_two = new SimpleHeuristic(29,false,  1);

				p_one->setHeuristic(h_one);
				p_two->setHeuristic(h_two);

				g.construct_game(theBoard, p_one, p_two);


				clock_t begin = clock();
				g.play_game();
				clock_t end = clock();

				double elapsed_time = double(end - begin) / CLOCKS_PER_SEC;

				avg_time += elapsed_time/g.numMoves;

				delete theBoard;
			}

			avg_time = avg_time /10;
			ofs << i << "," << avg_time << endl;
			avg_time = 0;
	}

}




void run_test() {

	Player* p_one;
	Player* p_two;

	Heuristic * h_one;
	Heuristic * h_two;


	ConnectFourBoard *theBoard;

	ofstream ofs("simple_depth.txt");

	for( int i = 1; i <= 10; i+=1) {
		if( i > 1 && i % 2 != 0 ) continue;
		for( int j = 1; j <= 10; j+=1) {
			if( j > 1 && j % 2 != 0 ) continue;
			//ofs << "Player 1 Depth: " << i << " ,Player 2 Depth: " << j << endl;
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

void run_test_two() {

	Player* p_one;
	Player* p_two;

	Heuristic * h_one;
	Heuristic * h_two;


	ConnectFourBoard *theBoard;

	ofstream ofs("simple1_simple2.txt");

	for( int i = 1; i <= 10; i+=1) {
		if( i > 1 && i % 2 != 0 ) continue;

			ofs << "Simple_1 vs. Simple_2 Depth: " << i << endl;
			for( int z = 0; z < 25; z++) {
				Game g;
				theBoard = new ConnectFourBoard;
				p_one = new ComputerPlayer(true, theBoard);
				p_two = new ComputerPlayer(false, theBoard);

				h_one = new SimpleHeuristic(29, false, i);
				h_two = new SimpleTwo(29,false,  i);

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
			ofs << "Simple_2 vs. Simple_1 Depth: " << i << endl;
			for( int z = 0; z < 25; z++) {
				Game g;
				theBoard = new ConnectFourBoard;
				p_one = new ComputerPlayer(true, theBoard);
				p_two = new ComputerPlayer(false, theBoard);

				h_one = new SimpleHeuristic(29, false, i);
				h_two = new SimpleTwo(29,false,  i);

				p_one->setHeuristic(h_one);
				p_two->setHeuristic(h_two);

				g.construct_game(theBoard, p_two, p_one);
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

	ofs.close();
}

void run_test_three() {
	Player* p_one;
	Player* p_two;

	Heuristic * h_one;
	Heuristic * h_two;


	ConnectFourBoard *theBoard;

	ofstream ofs("simple1_simple3.txt");

	for( int i = 1; i <= 10; i+=1) {
		if( i > 1 && i % 2 != 0 ) continue;

			ofs << "Simple_1 vs. Simple_3 Depth: " << i << endl;
			for( int z = 0; z < 25; z++) {
				Game g;
				theBoard = new ConnectFourBoard;
				p_one = new ComputerPlayer(true, theBoard);
				p_two = new ComputerPlayer(false, theBoard);

				h_one = new SimpleHeuristic(29, false, i);
				h_two = new SimpleThree(29,false,  i);

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
			ofs << "Simple_3 vs. Simple_1 Depth: " << i << endl;
			for( int z = 0; z < 25; z++) {
				Game g;
				theBoard = new ConnectFourBoard;
				p_one = new ComputerPlayer(true, theBoard);
				p_two = new ComputerPlayer(false, theBoard);

				h_one = new SimpleHeuristic(29, false, i);
				h_two = new SimpleThree(29,false,  i);

				p_one->setHeuristic(h_one);
				p_two->setHeuristic(h_two);

				g.construct_game(theBoard, p_two, p_one);
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

	ofs.close();
}


void run_test_four() {
	Player* p_one;
	Player* p_two;

	Heuristic * h_one;
	Heuristic * h_two;


	ConnectFourBoard *theBoard;

	ofstream ofs("simple1_simple4.txt");

	for( int i = 1; i <= 10; i+=1) {
		if( i > 1 && i % 2 != 0 ) continue;

			ofs << "Simple_1 vs. Simple_4 Depth: " << i << endl;
			for( int z = 0; z < 25; z++) {
				Game g;
				theBoard = new ConnectFourBoard;
				p_one = new ComputerPlayer(true, theBoard);
				p_two = new ComputerPlayer(false, theBoard);

				h_one = new SimpleHeuristic(29, false, i);
				h_two = new SimpleFour(29,false,  i);

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
			ofs << "Simple_4 vs. Simple_1 Depth: " << i << endl;
			for( int z = 0; z < 25; z++) {
				Game g;
				theBoard = new ConnectFourBoard;
				p_one = new ComputerPlayer(true, theBoard);
				p_two = new ComputerPlayer(false, theBoard);

				h_one = new SimpleHeuristic(29, false, i);
				h_two = new SimpleFour(29,false,  i);

				p_one->setHeuristic(h_one);
				p_two->setHeuristic(h_two);

				g.construct_game(theBoard, p_two, p_one);
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

	ofs.close();
}

