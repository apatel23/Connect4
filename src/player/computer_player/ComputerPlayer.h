#pragma once
#include "../player.h"
#include "node.h"

class ComputerPlayer : public Player {
public:
	virtual void move(ConnectFourBoard * b) override;
	bool firstMove = true;
	ComputerPlayer(bool Player, ConnectFourBoard *b);
	float getUtility(int column);
	Node * root;
	Node * current_node;
	int getHeuristic( ConnectFourBoard board);
	int AlphaBeta(Node* node, ConnectFourBoard b, int depth, int Alpha, int Beta, bool MaxPlayer);
	void setDepth(int depth);
	void runAlgorithm( Node * b );
	void checkNode(Node * node, ConnectFourBoard b, bool ply);
	int findBestnode(Node * n);

private:
	ConnectFourBoard board;
	char currentPlayer;

	// depth of the algorithm
	int depth;
};
