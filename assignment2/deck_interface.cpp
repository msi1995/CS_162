
#include <iostream>
#include "deck.h"
#include "card.h"

using namespace std;

//Default Constructor

Deck::~Deck() {

}

//Destructor
Deck::Deck() {

}

//Getter for the private array of 52 cards
Card* Deck::get_card() {

	return card_arr;

}

//Getter for the private n_cards member
int Deck::get_n_cards() {
	return n_cards;
}

//Iterates through all 52 members of the empty card_arr array and 
// assigns them a rank 0-12, with each set of 13 cards getting
// a suit (Hearts, Clubs, Diamonds, Spades)
void Deck::populate_deck() {
	int card_count = 0;

	for (int i = 0; i < 13; i++) {
		card_arr[card_count].set_rank(i);
		card_arr[card_count].set_suit(0);
		card_count++;
	}
	for (int i = 0; i < 13; i++) {
		card_arr[card_count].set_rank(i);
		card_arr[card_count].set_suit(1);
		card_count++;
	}
	for (int i = 0; i < 13; i++) {
		card_arr[card_count].set_rank(i);
		card_arr[card_count].set_suit(2);
		card_count++;
	}
	for (int i = 0; i < 13; i++) {
		card_arr[card_count].set_rank(i);
		card_arr[card_count].set_suit(3);
		card_count++;
	}
}

// Function used to perform the actual shuffling of the deck. Takes in
// two integers, and swaps those cards positions in the deck. For example,
// swapcards(5,25) would swap card 5's position with card 25's position.
void Deck::swapcards(int card1, int card2) {
	Card temp;

	if (card1 == card2)
		return;

	temp = card_arr[card1];
	card_arr[card1] = card_arr[card2];
	card_arr[card2] = temp;
}

//Generates random numbers to be passed into the swapcards function and calls
// swapcards 100 times with those values. Results in a completely shuffled
// deck.
void Deck::shuffle() {
	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		swapcards(rand() % 52, rand() % 52);
	}

}

// Draws a card from the game deck and then decrements the n_cards value so that
// the next card can be pulled properly instead of repeated. This function will
// be used to populate the player's initial hand of 7 cards in the Player class
// later.
Card Deck::draw_card() {
	Card tempcard = card_arr[n_cards-1];
	n_cards--;
	return tempcard;
}

// Prints the deck, using the n_cards value as a bound.
void Deck::print_deck(){
	cout << endl;
	for (int i = 0; i < n_cards; i++) {
		if (card_arr[i].get_rank() == 0)
			cout << "Ace of ";
		else if (card_arr[i].get_rank() == 10)
			cout << "Jack of ";
		else if (card_arr[i].get_rank() == 11)
			cout << "Queen of ";
		else if (card_arr[i].get_rank() == 12)
			cout << "King of ";
		else
			cout << card_arr[i].get_rank() + 1 << " of ";



		if (card_arr[i].get_suit() == 0)
			cout << "Spades" << endl;
		else if (card_arr[i].get_suit() == 1)
			cout << "Hearts" << endl;
		else if (card_arr[i].get_suit() == 2)
			cout << "Diamonds" << endl;
		else if (card_arr[i].get_suit() == 3)
			cout << "Clubs" << endl;
		}

	}
