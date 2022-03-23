#pragma once
#include <iostream>

class Event{

private:

public:

	//Default constructor
	Event();

	//Default destructor
	~Event();

	//Pure virtual function that will be used by bats, pit, gold, and wumpus
	//No functionality in the event class.
	virtual void percept() = 0;

	//Pure virtual function that will be used by bats, pit, gold, and wumpus
	//No functionality in the event class.
	virtual void encounter() = 0;
};