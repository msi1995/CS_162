#include "room.h"
#include "game.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdio.h>      
#include <stdlib.h>   
using namespace std;


Game::Game() {


}

Game::Game(int x) {
	gridsize = x;
}

Game::~Game() {

}

void Game::set_gamemode(int x) {
	gamemode = x;
}

void Game::create_grid(int x) {
	set_gamemode(x);
	for (int i = 0; i < gridsize; i++) {
		vector<Room> roomVector;
		for (int j = 0; j < gridsize; j++) {
			Room one;
			roomVector.push_back(one);
		}
		roomVector2.push_back(roomVector);
	}

	populate_all();

	
	cout << endl << "Welcome to Hunt The Wumpus. Your position in the Wumpus' cave is denoted by the X in the grid below..." << endl << endl;
	cout << "You must traverse the caves, find the gold, and return to your starting room to win the game." << endl;
	cout << "Be aware that the Wumpus will kill you if you enter his room. There are also rooms with superbats that will carry you to random rooms." << endl;
	cout << "Some rooms contain pitfalls -- You will die if you fall into one. Hints will be given to you when you are near any room containing a hazard." << endl << endl;
	cout << "Press w, a, s, or d to move your character. Press space and then w, a, s, or d to fire an arrow in that direction." << endl << endl << endl;
	cout << "Good luck..." << endl << endl;
	if (gamemode == 2)
		cout << endl << "GAME STARTED IN EXPERT MODE. NUMBER OF BATS/WUMPUS/PITS HEAVILY INCREASED. YOU HAVE NO ARROWS." << endl << endl;
	check_adjacent();
	print_grid();
}




void Game::place_player() {
	int i1, i2;
	int cont = 1;

	while (cont == 1) {
		i1 = rand() % (gridsize);
		i2 = rand() % (gridsize);

		if (roomVector2[i1][i2].event_present == 0) {
			roomVector2[i1][i2].player_present = 1;
			roomVector2[i1][i2].event_present = 1;
			roomVector2[i1][i2].escape_rope = 1;
			
			cont = 0;
		}
	}
}



void Game::place_wumpus() {
	int i1, i2;
	int cont = 1;
	while (cont == 1) {
		i1 = rand() % (gridsize);
		i2 = rand() % (gridsize);

		if (roomVector2[i1][i2].event_present == 0) {
			roomVector2[i1][i2].wumpus_present = 1;
			roomVector2[i1][i2].event_present = 1;
			roomVector2[i1][i2].set_event(3);
			cont = 0;
		}
	}
}

void Game::move_wumpus() {
	int i1, i2;
	int cont = 1;
	int flag = 0;
	int random = rand() % 4;
	if (random != 3) {
		for (int i = 0; i < gridsize; i++) {
			for (int j = 0; j < gridsize; j++) {
				if (roomVector2[i][j].wumpus_present == 1) {
					roomVector2[i][j].wumpus_present = 0;
					roomVector2[i][j].event_present = 0;
					roomVector2[i][j].set_event(5);
					while (cont == 1) {
						i1 = rand() % (gridsize);
						i2 = rand() % (gridsize);
						if (roomVector2[i1][i2].event_present == 0 && roomVector2[i1][i2].player_present == 0) {
							cont = 0;
							roomVector2[i1][i2].wumpus_present = 1;
							roomVector2[i1][i2].event_present = 1;
							roomVector2[i1][i2].set_event(3);
						}
					}
				}
				if (cont == 0)
					break;
			}
			if (cont == 0)
				break;
		}
	}
}
				

void Game::place_gold() {
	int i1, i2;
	int cont = 1;
	while (cont == 1) {
		i1 = rand() % (gridsize);
		i2 = rand() % (gridsize);

		if (roomVector2[i1][i2].event_present == 0) {
			roomVector2[i1][i2].gold_present = 1;
			roomVector2[i1][i2].event_present = 1;
			roomVector2[i1][i2].set_event(1);
			cont = 0;
		}
	}
}


void Game::place_pits() {
	int i1, i2;
	int cont = 1;
	while (cont == 1) {
		i1 = rand() % (gridsize);
		i2 = rand() % (gridsize);

		if (roomVector2[i1][i2].event_present == 0) {
			roomVector2[i1][i2].pits_present = 1;
			roomVector2[i1][i2].event_present = 1;
			roomVector2[i1][i2].set_event(2);
			cont = 0;
		}
	}
}


