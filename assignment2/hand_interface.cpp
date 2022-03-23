
#include <iostream>
#include "Hand.h"
#include "card.h"
#include "deck.h"

//Default Constructor
Hand::Hand() {
	n_cards = 14;
	cards = new Card[n_cards];

}

//Destructor that includes delete[] command to free memory allocated for the dynamic hand array.
Hand::~Hand() {
	delete[] cards;
}

// Getter for the n_cards private member
int Hand::hand_size() {

	return n_cards;


}

// Getter for the Card* cards private member
Card* Hand::get_card() {

	return cards;

}