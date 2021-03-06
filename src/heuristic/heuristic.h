#pragma once
#include "../board/ConnectFourBoard.h"


using namespace std;

struct Heuristic {

	int DEPTH;

	int MAX_SCORE;
	int THRESHOLD;

	bool WINNER;

	bool t_hold;

	virtual int getHeuristic(ConnectFourBoard bo) = 0;

};