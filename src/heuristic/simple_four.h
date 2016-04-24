#pragma once
#include "heuristic.h"

class SimpleFour : public Heuristic {
public:
	int getresult( char results []);
	SimpleFour(int threshold, bool thresh, int depth);
	virtual int getHeuristic( ConnectFourBoard bo ) override;
};