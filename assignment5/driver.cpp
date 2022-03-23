/******************************************************
** Program: driver.cpp
** Author: Doug Lloyd
** Date: 03/15/2020
** Description: Driver for linked list.
** Input: numbers and a/d for sort
** Output: sorted linked list, # of prime numbers, and # of nodes in list.
******************************************************/

#include "linked_list.h"
using namespace std;

int main() {	
	Linked_List list1;

	list1.user_flow();
	cout << endl << endl << "Number of nodes in the list is: " << list1.get_length();
	cout << endl << "Number of primes in the list is: " << list1.count_primes() << endl << endl;
	

	list1.clear();

	cout << endl << "Number of nodes in the list after clear function: " << list1.get_length() << endl;

	return 0;
}