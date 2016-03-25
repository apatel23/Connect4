#pragma once

/*
 * This class represents the logic required to play a game of Connect Four.
 * 
 */
 struct ConnectFourBoard
 {
    // The dimensions of a standard Connect Four board.
    static const int ROWS = 6;
    static const int COLS = 7;

    // Constructs a new Connect Four Board object, ready for a new game.
    ConnectFourBoard();

    // Makes a move in the indicated column on the Connect Four board, returning true if successful.
    bool makeMove( int col , bool current_player);

    // This function returns true if the board is full; false otherwise.
    bool isFull() const;

    // This function returns 'X' or 'O' if there is a winner on the board; ' ' otherwise.
    char getWinner() const;

    // gets the location of the current player
    char getPlayerAt( int row, int col ) const;

    // setting player
    void set_player( bool current_player );

    // Two dimensional array of characters represents the current state of the board.
    char board[ ROWS ][ COLS ];

    // Bool which player
    char c_player;
};
