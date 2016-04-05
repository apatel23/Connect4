#pragma once
#include "../player.h"
#include "node.h"

class ComputerPlayer : public Player {
public:
	virtual void move(ConnectFourBoard * b) override;
	ComputerPlayer(bool Player, ConnectFourBoard *b);
	float getUtility(int column);
	Node * root;
	int getHeuristic( ConnectFourBoard board);
	int AlphaBeta(Node* node, ConnectFourBoard b, int depth, int Alpha, int Beta, bool MaxPlayer);
	void setDepth(int depth);
	void runAlgorithm();
	void checkNode(Node * node);

private:
	ConnectFourBoard board;
	char currentPlayer;

	// depth of the algorithm
	int depth;
};
