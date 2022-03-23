#pragma once
#include <iostream>
#include "card.h"
#include "deck.h"
#include "Hand.h"

class Player {
private:
	Hand hand;
	string name;
public:
	Player();
	~Player();
	void create_phand(Deck&);
	void print_phand();
	void get_name();
	int prompt();
	void play_card_valid(Deck&, Deck&, int&, int&);
	void cpu_play_card_valid(Deck&, Deck&, int&, int&);

};