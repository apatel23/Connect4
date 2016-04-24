#include "ComputerPlayer.h"
//#include "ConnectFourBoard.h"
#include <iostream>
#include <algorithm>
#include "logger_node.h"
#include <climits>


using namespace std;

int win = 100;
int loss = -100;
const int DEPTH_TOTAL = 10;

const int ROWS = 6;
const int COLS = 7;


void ComputerPlayer::setHeuristic(Heuristic * h) {
  heuristic = h;
}

void ComputerPlayer::move(ConnectFourBoard * b) {

  if( firstMove ) {
    b->makeMove(3, Player);
    firstMove = false;
    return;
  }


  board = *b;
  setDepth(heuristic->DEPTH);
  int move = AlphaBeta(board, depth , loss, win, Player );

  //cout << "Move: " << move << endl;


  while( !b->makeMove(move, Player) ) {
    move = rand()% COLS;
  }
}



// setting the depth of the search
void ComputerPlayer::setDepth(int depth) {
  this->depth = depth;
}


int ComputerPlayer::findBestnode(Node * n) {
  int a = 0;
  double max = INT_MIN;
  double min = INT_MAX;
  if (n->nodes == nullptr) return a;
  for(int i = 0; i < 7; i++) {
    if( n->nodes[i] == nullptr) {
      continue;
    }
    if( Player ) {
      if(n->nodes[i]->data > max && n->nodes[i]->valid){
        max = n->nodes[i]->data;
        a = i;
        cout << "Node: " << i << " Value: " << n->nodes[i]->data << endl; ////////////////////////////////////////////////////////////////////////
      }
    } else {
      if(n->nodes[i]->data < min && n->nodes[i]->valid){
        min = n->nodes[i]->data;
        a = i;
      }
    }
  }
/*
  if( a == 0 && max == 0) {
    return -1;
  }
*/
  return a;
}



  // Defualt Constructor
ComputerPlayer::ComputerPlayer(bool Player, ConnectFourBoard *b) {
  this->Player = Player;
  root = new Node;
  board = *b;
}






int ComputerPlayer::AlphaBeta(ConnectFourBoard b, int depth_run, int Alpha, int Beta, bool MaxPlayer) {

  /*
  // Check to see if terminal node by making an attemp to find a winner
  // by checking the board configuration for winner and loosers
  // Also if at depth 0 will return null since it has yet to find the optimal path
  */
  int i;
  bool madeMove;
  int result = 0;
  int desired_move = -1;
  int prune;
  ConnectFourBoard bo;

  // if at the end of the search
  result = heuristic->getHeuristic(b);
  
  if( heuristic->t_hold ) {
    if( MaxPlayer ) {
      if( result < -1 * heuristic->THRESHOLD) {
        return result;
      }
    } else {
      if(result > heuristic->THRESHOLD ) {
        return result;
      }
    }
  }
  
  
  

  if ( depth_run == 0 ) {
    return result;
  }
  result = 0;



  //node->addNode(MaxPlayer);

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


    result = heuristic->getHeuristic(bo);



    if( heuristic->WINNER ) {
      desired_move = i;
      v = heuristic->MAX_SCORE;
      break;
    }

      prune = AlphaBeta(bo, depth_run - 1, Alpha, Beta, false);
      if( v < prune ) {
        desired_move = i;
        v = prune;
      }
      Alpha = max(Alpha, v);
      
      
      if( Beta <= Alpha) {
        desired_move = i;
        break;
      }
      

    }
  } else {
    v = win;
    for( i = 0; i < COLS; i++) {
      bo = b;
      madeMove = bo.makeMove(i, MaxPlayer);
      // check to see if a move was made it would be false if a certain column is full
      if( !madeMove ) {
        continue;
      }

    result = heuristic->getHeuristic(bo);
    


    if( heuristic->WINNER ) {
      desired_move = i;
      v = -1 * heuristic->MAX_SCORE;
      break;
    }

      prune = AlphaBeta(bo, depth_run - 1, Alpha, Beta, true);
      if( v > prune ) {
        desired_move = i;
        v = prune;
      }
      Beta = min(Beta, v);
      
      
      
      if( Beta <= Alpha) {
        desired_move = i;
        break;
      }
      

    }
  }

  if( depth == depth_run ) {
    return desired_move;
  }

  return v;

}

