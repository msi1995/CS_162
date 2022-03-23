#pragma once
#include <iostream>
#include "node.h"

class Linked_List {
private:
	unsigned int length; // the number of nodes contained in the list
	Node* head, *tail, *del; // a pointer to the head and tail of the list, and a
							// del node that i use in the destructor

public:

	//standard constructor
	Linked_List();

	//standard destructor
	~Linked_List();

	//returns length value 
	int get_length();

	/*This function iterates through all of the nodes in the linked list, and then passes
	the int value they contain into the is_prime function. if is_prime is true, increments 
	the prime tracker.*/
	int count_primes();

	/*Function recursively checks to see if a number is prime*/
	bool is_prime(int);

	/*This function iterates through all of the nodes in the linked list, printing their values
	as it iterates.*/
	void print(); 

	/*This function iterates through all of the nodes in the linked list, deleting the nodes
	as it iterates. Sets length to 0.*/
	void clear();

	/*This function makes a temp node, stores the user inputted value in it,
	sets temp's pointer to the head, and then changes temp to
	the new head.*/
	unsigned int push_front(int);

	/*This function makes a temp node, stores the user inputted value in it,
	sets tail's pointer to temp, and makes temp the new tail.*/
	unsigned int push_back(int); 

	/*This function takes a value and an index and inserts the new node and it's
	value at the index selected by the user, and remaps the pointers.*/
	unsigned int insert(int, unsigned int);

	/*This function just calls the MergeSort(Node**) function.*/
	void sort_ascending();

	/*This function just calls the MergeSort_2(Node**) function.*/
	void sort_descending();

	/*This function handles the user input (adding numbers to list until
	finished and choosing ascending/descending sort.) Also calls print().*/
	void user_flow();


/* This function recursively splits the list over and over until it is in
individual nodes. Calls Merge with actually sorts and merges the list
back together.*/
	void MergeSort(Node**);


/* This function sorts the linked list in ascending order by rearranging 
pointers and then returns the head.*/
	Node* Merge(Node*, Node*);


/* This function recursively splits the list over and over until it is in
individual nodes. Calls Merge_2 with actually sorts and merges the list
back together.*/
	void MergeSort_2(Node**);

/* This function sorts the linked list in descending order by rearranging
pointers and then returns the head.*/
	Node* Merge_2(Node*, Node*);

};