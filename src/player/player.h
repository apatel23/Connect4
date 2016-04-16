#pragma once
#include "../board/ConnectFourBoard.h"
#include "../heuristic/heuristic.h"

using namespace std;

struct Player {

	bool Player;

	virtual void move (ConnectFourBoard * b) = 0;

	virtual void setHeuristic(Heuristic* h) = 0;

};