#pragma once
#include "../player.h"

class ComputerPlayer : public Player {
public:
	virtual void move(ConnectFourBoard * b) override;
	ComputerPlayer(char Player, ConnectFourBoard *b);
	float getUtility(int column);
private:
	ConnectFourBoard board;
	char currentPlayer;
};
