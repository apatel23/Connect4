#pragma once

#include "../board/ConnectFourBoard.h"
#include "../player/player.h"
#include "../player/computer_player/ComputerPlayer.h"
#include "../player/human_player/HumanPlayer.h"
#include "../heuristic/heuristic.h"
#include "../heuristic/simple_heuristic.h"


using namespace std;

struct Game {
	ConnectFourBoard *theBoard;
	bool IsPlayerOne = true;
	Player *playerone;
	Player *playertwo;

	Player *currentPlayer;

	// functions to build and create the board main.cpp
	void construct_game(ConnectFourBoard* B, Player* p_one, Player* p_two);
	void play_game();

	// helper functions defined in utils.cpp
	void changePlayers();
	bool makeMove( int col );
	bool isFull();
	Player * getWinner();
	Player * getCurrentPlayer();

	// functions for displaying the board, it is defined in the logger.cpp file
	void display_board();


};
