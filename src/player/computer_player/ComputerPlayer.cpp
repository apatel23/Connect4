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


void ComputerPlayer::checkNode(Node * node, ConnectFourBoard b, bool ply) {


  if( node->nodes == nullptr ) {
    return;
  }
  
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


  b.makeMove(i , ply);
  logger_node::print_board(b);


  cout << "Node " << i << endl;
  checkNode(node->nodes[i], b, !ply);
}

  // Defualt Constructor
ComputerPlayer::ComputerPlayer(bool Player, ConnectFourBoard *b) {
  this->Player = Player;
  root = new Node;
  board = *b;
  setDepth(DEPTH_TOTAL);
  runAlgorithm();
  checkNode(root, board, true);
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

  // if at the end of the search
  result = getHeuristic(b);

  if( MaxPlayer ) {
    if( result < 0) {
      node->data = result;
      return result;
    }
  } else {
    if(result > 0 ) {
      node->data = result;
      return result;
    }
  }

  if ( depth_run == 0 ) {
    node->data = result;
    return result;
  }
  result = 0;



  node->addNode(MaxPlayer);

  int v;
  if( MaxPlayer ) {
    v = loss;

    for( i = 0; i < COLS; i++) {
    bo = b;
    madeMove = bo.makeMove(i, MaxPlayer);
    // check to see if a move was made it would be false if a certain column is full
    if( !madeMove ) {
      continue;
    }

    if ( bo.getWinner() != ' ') {
      foundWinner = true;
    }

    result = getHeuristic(bo);
    if ( result > 100) {
      foundWinner = true;
    }

    if( foundWinner ) {
      node->nodes[i]->data = 100;
      v = 100;
      break;
    }

      v = max(v, AlphaBeta(node->nodes[i], bo, depth_run - 1, Alpha, Beta, false) + result);
      Alpha = max(Alpha, v);
      
      /*
      if( Beta < Alpha) {
        break;
      }
      */
      
      
      
    }
    node->data = v;
    return v;
  } else {
    v = win;
    for( i = 0; i < COLS; i++) {
      bo = b;
      madeMove = bo.makeMove(i, MaxPlayer);
      // check to see if a move was made it would be false if a certain column is full
      if( !madeMove ) {
        continue;
      }

    result = getHeuristic(bo);
    if ( result < -100) {
      foundWinner = true;
    }

    if( foundWinner ) {
      node->nodes[i]->data = -100;
      v = -100;
      break;
    }

      v = min(v, AlphaBeta(node->nodes[i], bo, depth_run - 1, Alpha, Beta, true) + result);
      Beta = min(Beta, v);
      
      /*
      if( Beta < Alpha) {
        break;
      }
      */
      
      
    }
    node->data = v;
    return v; 
  }

}

void ComputerPlayer::runAlgorithm(){
  cout << "Tom" << endl;
  root->data = AlphaBeta(root, board, depth - 1, loss, win, true );
  cout << "Jerry" << endl; 
}

int getresult(char results []) {

  int score = 0;

  if ( results[0] == results[1] && results[0] == results[2] && results[0] == results[3] && results[0] != ' ') {
    score = 100;
  }


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
        return score ;//* -1;
      }else{
        return score * -1;
      }
    }else{
      if( results[0] == 'X'){
        return score  ;//* -1;
      }else{
        return score * -1;
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