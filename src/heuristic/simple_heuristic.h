#pragma once
#include "heuristic.h"

class SimpleHeuristic : public Heuristic {
public:
	SimpleHeuristic(int threshold, bool thresh, int depth);
	virtual int getHeuristic( ConnectFourBoard bo ) override;
};