void Game::place_bats() {
	int i1, i2;
	int cont = 1;
	while (cont == 1) {
		i1 = rand() % (gridsize);
		i2 = rand() % (gridsize);

		if (roomVector2[i1][i2].event_present == 0) {
			roomVector2[i1][i2].bats_present = 1;
			roomVector2[i1][i2].event_present = 1;
			roomVector2[i1][i2].set_event(4);
			cont = 0;
		}
	}
}


void Game::populate_all() {
	if (gamemode == 2) {
		arrow_count = 0;
		place_player();
		place_gold();
		for (int i = 0; i < (gridsize / 2); i++) {
			place_pits();
			place_wumpus();
			place_bats();
		}
	}
	else {
		place_player();
		place_wumpus();
		place_gold();
		place_pits();
		place_pits();
		place_bats();
		place_bats();
	}
}


void Game::player_move() {
	char choice, choice2;
	int flag = 0;
	cout << "Make a move: ";
	system("stty raw");
	choice = getchar();
	if (choice == ' ')
		choice2 = getchar();
	system("stty cooked");
		for (int i = 0; i < gridsize; i++) {
			for (int j = 0; j < gridsize; j++) {
				if (roomVector2[i][j].player_present == 1) {
					flag = 1;
					if (choice == 'w') 
						move_north();
					else if (choice == 's')
						move_south();
					else if (choice == 'a')
						move_west();
					else if (choice == 'd')
						move_east();
					else if (choice == 'z')
						exit(1);
					else if (choice2 == 'w')
						fire_north();
					else if (choice2 == 'd')
						fire_east();
					else if (choice2 == 'a')
						fire_west();
					else if (choice2 == 's')
						fire_south();
				}
				if (flag == 1)
					break;
			}
			if (flag == 1)
				break;
		}
		win_condition();
		check_adjacent();
		encounter_checker();
		print_grid();
	}

void Game::move_north() {
	for (int i = 0; i < gridsize; i++) {
		for (int j = 0; j < gridsize; j++) {
			if (roomVector2[i][j].player_present == 1) {
					if (i != 0) {
						roomVector2[i][j].player_present = 0;
						roomVector2[i - 1][j].player_present = 1;
						roomVector2[i - 1][j].run_encounter();

					}
			}
		}
	}
}

void Game::move_south() {
	int flag = 0;

	for (int i = 0; i < gridsize; i++) {
		for (int j = 0; j < gridsize; j++) {
			if (roomVector2[i][j].player_present == 1) {
				if (i != gridsize - 1) {
					flag = 1;
					roomVector2[i][j].player_present = 0;
					roomVector2[i + 1][j].player_present = 1;
					roomVector2[i + 1][j].run_encounter();
						break;
				}
			}
			if (flag == 1)
				break;
		}
		if (flag == 1)
			break;
	}
}

void Game::move_east() {
	int flag = 0;
	for (int i = 0; i < gridsize; i++) {
		for (int j = 0; j < gridsize; j++) {
			if (roomVector2[i][j].player_present == 1) {
				flag = 1;
				if (j != gridsize-1) {
					roomVector2[i][j].player_present = 0;
					roomVector2[i][j+1].player_present = 1;
					roomVector2[i][j+1].run_encounter();
					break;

				}
			}
		}
	}
}

void Game::move_west() {
	for (int i = 0; i < gridsize; i++) {
		for (int j = 0; j < gridsize; j++) {
			if (roomVector2[i][j].player_present == 1) {
				if (j != 0) {
					roomVector2[i][j].player_present = 0;
					roomVector2[i][j-1].player_present = 1;
					roomVector2[i][j-1].run_encounter();
				}
			}
		}
	}
}

void Game::fire_north() {
	if (arrow_count > 0) {
		arrow_count--;
		for (int i = 0; i < gridsize; i++) {
			for (int j = 0; j < gridsize; j++) {
				if (roomVector2[i][j].player_present == 1) {
					if (i != 0 && roomVector2[i - 1][j].wumpus_present == 1) {
						roomVector2[i - 1][j].wumpus_present = 0;
						roomVector2[i - 1][j].set_event(5);
						cout << endl << "You hear a deafening roar followed by a thud as the Wumpus falls to the ground, dead." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
					}
					else if ((i != 0) && (i != 1) && (roomVector2[i - 2][j].wumpus_present == 1)) {
						roomVector2[i - 2][j].wumpus_present = 0;
						roomVector2[i - 2][j].set_event(5);
						cout << endl << "You hear a deafening roar followed by a thud as the Wumpus falls to the ground, dead." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
					}
					else if ((i != 0) && (i != 1) && (i != 2) && (roomVector2[i - 3][j].wumpus_present == 1)) {
						roomVector2[i - 3][j].wumpus_present = 0;
						roomVector2[i - 3][j].set_event(5);
						cout << endl << "You hear a deafening roar followed by a thud as the Wumpus falls to the ground, dead." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
					}
					else {
						cout << endl << "You hear your arrow clatter to the ground in the distance, followed by the rapid pounding of paws against pavement..." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
						move_wumpus();
					}
				}
			}
		}
	}
	else 
		cout << endl << "You are out of arrows..." << endl;
}


