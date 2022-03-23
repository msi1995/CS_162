#include "linked_list.h"
#include <iostream>
using namespace std;

Linked_List::Linked_List() {

	head = NULL;
	tail = NULL;
	del = NULL;
}

Linked_List::~Linked_List() {
	while (head != NULL) {
		del = head->next;
		delete head;
		head = del;
	}

}


int Linked_List::get_length() {
	return length;
}

bool Linked_List::is_prime(int num) {
	if (num < 0)
		return false;

	for (int i = 2; i <= num / 2; ++i) {
		if (num % i == 0) {
			//cout << num << " is not prime" << endl;
			return false;
			break;
		}
	}
	//cout << num << " is prime" << endl;
	return true;
}

int Linked_List::count_primes() {
	int primes = 0;
	Node* current;
	Node* next;
	current = head;

	if (head == NULL)
		return 0;

	else {
		while (current != NULL) {
			if (is_prime(current->val) == true)
				primes++;
			current = current->next;
		}
		return primes;
	}
}

void Linked_List::print() {

	Node* current;
	current = head;

	while (current != NULL) {
		cout << current->val << " ";
		current = current->next;
	}
}

void Linked_List::clear() {

	Node* current;
	Node* next;
	current = head;

	while (current != NULL) {
		next = current->next;
		delete current;
		current = next;
	}
	length = 0;
}

unsigned int Linked_List::push_back(int value) {
	Node* temp = new Node;
	temp->val = value;
	temp->next = NULL;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}
	else {
		tail->next = temp;
		tail = tail->next;
	}

	length++;
	return length;
}

unsigned int Linked_List::push_front(int value) {
	Node* temp = new Node;
	temp->val = value;
	temp->next = NULL;

	if (head == NULL) {
		head = temp;
		tail = temp;
	}

	else {
		temp->next = head;
		head = temp;
	}
	
	length++;
	return length;
}

unsigned int Linked_List::insert(int value, unsigned int index) {
	int tracker = 1;
	Node* temp = new Node;
	Node* current = head;
	Node* tnext = head;
	temp->val = value;
	temp->next = NULL;

	if (index > length) {
		cout << "Invalid index. Can't add a value there.";
	}
	else {
		while (tracker != index - 1) {
			current = current->next;
			tnext = tnext->next;
			tracker++;
		}
		if (tracker == index - 1) {
			tnext = tnext->next;
			current->next = temp;
			temp->next = tnext;
		}
		length++;
		return length;
	}
}

void Linked_List::sort_ascending() {
	MergeSort(&head);
}

void Linked_List::sort_descending() {
	MergeSort_2(&head);
}



void Linked_List::user_flow() {
	char x;
	char z;
	int y;
	while (x != 'y') {
		cout << "Enter a number to add to list: ";
			cin >> y;
			push_back(y);
			cout << "Finished entering numbers? (y/n): ";
			cin >> x;
	}
	cout << "Sort ascending or descending? (a/d): ";
	cin >> z;
	if (z == 'a') {
		sort_ascending();
	}
	if (z == 'd')
		sort_descending();

	cout << endl << "Your sorted list: ";
	print();
}

Node* Linked_List::Merge(Node* h1, Node* h2) {
	

	Node* temp1 = new Node;
	Node* temp2 = new Node;
	Node* temp3 = new Node;

	if (h1 == NULL)
		return h2;
	if (h2 == NULL)
		return h1;

		temp1 = h1;

	while (h2 != NULL) {

		temp2 = h2;

		h2 = h2->next;
		temp2->next = NULL;

		if (h1->val > temp2->val) {
			temp2->next = h1;
			h1 = temp2;
			temp1 = h1;
			continue;
		}
	loop:
		if (temp1->next == NULL)
		{
			temp1->next = temp2;
			temp1 = temp1->next;
		}
		else if ((temp1->next)->val <= temp2->val)
		{
			temp1 = temp1->next;
			goto loop;
		}
		else
		{
			temp3 = temp1->next;
			temp1->next = temp2;
			temp2->next = temp3;
		}
	}

	return h1;
}


void Linked_List::MergeSort(Node** head2) {
	

	Node* first = new Node;
	Node* second = new Node;
	Node* temp = new Node;

	first = *head2;
	temp = *head2;

	// quit if linked list only has one node or zero node
	if (first == NULL || first->next == NULL)
	{
		return;
	}
	else
	{
		//split list in half
		while (first->next != NULL)
		{
			first = first->next;
			if (first->next != NULL)
			{
				temp = temp->next;
				first = first->next;
			}
		}
		second = temp->next;
		temp->next = NULL;
		first = *head2;
	}

	//recursive calls
	MergeSort(&first);
	MergeSort(&second);     


	*head2 = Merge(first, second);

}


Node* Linked_List::Merge_2(Node* h1, Node* h2) {

	Node* temp1 = new Node;
	Node* temp2 = new Node;
	Node* temp3 = new Node;

	if (h1 == NULL)
		return h2;
	if (h2 == NULL)
		return h1;

	temp1 = h1;

	while (h2 != NULL) {

		temp2 = h2;

		h2 = h2->next;
		temp2->next = NULL;

		if (h1->val < temp2->val) {
			temp2->next = h1;
			h1 = temp2;
			temp1 = h1;
			continue;
		}
	loop:
		if (temp1->next == NULL)
		{
			temp1->next = temp2;
			temp1 = temp1->next;
		}
		else if ((temp1->next)->val >= temp2->val)
		{
			temp1 = temp1->next;
			goto loop;
		}
		else
		{
			temp3 = temp1->next;
			temp1->next = temp2;
			temp2->next = temp3;
		}
	}

	temp1 = NULL;
	temp2 = NULL;
	temp3 = NULL;

	return h1;
}

void Linked_List::MergeSort_2(Node** head2) {


	Node* first = new Node;
	Node* second = new Node;
	Node* temp = new Node;

	first = *head2;
	temp = *head2;

	// quit if linked list only has one node or zero node
	if (first == NULL || first->next == NULL)
	{
		return;
	}
	else
	{
		//split list in half
		while (first->next != NULL)
		{
			first = first->next;
			if (first->next != NULL)
			{
				temp = temp->next;
				first = first->next;
			}
		}
		second = temp->next;
		temp->next = NULL;
		first = *head2;
	}

	MergeSort_2(&first);
	MergeSort_2(&second);

	*head2 = Merge_2(first, second);

}