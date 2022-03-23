#pragma once
#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"
#include "event.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdio.h>      
#include <stdlib.h> 
using namespace std;
using std::vector;

class Room {

private:


public:

	/*This pointer is used so that the proper percept() and encounter()
	functions can be called, since each room contains an event. The
	pointer points to whatever event (bats, pit, gold, wumpus) that
	it has been assigned to and so the corresponding function is called.*/
	Event* eventptr;

	/*These are all variables that I use to keep track of things 
	within the labyrinth.*/
	int event_present = 0;
	int player_present = 0;
	int wumpus_present = 0;
	int bats_present = 0;
	int pits_present = 0;
	int gold_present = 0;
	int escape_rope = 0;

	/*This function sets the event pointer. The int it takes
	in is used to decide which event is pointed to.
	For example, roomVector2[1][1].set_event(1) would
	give the room at [1][1] an eventptr pointing to Gold.*/
	void set_event(int); 

	/* This function checks to see if the room that it was 
	called on has a non-NULL eventptr, and if it does, 
	runs the event by doing eventptr -> encounter(). I call
	this every time a player moves on the room they just 
	moved to. If the room has a NULL eventptr the function doesnt
	do anything. */
	void run_encounter();

	/* This function checks to see if the room that it was
	called on has a non-NULL eventptr, and if it does,
	runs the percept by doing eventptr -> percept(). I call
	this every time a player moves on the room they just
	moved to. If the room has a NULL eventptr the function doesnt
	do anything. */
	void run_percept();

	//Default constructor
	Room();

	//Default destructor
	~Room();
};