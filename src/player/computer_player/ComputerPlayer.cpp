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
  Node * nn = new Node;
  runAlgorithm( nn );
  //checkNode(nn, board, true)
  int move = findBestnode(nn);
  //cout << "Will make the best move with the following " << move << endl;
  //cout << "Analyze(9)" << endl;
  //int an;
  //cin >> an;
  //cin.ignore();
  //if( an == 9 ) {
  //  checkNode(nn, board, true);
  //}
/*
  if( move == -1 ) {
    if( b->makeMove(3, Player) ) {
      return;
    }
    if( b->makeMove(2, Player) ) {
      return;
    }
    if( b->makeMove(4, Player) ) {
      return;
    }

  }
*/


  b->makeMove(move, Player);
  //cout << "Will make the best move with the following " << move << endl;
}
  // return the utility of the given move
float ComputerPlayer::getUtility(int column) {
  return 0;
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
  cout << "Best node: " << findBestnode(node) << endl;
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
  //setDepth(heuristic->DEPTH);
  //runAlgorithm(root);
  //n = root;
  //checkNode(root, board, true);
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
  result = heuristic->getHeuristic(b);
  
  if( heuristic->t_hold ) {
    if( MaxPlayer ) {
      if( result < -1 * heuristic->THRESHOLD) {
        node->data = result;
        return result;
      }
    } else {
      if(result > heuristic->THRESHOLD ) {
        node->data = result;
        return result;
      }
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
      node->nodes[i]->valid = false;
      continue;
    }


    result = heuristic->getHeuristic(bo);
    if ( result >= heuristic->WINNER ) {
      foundWinner = true;
    }

    if( foundWinner ) {
      node->nodes[i]->data = heuristic->WINNER;
      v = heuristic->WINNER;
      break;
    }

      v = max(v, AlphaBeta(node->nodes[i], bo, depth_run - 1, Alpha, Beta, false) /* + result */);
      Alpha = max(Alpha, v);
      
      
      if( Beta <= Alpha) {
        break;
      }
      

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
        node->nodes[i]->valid = false;
        continue;
      }

    result = heuristic->getHeuristic(bo);
    if ( result <= -1 * heuristic->WINNER) {
      foundWinner = true;
    }

    if( foundWinner ) {
      node->nodes[i]->data = -1 * heuristic->WINNER;
      v = -1 * heuristic->WINNER;
      break;
    }

      v = min(v, AlphaBeta(node->nodes[i], bo, depth_run - 1, Alpha, Beta, true) /*+ result */);
      Beta = min(Beta, v);
      
      
      
      if( Beta <= Alpha) {
        break;
      }
      

    }
    node->data = v;
    return v; 
  }

}



void ComputerPlayer::runAlgorithm(Node * b){
  setDepth(heuristic->DEPTH);
  root->data = AlphaBeta(b, board, depth - 1, loss, win, Player );
}
