#pragma once

class Node {
public:
	int val;    // the value that this node stores
	Node* next; // a pointer to the next node in the list

	//standard constructor
	Node();

	//standard destructor
	~Node();
};