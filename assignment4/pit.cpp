#include "pit.h"
#include <iostream>


using namespace std;
Pit::Pit() {

}

Pit::~Pit() {

}

void Pit::encounter() {

	cout << endl << endl << "As you step forward, you realize that there is nowhere to step at all." << endl;
	cout << "You fall to your eventual death." << endl << endl;
	exit(1);


}

void Pit::percept() {

	cout << "You feel a breeze..." << endl << endl;

}