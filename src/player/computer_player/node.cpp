#include "node.h"

Node::Node() {
	nodes = nullptr;
}

void Node::addNode(bool Max) {
	if (nodes == nullptr) {
		nodes = new Node*[7];
		for( int i = 0; i < 7; i++) {
			nodes[i] = new Node;
			if( Max ) {
				nodes[i]->data = -100;
			}else {
				nodes[i]->data = 100;
			}
			//nodes[i]->data = 0;
		}
	}
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
