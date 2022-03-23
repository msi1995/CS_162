#include <iostream>
#include "Hand.h"
#include "card.h"
#include "deck.h"
#include "player.h"

Player::Player() {
	name = "Computer Player";
}

Player::~Player() {

}

void Player::get_name() {
	cout << "Enter player name: ";
	getline(cin, name);
}

void Player::create_phand(Deck& game_deck) {
	for (int i = 0; i < hand.hand_size(); i++) {
		hand.get_card()[i] = game_deck.draw_card();
	}
}

void Player::print_phand() {
	cout << endl << name << ", your current hand is:" << endl << endl;
	for (int i = 0; i < hand.hand_size(); i++) {
		if (hand.get_card()[i].get_rank() == 0)
			cout << "(Card " << i + 1 << "): " "Ace of ";
		else if (hand.get_card()[i].get_rank() == 10)
			cout << "(Card " << i + 1 << "): " "Jack of ";
		else if (hand.get_card()[i].get_rank() == 11)
			cout << "(Card " << i + 1 << "): " "Queen of ";
		else if (hand.get_card()[i].get_rank() == 12)
			cout << "(Card " << i + 1 << "): " "King of ";
		else if (hand.get_card()[i].get_rank() != 1000)
			cout << "(Card " << i + 1 << "): " << hand.get_card()[i].get_rank() + 1 << " of ";
		else
			cout << "" << endl;


		if (hand.get_card()[i].get_suit() == 0)
			cout << "Spades" << endl;
		else if (hand.get_card()[i].get_suit() == 1)
			cout << "Hearts"<< endl;
		else if (hand.get_card()[i].get_suit() == 2)
			cout << "Diamonds"<< endl;
		else if (hand.get_card()[i].get_suit() == 3)
			cout << "Clubs"<< endl;
		else if (hand.get_card()[i].get_suit() == 1000)
			cout << " ";

	}
}

int Player::prompt() {
	int playthiscard;
	cout << endl << "What card would you like to play? Press 1, 2, 3 etc or 0 to draw a card. Card must be an 8 or match the rank or suit of top card! ";

		cin >> playthiscard;
		return playthiscard;
}

//Checks validity of the card player chooses, and changes the new topcard by reference. works for declaring suit with 8 as well. a
int Player::play_card_valid(Deck& topcard) {
	int flag = 1;
	int declare_suit;
	while (flag == 1) {
		int choice = prompt();
		if (choice = 0) {
			//draw from gamedeck
		}
		int hand_rank = hand.get_card()[choice - 1].get_rank();
		int topcard_rank = topcard.get_card()[0].get_rank();
		int hand_suit = hand.get_card()[choice - 1].get_suit();
		int topcard_suit = topcard.get_card()[0].get_suit();

		if ((hand_rank == topcard_rank) || (hand_suit == topcard_suit) || (hand_rank == 7)) {
			flag = 0;
			topcard.get_card()[0] = hand.get_card()[choice - 1];

			if (hand_rank == 7) {
				cout << "Crazy Eight!!! Declare a suit (0: Spades | 1: Heart | 2: Diamonds | 3 Clubs): ";
				cin >> declare_suit;
				topcard.get_card()[0].set_rank(7);
				topcard.get_card()[0].set_suit(declare_suit);
			}
		}
	}
}

int Player::cpu_play_card_valid(Deck& topcard) {
	int flag = 1;
	int declare_suit;
	while (flag == 1) {
		for(int i = 0; i < 7; i++){
			int hand_rank = hand.get_card()[i].get_rank();
			int topcard_rank = topcard.get_card()[0].get_rank();
			int hand_suit = hand.get_card()[i].get_suit();
			int topcard_suit = topcard.get_card()[0].get_suit();
			if ((hand_rank == topcard_rank) || (hand_suit == topcard_suit) || (hand_rank == 7)) {
				flag = 0;
				topcard.get_card()[0] = hand.get_card()[i];

				if (hand_rank == 7) {
					topcard.get_card()[0].set_rank(7);
					topcard.get_card()[0].set_suit(rand() % 3);
				}
			}
		}
	}
}