void Game::fire_east() {
	if (arrow_count > 0) {
		arrow_count--;
		for (int i = 0; i < gridsize; i++) {
			for (int j = 0; j < gridsize; j++) {
				if (roomVector2[i][j].player_present == 1) {
					if (j != gridsize - 1 && roomVector2[i][j + 1].wumpus_present == 1) {
						roomVector2[i][j + 1].wumpus_present = 0;
						roomVector2[i][j + 1].set_event(5);
						cout << endl << "You hear a deafening roar followed by a thud as the Wumpus falls to the ground, dead." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
					}
					else if ((j != gridsize-1) && (j != gridsize-2) && (roomVector2[i][j+2].wumpus_present == 1)) {
						roomVector2[i][j+2].wumpus_present = 0;
						roomVector2[i][j+2].set_event(5);
						cout << endl << "You hear a deafening roar followed by a thud as the Wumpus falls to the ground, dead." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
					}
					else if ((j != gridsize-1) && (j != gridsize-2) && (j != gridsize-3) && (roomVector2[i][j+3].wumpus_present == 1)) {
						roomVector2[i][j+3].wumpus_present = 0;
						roomVector2[i][j+3].set_event(5);
						cout << endl << "You hear a deafening roar followed by a thud as the Wumpus falls to the ground, dead." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
					}
					else {
						cout << endl << "You hear your arrow clatter to the ground in the distance, followed by the rapid pounding of paws against pavement..." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
						move_wumpus();
					}
				}
			}
		}
	}
	else
		cout << endl << "You are out of arrows..." << endl;
}

void Game::fire_west() {
	if (arrow_count > 0) {
		arrow_count--;
		for (int i = 0; i < gridsize; i++) {
			for (int j = 0; j < gridsize; j++) {
				if (roomVector2[i][j].player_present == 1) {
					if (i != 0 && roomVector2[i - 1][j].wumpus_present == 1) {
						roomVector2[i - 1][j].wumpus_present = 0;
						roomVector2[i - 1][j].set_event(5);
						cout << endl << "You hear a deafening roar followed by a thud as the Wumpus falls to the ground, dead." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
					}
					else if ((i != 0) && (i != 1) && (roomVector2[i - 2][j].wumpus_present == 1)) {
						roomVector2[i - 2][j].wumpus_present = 0;
						roomVector2[i - 2][j].set_event(5);
						cout << endl << "You hear a deafening roar followed by a thud as the Wumpus falls to the ground, dead." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
					}
					else if ((i != 0) && (i != 1) && (i != 2) && (roomVector2[i - 3][j].wumpus_present == 1)) {
						roomVector2[i - 3][j].wumpus_present = 0;
						roomVector2[i - 3][j].set_event(5);
						cout << endl << "You hear a deafening roar followed by a thud as the Wumpus falls to the ground, dead." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
					}
					else {
						cout << endl << "You hear your arrow clatter to the ground in the distance, followed by the rapid pounding of paws against pavement..." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
						move_wumpus();
					}
				}
			}
		}
	}
	else 
		cout << endl << "You are out of arrows..." << endl;
}

