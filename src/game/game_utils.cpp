#include "game.h"

using namespace std;

void Game::changePlayers(){
	if(IsPlayerOne){
		IsPlayerOne = false;
		currentPlayer = playertwo;
	}else{
		IsPlayerOne = true;
		currentPlayer = playerone;
	}
}


Player * Game::getWinner() {
	return currentPlayer;
}

Player * Game::getCurrentPlayer() {
	return currentPlayer;
}

