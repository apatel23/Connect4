#pragma once

using namespace std;

struct Node {
	Node ** nodes = nullptr;
	double data;
	bool explored = false;
	Node();
	void addNode(int col, double value);
};