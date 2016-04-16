#pragma once
#include "../player.h"
#include "node.h"
#include "../../heuristic/heuristic.h"

class ComputerPlayer : public Player {
public:
	virtual void move(ConnectFourBoard * b) override;
	bool firstMove = true;
	ComputerPlayer(bool Player, ConnectFourBoard *b);
	float getUtility(int column);
	Node * root;
	Node * current_node;


	int AlphaBeta(Node* node, ConnectFourBoard b, int depth, int Alpha, int Beta, bool MaxPlayer);
	void setDepth(int depth);
	void runAlgorithm( Node * b );
	void checkNode(Node * node, ConnectFourBoard b, bool ply);


	int findBestnode(Node * n);

	virtual void setHeuristic(Heuristic* h) override;

private:
	ConnectFourBoard board;
	Heuristic* heuristic;
	char currentPlayer;


	// depth of the algorithm
	int depth;
};
