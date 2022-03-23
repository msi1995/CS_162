#pragma once
#include "wumpus.h"
#include "event.h"

class Pit : public Event {

private:

public:

	//This percept function prints a percept statement to the terminal when called. 
	//It is derived polymorphically from the pure virtual percept() in event.
	void percept();

	//This encounter function prints the encounter statement to the terminal when called. 
	//It is derived polymorphically from the pure virtual encounter() in event. It ends the game, as well.
	void encounter();

	//Default constructor
	Pit();

	//Default destructor
	~Pit();
};