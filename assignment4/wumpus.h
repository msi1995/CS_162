#pragma once
#include "event.h"

class Wumpus : public Event {

private:

public:

	//This percept function prints a percept statement to the terminal when called. 
	//It is derived polymorphically from the pure virtual percept() in event.
	void percept();

	//This encounter function prints the encounter statement to the terminal when called. 
	//It is derived polymorphically from the pure virtual encounter() in event. It ends the game, as well.
	void encounter();

	//Default constructor
	Wumpus();

	//Default destructor
	~Wumpus();
};