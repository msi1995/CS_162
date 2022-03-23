#pragma once

#include "card.h"
#include <cstdlib>

class Deck {
private:
	Card card_arr[52];
	int n_cards = 52;

public:
	Deck();
	~Deck();
	void populate_deck();
	void shuffle();
	void swapcards(int, int);
	void print_deck();
	int get_n_cards();
	Card* get_card();
	Card draw_card();
};