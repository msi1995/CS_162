/******************************************************
** Program: Zoo Tycoon
** Author: Doug Lloyd
** Date: 02/17/2020
** Description: Plays a barebones version of the game Zoo
	Tycoon. Allows player to purchase animals which can then
	have babies and become sick. Babies generate extra
	revenue and sick animals cost money to treat. Random
	attendance booms occur which cause sea lions to generate
	extra revenue. Reports user balance/revenue and progresses
	in a monthly fashion. Game ends if user runs out of money.
	Player begins the game with $100,000.
** Input: None
** Output: Terminal output includes game information such
	as revenue, balance, prompts about sick animals
	and births, etc.
******************************************************/

#include <iostream>
#include "zoo.h"

using namespace std;


int main() {
	Zoo Player_Zoo;

	Player_Zoo.start();


	return 0;
}