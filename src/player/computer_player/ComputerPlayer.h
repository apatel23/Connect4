#pragma once
#include "../player.h"
#include "node.h"
#include "../../heuristic/heuristic.h"

class ComputerPlayer : public Player {
public:
	virtual void move(ConnectFourBoard * b) override;
	bool firstMove = true;
	ComputerPlayer(bool Player, ConnectFourBoard *b);

	Node * root;


	int AlphaBeta(ConnectFourBoard b, int depth, int Alpha, int Beta, bool MaxPlayer);
	void setDepth(int depth);


	int findBestnode(Node * n);

	virtual void setHeuristic(Heuristic* h) override;

private:
	ConnectFourBoard board;
	Heuristic* heuristic;
	char currentPlayer;


	// depth of the algorithm
	int depth;
};
