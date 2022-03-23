#include "room.h"
#include <iostream>
using namespace std;

Wumpus::Wumpus() {

}

Wumpus::~Wumpus() {

}

void Wumpus::encounter() {

	cout << endl << endl << "As you enter the room you hear a horrible noise and heavy footsteps approaching you..." << endl << endl;
	cout << "You attempt to run only to feel your legs torn from your body by the Wumpus." << endl << endl << "Better luck next time..." << endl << endl;
	exit(1);

}

void Wumpus::percept() {

	cout << "You smell a terrible stench and hear heavy breathing..." << endl;

}