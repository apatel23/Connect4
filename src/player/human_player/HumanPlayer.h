#pragma once
#include "../player.h"


class HumanPlayer : public Player {
public:
	virtual void move(ConnectFourBoard * b) override;
	HumanPlayer(char Player, ConnectFourBoard *b);
};