#pragma once

using namespace std;

struct Node {
	Node ** nodes = nullptr;
	double data;
	bool valid = true;
	Node();

	void addNode(bool type);
	void addNode(int col, double value);

};