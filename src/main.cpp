/* CSCI 261: Homework 11 - Connect Four
 *
 * Co-Author: Daniel Zarrini - dzarrini
 *
 * Co-Author: Alex Patel - patel
 *
 * The main program runs console based version of Connect Four.
 *
 * This file also contains the definitions of the ConnectFourBoard methods so
 * only the main.cpp file needs to be submitted when the homework is complete.
 * (Normally there would be a ConnectFourBoard.cpp file, but we are working
 * within the limitations of the Blackboard homework submission page.)
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

// Function prototypes
void gooey();
void console();

int main()
{
	//console();
	//Game::play_game();
	Game g;
	g.play_game();

	return EXIT_SUCCESS;
}
