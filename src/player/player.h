#pragma once
#include "../board/ConnectFourBoard.h"

using namespace std;

struct Player {

	bool Player;

	virtual void move (ConnectFourBoard * b) = 0;

};