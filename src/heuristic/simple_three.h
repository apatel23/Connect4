#pragma once
#include "heuristic.h"

class SimpleThree : public Heuristic {
public:
	int getresult( char results []);
	SimpleThree(int threshold, bool thresh, int depth);
	virtual int getHeuristic( ConnectFourBoard bo ) override;
};