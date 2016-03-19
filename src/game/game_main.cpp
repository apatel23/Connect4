#include "game.h"
#include <iostream>

using namespace std;

void Game::construct_game(){
	theBoard = new ConnectFourBoard;
	playerone = new ComputerPlayer('X', theBoard);
	playertwo = new HumanPlayer('O', theBoard);

	currentPlayer = playerone;
}

void Game::play_game(){
	//construct the game
	construct_game();
	display_board();

	while( theBoard->getWinner() == ' ' && !theBoard->isFull() ) {

		currentPlayer->move(theBoard);

		changePlayers();
		display_board();
	}
	changePlayers();
	char winner = currentPlayer->Player;
	if( winner == ' ' )
	{
		cout << "Tie game." << endl;
	}
	else
	{
		cout << "Player " << winner << " wins!" << endl;
	}
}