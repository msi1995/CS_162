/******************************************************
** Program: driver.cpp
** Author: Doug Lloyd
** Date: 01/28/2020
** Description: Plays the card game Crazy Eights. 
	Generates an array of 52 Card objects, populates
	the array with 52 playing cards, shuffles the cards.
	Deals 7 cards to a human player and CPU and then 
	sets the 15th card as the initial top card for the
	game. 

	Player can then play one of their cards that matches
	the suit or rank of the top card (or any 8) or draw 
	if they cannot. CPU will make a move and players
	will go back and forth until someone lays down
	all of their cards or the draw pile is empty.

	My program cannot take cards out of the players' 
	hands when played, and so cannot detect a winner.
******************************************************/

using namespace std;
#include "deck.h"
#include "game.h"
#include <iostream>

int main() {
	int deck_marker = 36;
	int hand_size = 7, cpu_hand_size = 7;
	int game_over = 0;
	Deck game_deck;
	Player player1, cpu;
	Game C8;

	player1.get_name();
	game_deck.populate_deck();
	game_deck.shuffle();
	/*cout << endl << "Generated deck:" << endl;
	game_deck.print_deck();*/


	player1.create_phand(game_deck);
	cpu.create_phand(game_deck);
	//cpu.print_phand();


	//cout << "Revised deck (C8 copy):" << endl;
	C8.copy_playdeck(game_deck);
	//C8.print_playdeck(game_deck);
	C8.grab_topcard();
	player1.print_phand();
	C8.print_topcard();


	while (game_over < 3) {
		player1.play_card_valid(C8.topcard, C8.cards, deck_marker, hand_size);
		player1.print_phand();
		C8.print_topcard();
		cpu.cpu_play_card_valid(C8.topcard, C8.cards, deck_marker, cpu_hand_size);
		C8.print_topcard();
		player1.print_phand();

		game_over++; //The only reason this is here is because my program has no way to end otherwise since I can't check for a winner.
					// If I don't force the program to end somehow, valgrind will show memory leaks since the destructor isn't called if you ctrl+c in valgrind
	}

	cout << endl << "3 loops reached, exiting because I can't code" << endl;
	return 0;
}