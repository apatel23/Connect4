/*
 * The console function in this file uses the ConnectFourBoard class
 * to play a console-based, text version of the Connect Four game.
 */
#include <iostream>
 using namespace std;

#include "data/ConnectFourBoard.h"
#include "data/HumanPlayer.h"
#include "data/ComputerPlayer.h"

// Function prototypes
 void display( ConnectFourBoard board );

/*
 *        *************************************
 *        **** DO NOT MODIFY THIS FUNCTION ****
 *        *************************************
 */
 void console()
 {
  // Create the board and show it for the first time.
  ConnectFourBoard theBoard;
  display( theBoard );

  // The game continues until there is a winner or the board is full.
  while( theBoard.getWinner() == ' ' && !theBoard.isFull() )
  {
    if( theBoard.getCurrentPlayer() == 'X') {
    HumanPlayer::move(theBoard.getCurrentPlayer(), theBoard);
    // A move was successfully made, so change players and re-draw the board.
    } else {
    ComputerPlayer::move(theBoard.getCurrentPlayer(), theBoard);
    // A move was successfully made, so change players and re-draw the board.
    }
    theBoard.changePlayers();
    display( theBoard );
  }

  // Game is over ... show the results.
  char winner = theBoard.getWinner();
  if( winner == ' ' )
  {
    cout << "Tie game." << endl;
  }
  else
  {
    cout << "Player " << winner << " wins!" << endl;
  }
}


void display( ConnectFourBoard board )
{
  // Print a bunch of newline characters so the board is
  // always at the bottom of the window. If it prints/scrolls
  // fast enough, it will almost look like it draws in place.
  // Why 16? Your console window may need more ... or less ...
  for( int i = 0; i < 16; i++ )  cout << endl;

  // Draw column headers (starting at 1 because not all
  // Connect Four players are Computer Science majors).
    cout << " ";
  for( int c = 1; c <= ConnectFourBoard::COLS; c++ )
  {
    cout << " " << c << "  ";
  }
  cout << endl;

  // Print the contents of the board with some separating characters.
  for( int r = 0; r < ConnectFourBoard::ROWS; r++ )
  {
    // Draw a row of column separators.
    cout << "|";
    for( int c = 1; c <= ConnectFourBoard::COLS; c++ )
    {
      cout << "   |";
    }
    cout << endl;

    // Draw a row of actual data, with column separators.
    cout << "|";
    for( int c = 0; c < ConnectFourBoard::COLS; c++ )
    {
      cout << " " << board.getPlayerAt( r, c ) << " |";
    }
    cout << endl;

    // Draw a row of column separators.
    cout << "|";
    for( int c = 1; c <= ConnectFourBoard::COLS; c++ )
    {
      cout << "   |";
    }
    cout << endl;

    // Draw the row separator.
    cout << "+";
    for( int c = 1; c <= ConnectFourBoard::COLS; c++ )
    {
      cout << "---+";
    }
    cout << endl;
  }
  cout << endl;
}
