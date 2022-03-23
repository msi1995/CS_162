

#include "card.h"
#include <iostream>

using namespace std;

//Default Constructor
Card::~Card() {

}

//Destructor
Card::Card() {

}

//Setter for the suit member variable of the Card class.
void Card::set_suit(int new_suit) {
	suit = new_suit;
}

//Setter for the rank member variable of the Card class.
void Card::set_rank(int new_rank) {
	rank = new_rank;
}

//Getter for the suit member variable of the Card class.
int Card::get_suit() {
	return suit;
}

//Getter for the rank member variable of the Card class.
int Card::get_rank() {
	return rank;
}