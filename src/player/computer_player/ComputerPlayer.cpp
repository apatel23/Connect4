#include "ComputerPlayer.h"
//#include "ConnectFourBoard.h"
#include <iostream>
#include <algorithm>
#include "logger_node.h"


using namespace std;

int win = 1;
int loss = -1;
const int DEPTH_TOTAL = 8;

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


// setting the depth of the search
void ComputerPlayer::setDepth(int depth) {
  this->depth = depth;
}


  // Defualt Constructor
ComputerPlayer::ComputerPlayer(bool Player, ConnectFourBoard *b) {
  this->Player = Player;
  root = new Node;
  board = *b;
  setDepth(DEPTH_TOTAL);
  runAlgorithm();
}

void addNode(Node * node, int i, bool MaxPlayer, bool winner) {
  if(win) {
    if( MaxPlayer) {
      node->addNode( i, win);
    }else {
      node->addNode( i , loss);
    }
  } else {
    node->addNode( i , 0);
  }
}


void prints(int i) {
  cout << i << endl;
}

int ComputerPlayer::AlphaBeta(Node * node, ConnectFourBoard b, int depth_run, int Alpha, int Beta, bool MaxPlayer) {

  /*
  // Check to see if terminal node by making an attemp to find a winner
  // by checking the board configuration for winner and loosers
  // Also if at depth 0 will return null since it has yet to find the optimal path
  */
  int i;
  bool madeMove;
  bool foundWinner = false;
  ConnectFourBoard bo;
  //prints(1);
  for( i = 0; i < 7; i++) {
    bo = b;
    madeMove = bo.makeMove(i, MaxPlayer);
    //prints(1);
    // check to see if a move was made it would be false if a certain column is full
    if( !madeMove ) {
      continue;
    }
    // logger_node::print_board(bo);
    // check to see if found winner
    if ( bo.getWinner() != ' ') {
      foundWinner = true;
      addNode(node, i, MaxPlayer, true);
      break;
    } else {
      addNode(node, i, MaxPlayer, false);
    }
  }

  if( foundWinner ) {
    logger_node::print_board(bo);
    if (MaxPlayer) {
      return 1;
    } else {
      return -1;
    }
  }


    
  //prints(2);
  // if at the end of the search
  if ( depth_run == 0 ) {
  //prints(2);
    if (MaxPlayer) {
      return 1;
    } else {
      return -1;
    }
  }
  // cout << "Tommy" << endl;
  //prints(1);


  int v;
  if( MaxPlayer ) {
    v = -1;
    for( i = 0; i < 7; i++) {
    bo = b;
    madeMove = bo.makeMove(i, MaxPlayer);
    // check to see if a move was made it would be false if a certain column is full
    if( !madeMove ) {
      continue;
    }
      v = max(v, AlphaBeta(node->nodes[i], bo, depth_run - 1, Alpha, Beta, false));
      Alpha = max(Alpha, v);
      if( Beta <= Alpha) {
        break;
      }
    }
    // cout << "Max";
    // cout << depth_run << endl;
    return v;
  } else {
    v = 1;
    for( i = 0; i < 7; i++) {
      bo = b;
      madeMove = bo.makeMove(i, MaxPlayer);
      // check to see if a move was made it would be false if a certain column is full
      if( !madeMove ) {
        continue;
      }
      // cout << "ali" << endl;
      // cout << depth_run << endl;
      v = min(v, AlphaBeta(node->nodes[i], bo, depth_run - 1, Alpha, Beta, true));
      //cout << "dan" << endl;
      Beta = min(Beta, v);
      if( Beta <= Alpha) {
        break;
      }
    }
    // cout << "Min";
    // cout << depth_run << endl;
    return v; 
  }

}

void ComputerPlayer::runAlgorithm(){
  cout << "Tom" << endl;
  AlphaBeta(root, board, depth - 1, -1, 1, true );
  cout << "Jerry" << endl; 
}
