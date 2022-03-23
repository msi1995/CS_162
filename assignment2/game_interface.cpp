#include <iostream>
#include "Hand.h"
#include "card.h"
#include "deck.h"
#include "player.h"
#include "game.h"

using namespace std;

//Default Constructor
Game::Game() {

}

//Destructor
Game::~Game() {

}

//This copies the game deck object that has 38 cards in it to a new object,
// "cards", in the game class.
void Game::copy_playdeck(Deck& game_deck) {
	int size = game_deck.get_n_cards();
	for (int i = 0; i < size; i++) {
		cards.get_card()[i] = game_deck.draw_card();
	}
}

//This prints the deck called "cards" referenced in the function above.
void Game::print_playdeck(Deck& game_deck) {
	int size = 38;
	for (int i = 0; i < size; i++) {
		if (cards.get_card()[i].get_rank() == 0)
			cout << "Ace of ";
		else if (cards.get_card()[i].get_rank() == 10)
			cout << "Jack of ";
		else if (cards.get_card()[i].get_rank() == 11)
			cout << "Queen of ";
		else if (cards.get_card()[i].get_rank() == 12)
			cout << "King of ";
		else
			cout << cards.get_card()[i].get_rank() + 1 << " of ";


		if (cards.get_card()[i].get_suit() == 0)
			cout << "Spades" << endl;
		else if (cards.get_card()[i].get_suit() == 1)
			cout << "Hearts" << endl;
		else if (cards.get_card()[i].get_suit() == 2)
			cout << "Diamonds" << endl;
		else if (cards.get_card()[i].get_suit() == 3)
			cout << "Clubs" << endl;
	}
}

//This draws a card from the "cards" deck above and then decrements
// an n_cards counter so that the next card can be drawn when the function
// is called again. Returns the card. 
Card Game::draw_card(Deck& cards) {
	Card tempcard = cards.get_card()[n_cards - 1];
	n_cards--;
	return tempcard;
}

//This sets the initial top card that is used to play the game. It is drawn
//from the "cards" deck, which was a copy of the 38 cards remaining in the 
// original deck after each player was dealt 7 cards.
void Game::grab_topcard() {
	for (int i = 0; i < 1; i++) {
		topcard.get_card()[i] = draw_card(cards);
	}
}

//This prints the top card and is used every time the top card changes.
void Game::print_topcard() {
	cout << "Top Card: ";
	for (int i = 0; i < 1; i++) {
		if (topcard.get_card()[i].get_rank() == 0)
			cout << "Ace of ";
		else if (topcard.get_card()[i].get_rank() == 10)
			cout << "Jack of ";
		else if (topcard.get_card()[i].get_rank() == 11)
			cout << "Queen of ";
		else if (topcard.get_card()[i].get_rank() == 12)
			cout << "King of ";
		else if (topcard.get_card()[i].get_rank() != 1000)
			cout << topcard.get_card()[i].get_rank() + 1 << " of ";
		else
			cout << "";


		if (topcard.get_card()[i].get_suit() == 0)
			cout << "Spades" << endl;
		else if (topcard.get_card()[i].get_suit() == 1)
			cout << "Hearts" << endl;
		else if (topcard.get_card()[i].get_suit() == 2)
			cout << "Diamonds" << endl;
		else if (topcard.get_card()[i].get_suit() == 3)
			cout << "Clubs" << endl;
		else
			cout << "";
	}
	cout << endl;
}