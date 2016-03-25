#include "ComputerPlayer.h"
//#include "ConnectFourBoard.h"
#include <iostream>


using namespace std;

int win = 1;
int loss = -1;

void ComputerPlayer::move(ConnectFourBoard * b) {
	// Show the current player and get a move.
  int move;
  cout << "Player " << Player  << ", enter a column (1-7): ";
  cin >> move;

    // Note: Not all users are CS majors, so they prefer columns 1-7, but we need a
    // zero-based array index. Thus, subtract one from move in the function call.

    // The makeMove function returns true if it successfully makes a move.
    // Stay in this loop until a successful move is entered and made.
  while( !b->makeMove( move - 1, Player ) )
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
ComputerPlayer::ComputerPlayer(bool Player, ConnectFourBoard *b) {
  this->Player = Player;
  root = nullptr;
  board = *b;
}
/*
int ComputerPlayer::AlphaBeta(Node * node, ConnectFourBoard b, int depth, int Alpha, int Beta, bool MaxPlayer, char Player) {
  
  // used for itterations
  int i;
  for( i = 1; i <= 8; i++) {
    ConnectFourBoard bo = *b;
    bo.makeMove(i, Player);
    if( bo.getWinner() != ' ' ) {

      break;
    } else {
      if ( MaxPalyer ) {
        node->addNode( i - 1, win);
      } else {
        nod->addNode( i - 1, loss);
      }
    }

  }




  if ( depth == 0 ) {
    return 0;
  } 
}
*/
