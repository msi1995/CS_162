#include "room.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdio.h>      
#include <stdlib.h>  
#include "pit.h"
using namespace std;

Room::Room() {
	eventptr = NULL;
}

Room::~Room() {

}

// 1 - gold , 2 - pit, 3 - wumpus, 4 - bats 5 - reset
void Room::set_event(int choice) {

	if (choice == 1) {
		eventptr = new Gold;
	}else if (choice == 2) {
		eventptr = new Pit;
	}else if (choice == 3) {
		eventptr = new Wumpus;
	}else if (choice == 4) {
		eventptr = new Bats;
	}
	else if (choice == 5) {
		eventptr = NULL;
	}

}

void Room::run_encounter() {

	if (eventptr != NULL)
		eventptr->encounter();
	else
		cout << endl << "You enter the room, but nothing is inside..." << endl << endl;

}

void Room::run_percept() {
	if (eventptr != NULL)
		eventptr->percept();
	else
		return;
}