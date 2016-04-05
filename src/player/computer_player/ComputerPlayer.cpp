#include "ComputerPlayer.h"
//#include "ConnectFourBoard.h"
#include <iostream>
#include <algorithm>
#include "logger_node.h"


using namespace std;

int win = 100;
int loss = -100;
const int DEPTH_TOTAL = 10;
const int ROWS = 6;
const int COLS = 7;

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


void ComputerPlayer::checkNode(Node * node) {
  
  for( size_t a = 0; a < COLS; a++) {
    if( node->nodes[a] != nullptr) {
      cout << "Node: " << a << " Data: " << node->nodes[a]->data << endl;
    }
  }
  cout << endl;

  int i;
  cout << "Enter what node values you would like to see" << endl;
  cin >> i;
  cin.ignore();
  if( i == -1) {
    return;
  }
  cout << "Node " << i << endl;
  checkNode(node->nodes[i]);
}

  // Defualt Constructor
ComputerPlayer::ComputerPlayer(bool Player, ConnectFourBoard *b) {
  this->Player = Player;
  root = new Node;
  board = *b;
  setDepth(DEPTH_TOTAL);
  runAlgorithm();
  checkNode(root);
}

void addNode(Node * node, int i, bool MaxPlayer, bool winner) {
  if(winner) {
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
  int result = 0;
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
      // addNode(node, i, MaxPlayer, false);
      result = getHeuristic(bo);
      if( result != 0 ) {
        //logger_node::print_board(bo);
        node->addNode(i, result);
      }else {
        addNode(node, i, MaxPlayer, false);
      }
    }


  }


  // checks to find winner
  if( foundWinner ) {
    //logger_node::print_board(bo);
    if (MaxPlayer) {
      return 1;
    } else {
      return -1;
    }
  }

/*
  int result = getHeuristic(bo);

  if( result != 0 ) {
    logger_node::print_board(bo);
    return result;
  }
*/

    
  //prints(2);
  // if at the end of the search
  if ( depth_run == 0 ) {
  //prints(2);
    /*
    if (MaxPlayer) {
      return 1;
    } else {
      return -1;
    }
    */
  


    if (MaxPlayer) {
      return 0;
    } else {
      return 0;
    }

  }
  // cout << "Tommy" << endl;
  //prints(1);


  int v;
  if( MaxPlayer ) {
    v = -1;
    for( i = 0; i < COLS; i++) {
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
    node->data = v;
    return v;
  } else {
    v = 1;
    for( i = 0; i < COLS; i++) {
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
    node->data = v;
    return v; 
  }

}

void ComputerPlayer::runAlgorithm(){
  cout << "Tom" << endl;
  AlphaBeta(root, board, depth - 1, -1, 1, true );
  cout << "Jerry" << endl; 
}




int getresult(char results []) {

  int score = 0;

  if ( results[0] == results[1] && results[0] == results[2] && results[3] == ' ' && results[0] != ' ') {
    score = 3;
  }

  if ( results[0] == results[1] && results[0] == results[3] && results[2] == ' ' && results[0] != ' ') {
    score = 3;
  }

  if ( results[0] == results[2] && results[0] == results[3] && results[1] == ' ' && results[0] != ' ') {
    score = 3;
  }

  if ( results[1] == results[2] && results[1] == results[3] && results[0] == ' ' && results[1] != ' ' ) {
    score = 3;
  }

  if( score > 0 ) {
    if( results[0] == ' '){
      if( results[1] == 'X'){
        return score;
      }else{
        score = score * -1;
      }
    }else{
      if( results[0] == 'X'){
        return score;
      }else{
        score = score * -1;
      }
    }
  }

  return score;
}


int ComputerPlayer::getHeuristic( ConnectFourBoard bo) {

  int finalS = 0;
  int score = 0;
  char results [4];

  for( int r = 0; r < ROWS; r++ )
  {
    for( int c = 0; c < COLS - 3; c++ )
    {
      results[0] = bo.board[ r ][ c ];
      results[1] = bo.board[ r ][ c + 1];
      results[2] = bo.board[ r ][ c + 2];
      results[3] = bo.board[ r ][ c + 3];
      score = getresult(results);
      finalS += score;
    }
  }


  for( int r = 0; r < ROWS - 3; r++ )
  {
    for( int c = 0; c < COLS; c++ )
    {
      results[0] = bo.board[ r ][ c ];
      results[1] = bo.board[ r + 1][ c ];
      results[2] = bo.board[ r + 2][ c ];
      results[3] = bo.board[ r + 3][ c ];
      score = getresult(results);
      finalS += score;
    }
  }

  for( int r = 0; r < ROWS - 3; r++ )
  {
    for( int c = 0; c < COLS - 3; c++ )
    {
      results[0] = bo.board[ r ][ c ];
      results[1] = bo.board[ r + 1 ][ c + 1 ];
      results[2] = bo.board[ r + 2 ][ c + 2 ];
      results[3] = bo.board[ r + 3 ][ c + 3 ];
      score = getresult(results);
      finalS += score;
    }
  }

  for( int r = 0; r < ROWS - 3; r++ )
  {
    for( int c = 3; c < COLS; c++ )
    {
      results[0] = bo.board[ r ][ c ];
      results[1] = bo.board[ r + 1 ][ c - 1 ];
      results[2] = bo.board[ r + 2 ][ c - 2 ];
      results[3] = bo.board[ r + 3 ][ c - 3 ];
      score = getresult(results);
      finalS += score;
    }
  }

  return finalS;  // Didn't find a winner so return a space.
}