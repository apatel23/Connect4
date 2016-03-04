#pragma once
#include "ConnectFourBoard.h"

class ComputerPlayer {
public:
	static void move(char Player, ConnectFourBoard &b);
	ComputerPlayer(ConnectFourBoard &b);
	float getUtility(int column);
private:
	ConnectFourBoard board;
	char currentPlayer;
};
