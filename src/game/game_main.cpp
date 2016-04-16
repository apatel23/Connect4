#include "game.h"
#include <iostream>

using namespace std;

void Game::construct_game(ConnectFourBoard* B, Player* p_one, Player* p_two){

	theBoard = B;
	playerone = p_one;
	playertwo = p_two;

	currentPlayer = playerone;
}

void Game::play_game(){
	display_board();

	while( theBoard->getWinner() == ' ' && !theBoard->isFull() ) {

		currentPlayer->move(theBoard);

		changePlayers();
		display_board();
	}
	changePlayers();
	char winner = theBoard->getWinner();
	if( winner == ' ' )
	{
		cout << "Tie game." << endl;
	}
	else
	{
		cout << "Player " << winner << " wins!" << endl;
	}
}