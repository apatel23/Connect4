#include "ConnectFourBoard.h"

using namespace std;

/*
 * Makes a move in the indicated column on the Connect Four board.
 * 
 * The function must ensure col is a valid column and that the column is not full.
 * The value of currentPlayer is then placed in the top-most empty row.
 * 
 * The function returns true if a valid move was made; false otherwise;
 */
 bool ConnectFourBoard::makeMove( int col , char currentPlayer)
 {
 	if ( col >= 0 && col < COLS )
 	{
 		for ( int i = ROWS - 1; i >= 0 ; --i)
 		{
 			if ( board[ i] [col ] == ' ' )
 			{
 				board[i][col] = currentPlayer;
 				return true;
 			}
 		}
 	}

  // Could not make this move, so return false.
 	return false;
 }

/*
 * This function returns true if the board is full; false otherwise.
 * 
 * Since all moves go to the lowest unoccupied row, the function only
 * needs to look at the top row of each column for an empty space.
 */
 bool ConnectFourBoard::isFull() const {
 	for ( int i = 0 ; i < COLS ; i++ )
 	{
 		if ( board[ 0 ][i] == ' ' )
 		{
 			return false;
 		}
 	}

 	return true; 
 }

/*
 * This function returns 'X' or 'O' if there is a winner on the board; ' ' otherwise.
 * 
 * The function must check all possible locations where four consecutive values
 * could be equal (and not spaces) and return true if it finds such a location.
 * If it finishes all of these tests without finding four consecutive locations
 * that match, it will return false.
 */
 char ConnectFourBoard::getWinner() const {
 	for( int r = 0; r < ROWS; r++ )
 	{
 		for( int c = 0; c < COLS - 3; c++ )
 		{
 			if( board[ r ][ c ] != ' '  && 
 				board[ r ][ c ] == board[ r ][ c + 1 ] && 
 				board[ r ][ c ] == board[ r ][ c + 2 ] &&
 				board[ r ][ c ] == board[ r ][ c + 3 ]
 				)
 			{
 				return board[ r ][ c ];
 			}
 		}
 	}


 	for( int r = 0; r < ROWS - 3; r++ )
 	{
 		for( int c = 0; c < COLS; c++ )
 		{
 			if( board[ r ][ c ] != ' '  && 
 				board[ r ][ c ] == board[ r + 1 ][ c ] && 
 				board[ r ][ c ] == board[ r + 2 ][ c ] &&
 				board[ r ][ c ] == board[ r + 3 ][ c ]
 				)
 			{
 				return board[ r ][ c ];
 			}
 		}
 	}

 	for( int r = 0; r < ROWS - 3; r++ )
 	{
 		for( int c = 0; c < COLS - 3; c++ )
 		{
 			if( board[ r ][ c ] != ' '  && 
 				board[ r ][ c ] == board[ r + 1 ][ c + 1 ] && 
 				board[ r ][ c ] == board[ r + 2 ][ c + 2 ] &&
 				board[ r ][ c ] == board[ r + 3 ][ c + 3 ]
 				)
 			{
 				return board[ r ][ c ];
 			}
 		}
 	}

 	for( int r = 0; r < ROWS - 3; r++ )
 	{
 		for( int c = 3; c < COLS; c++ )
 		{
 			if( board[ r ][ c ] != ' '  && 
 				board[ r ][ c ] == board[ r + 1 ][ c - 1 ] && 
 				board[ r ][ c ] == board[ r + 2 ][ c - 2 ] &&
 				board[ r ][ c ] == board[ r + 3 ][ c - 3 ]
 				)
 			{
 				return board[ r ][ c ];
 			}
 		}
 	}

  return ' ';  // Didn't find a winner so return a space.
}





/* void ConnectFourBoard::changePlayers() {

 	currentPlayer = ( currentPlayer == 'X' ) ? 'O' : 'X';

 }


 char ConnectFourBoard::getCurrentPlayer() const {
 	return currentPlayer;
 }

*/
 char ConnectFourBoard::getPlayerAt( int row, int col ) const {
  // Make sure not to go out of bounds of the array.
 	if( row >= 0 && row < ROWS && col >= 0 && col < COLS )
 	{
 		return board[ row ][ col ];
 	}

  // The code above should return a value from the board array.
  // If it doesn't, return something here to signal an error.
 	return '!';
 }



/*
 * Constructs a new Connect Four Board object, ready for a new game.
 */
 ConnectFourBoard::ConnectFourBoard() {
  // Initialize the board array to all spaces.
 	for( int r = 0; r < ROWS; r++ )
 	{
 		for( int c = 0; c < COLS; c++ )
 		{
 			board[ r ][ c ] = ' ';
 		}
 	}

  // Player X always goes first.
  // currentPlayer = 'X';
 }
