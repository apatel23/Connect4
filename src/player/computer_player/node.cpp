#include "node.h"

Node::Node() {
	nodes = nullptr;
}

void Node::addNode(int col, double value) {
	if (nodes == nullptr) {
		nodes = new Node*[8];
		for( int i = 0; i < 8; i++) {
			nodes[i] = nullptr;
		}
	}
		nodes[col] = new Node;
		nodes[col]->data = value;
}
