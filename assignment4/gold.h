#pragma once
#include "pit.h"
#include "wumpus.h"
#include "event.h"


class Gold : public Event {

private:

public:

	//This percept function prints a percept statement to the terminal when called. 
	//It is derived polymorphically from the pure virtual percept() in event.
	void percept();

	//This encounter function prints the encounter statement to the terminal when called. 
	//It is derived polymorphically from the pure virtual encounter() in event.
	void encounter();

	//Default constructor
	Gold();

	//Default destructor
	~Gold();
};