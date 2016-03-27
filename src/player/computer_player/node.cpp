#include "node.h"

Node::Node() {
	nodes = nullptr;
}

void Node::addNode(int col, double value) {
	if (nodes == nullptr) {
		nodes = new Node*[7];
		for( int i = 0; i < 7; i++) {
			nodes[i] = nullptr;
		}
	}
		nodes[col] = new Node;
		nodes[col]->data = value;
}
