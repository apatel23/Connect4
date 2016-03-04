#include "ComputerPlayer.h"
#include "ConnectFourBoard.h"
#include <iostream>

using namespace std;

void ComputerPlayer::move(char Player, ConnectFourBoard &b) {
	// Show the current player and get a move.
    int move;
    cout << "Player " << Player  << ", enter a column (1-7): ";
    cin >> move;

    // Note: Not all users are CS majors, so they prefer columns 1-7, but we need a
    // zero-based array index. Thus, subtract one from move in the function call.

    // The makeMove function returns true if it successfully makes a move.
    // Stay in this loop until a successful move is entered and made.
    while( !b.makeMove( move - 1 ) )
    {
      // The makeMove functions returns true if it successfully makes a move.
      // Show an error and continue getting moves
      cout << "Invalid move. Please try again: ";
      cin >> move;
    }

}
  // return the utility of the given move
  float ComputerPlayer::getUtility(int column) {


    return 0;
  }

  // Defualt Constructor
  ComputerPlayer::ComputerPlayer() {


  }
