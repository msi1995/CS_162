#pragma once

#include <iostream>
#include "card.h"
#include "deck.h"

using namespace std;

class Hand {
private:
	Card* cards;
	int n_cards;
public:
	Hand();
	~Hand();
	Hand(const Hand& source);
	Hand& operator=(const Hand& source);

	int hand_size();
	Card* get_card();
};