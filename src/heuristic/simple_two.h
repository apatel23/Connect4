#pragma once
#include "heuristic.h"

class SimpleTwo : public Heuristic {
public:
	int getresult( char results []);
	SimpleTwo(int threshold, bool thresh, int depth);
	virtual int getHeuristic( ConnectFourBoard bo ) override;
};