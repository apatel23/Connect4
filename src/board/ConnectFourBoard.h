#pragma once

/*
 * This class represents the logic required to play a game of Connect Four.
 * 
 * 
 *        *************************************
 *        ****   DO NOT MODIFY THIS FILE   ****
 *        *************************************
 */
 struct ConnectFourBoard
 {
    // The dimensions of a standard Connect Four board.
    static const int ROWS = 6;
    static const int COLS = 7;

    // Constructs a new Connect Four Board object, ready for a new game.
    ConnectFourBoard();

    // Makes a move in the indicated column on the Connect Four board, returning true if successful.
    bool makeMove( int col , char currentPlayer);

    // This function returns true if the board is full; false otherwise.
    bool isFull() const;

    // This function returns 'X' or 'O' if there is a winner on the board; ' ' otherwise.
    char getWinner() const;

    // This function changes the current player.
    // void changePlayers();

    // This function retrieves the current player.
    // char getCurrentPlayer() const;

    // This function retrieves the player at the indicated position of the board,
    // or a space if the board location is currently unoccupied.
    char getPlayerAt( int row, int col ) const;

    // Two dimensional array of characters represents the current state of the board.
    char board[ ROWS ][ COLS ];
    // The board keeps track of the current player.
    // char currentPlayer;
};
