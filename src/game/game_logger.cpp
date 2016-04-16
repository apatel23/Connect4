#include "game.h"
#include <iostream>
#include "../board/ConnectFourBoard.h"

using namespace std;

void color_char(char a) {
  if( a == 'X') {
    cout << "\033[0;31mX\033[0m"; 
  } else if (a == 'O') {
    cout << "\033[0;34mO\033[0m"; 
  } else {
    cout << a;
  }
}



void Game::display_board() {
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
      cout << " ";
      color_char(theBoard->getPlayerAt( r, c )) ;
      cout << " |";
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