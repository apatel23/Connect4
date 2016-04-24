#include "simple_four.h"
#include <climits>

using namespace std;

const int ROWS = 6;
const int COLS = 7;

SimpleFour::SimpleFour(int threshold, bool thresh, int depth) {
  MAX_SCORE = INT_MAX;
  THRESHOLD = threshold;
  t_hold = thresh;
  DEPTH = depth;
  WINNER = false;
}


int SimpleFour::getresult(char results []) {

  int score = 0;

  if ( results[0] == results[1] && results[0] == results[2] && results[0] == results[3] && results[0] != ' ') {
    score += 500;
    WINNER = true;
  }


  if ( results[0] == results[1] && results[0] == results[2] && results[3] == ' ' && results[0] != ' ') {
    score += 10;
  }


  if ( results[0] == results[1] && results[0] != ' ') {
    score += 1;
  }

/*

  if ( results[0] == results[2] && results[0] == results[3] && results[1] == ' ' && results[0] != ' ') {
    score = 10;
  }


  if ( results[1] == results[2] && results[1] == results[3] && results[0] == ' ' && results[1] != ' ' ) {
    score += 10;
  }

*/


    if( results[0] == ' '){
      if( results[1] == 'X'){
        return score ;
      }else{
        return score * -1;
      }
    }else{
      if( results[0] == 'X'){
        return score  ;
      }else{
        return score * -1;
      }
    }


  return score;
}




int SimpleFour::getHeuristic(ConnectFourBoard bo) {
  int finalS = 0;
  int score = 0;
  char results [4];
  WINNER = false;

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