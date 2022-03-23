#pragma once
#include <iostream>
#include "card.h"
#include "deck.h"
#include "Hand.h"
#include "player.h"

class Game {
private:
	Player players[2];

public:
	Deck topcard;
	Deck cards;
	Game();
	~Game();
	int n_cards = 38;
	Card draw_card(Deck&);
	void copy_playdeck(Deck&);
	void print_playdeck(Deck&);
	void grab_topcard();
	void print_topcard();

};