void Game::fire_south() {
	if (arrow_count > 0) {
		arrow_count--;
		for (int i = 0; i < gridsize; i++) {
			for (int j = 0; j < gridsize; j++) {
				if (roomVector2[i][j].player_present == 1) {
					if (i != gridsize - 1 && roomVector2[i+1][j].wumpus_present == 1) {
						roomVector2[i+1][j].wumpus_present = 0;
						roomVector2[i+1][j].set_event(5);
						cout << endl << "You hear a deafening roar followed by a thud as the Wumpus falls to the ground, dead." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
					}
					else if ((i != gridsize - 1) && (i != gridsize - 2) && (roomVector2[i+2][j].wumpus_present == 1)) {
						roomVector2[i+2][j].wumpus_present = 0;
						roomVector2[i+2][j].set_event(5);
						cout << endl << "You hear a deafening roar followed by a thud as the Wumpus falls to the ground, dead." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
					}
					else if ((i != gridsize - 1) && (i != gridsize - 2) && (i != gridsize - 3) && (roomVector2[i+3][j].wumpus_present == 1)) {
						roomVector2[i+3][j].wumpus_present = 0;
						roomVector2[i+3][j].set_event(5);
						cout << endl << "You hear a deafening roar followed by a thud as the Wumpus falls to the ground, dead." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
					}
					else {
						cout << endl << "You hear your arrow clatter to the ground in the distance, followed by the rapid pounding of paws against pavement..." << endl << endl;
						cout << "You have " << arrow_count << " arrows remaining..." << endl;
						move_wumpus();
					}
				}
			}
		}
	}
	else
		cout << endl << "You are out of arrows..." << endl;
}

void Game::win_condition() {
	for (int i = 0; i < gridsize; i++) {
		for (int j = 0; j < gridsize; j++) {
			if (roomVector2[i][j].player_present == 1) {
				if (roomVector2[i][j].escape_rope == 1 && has_gold == 1) {
					cout << endl << endl << "Way to go!!! You got the gold and escaped from the cave! You win!" << endl << endl;
					exit(1);
				}
			}
		}
	}
}

void Game::check_adjacent() {
	int flag = 1;
	for (int i = 0; i < gridsize; i++) {
		for (int j = 0; j < gridsize; j++) {
			if (roomVector2[i][j].player_present == 1 && roomVector2[i][j].bats_present != 1) {
				if (i != gridsize - 1) {
					roomVector2[i + 1][j].run_percept();
					flag = 0;
				}
				if (i != 0) {
					roomVector2[i-1][j].run_percept();
				}
				if (j != gridsize && j != gridsize - 1 ) {
					roomVector2[i][j + 1].run_percept();
					flag = 0;
				}
				if (j != 0) {
					roomVector2[i][j - 1].run_percept();
				}
			}
		}
	}
}

void Game::encounter_checker() {
	for (int i = 0; i < gridsize; i++) {
		for (int j = 0; j < gridsize; j++) {
			if (roomVector2[i][j].player_present == 1) {
				if (roomVector2[i][j].gold_present == 1) {
					roomVector2[i][j].gold_present == 0;
					roomVector2[i][j].set_event(5);
					has_gold = 1;

				}
				else if (roomVector2[i][j].bats_present == 1) {
					bats_move_player();
				}
			}
		}
	}
}


void Game::bats_move_player() {
	int i1, i2;
	int cont = 1;
	int flag = 0;
	for (int i = 0; i < gridsize; i++) {
		for (int j = 0; j < gridsize; j++) {
			if (roomVector2[i][j].player_present == 1) {
				roomVector2[i][j].player_present = 0;
				while (cont == 1) {
					i1 = rand() % (gridsize);
					i2 = rand() % (gridsize);
					if (roomVector2[i1][i2].event_present == 0) {
						roomVector2[i1][i2].player_present = 1;
						cont = 0;
					}
				}
			}
			if (cont == 0)
				break;
		}
		if (cont == 0)
			break;
	}
	check_adjacent();
}

void Game::print_grid() {
	for (int i = 0; i < gridsize; i++)
		cout << "+===+";
	cout << endl;

	for (int i = 0; i < gridsize; i++) {
		for (int j = 0; j < gridsize; j++) {
			print_room_content(i, j);
		}
		cout << endl;
		for (int i = 0; i < gridsize; i++)
			cout << "+===+";
		cout << endl;
	}
	cout << endl << endl;
	player_move();
}

void Game::print_room_content(int i, int j) {

	if (gamemode == 1) {
		if (roomVector2[i][j].player_present == 1) {
			cout << "|" << " X " << "|";
		}
		else if (roomVector2[i][j].wumpus_present == 1) {
			cout << "|" << " W " << "|";
		}
		else if (roomVector2[i][j].gold_present == 1) {
			cout << "|" << " G " << "|";
		}
		else if (roomVector2[i][j].bats_present == 1) {
			cout << "|" << " B " << "|";
		}
		else if (roomVector2[i][j].pits_present == 1) {
			cout << "|" << " P " << "|";
		}
		else {
			cout << "|" << "   " << "|";
		}
	}
	else {
		if (roomVector2[i][j].player_present == 1) {
			cout << "|" << " X " << "|";
		}
		else {
			cout << "|" << "   " << "|";
		}
	}
}
