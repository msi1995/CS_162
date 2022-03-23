#include "gold.h"
#include <iostream>
using namespace std;

Gold::Gold() {

}

Gold::~Gold() {

}

void Gold::encounter() {

	cout << endl << endl << "You retrieved the gold! Get back to your starting room and escape!!!" << endl << endl;

}

void Gold::percept() {

	cout << "You see a glimmer nearby..." << endl;

}