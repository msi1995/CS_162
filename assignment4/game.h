#include "bats.h"
#include "gold.h"
#include "pit.h"
#include "wumpus.h"
#include "event.h"
#include "room.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdio.h>      
#pragma once

#include <stdlib.h> 
using namespace std;
using std::vector;

class Game {
private:
	int gamemode;

public:
	int has_gold = 0;
	int arrow_count = 3;
	int wumpus_alive = 1;
	int gridsize;

	vector<vector<Room>> roomVector2;


	//Default constructor
	Game();

	//Default constructor
	Game(int);

	//Default destructor
	~Game();


	/*This function just changes the private gamemode int 
	to 1 (debug) or 0 (normal). My print_room_content function
	runs a check on gamemode and only prints the contents of the
	rooms if gamemode is 1. */
	void set_gamemode(int);


	/*This function creates a 2D vector (vector of vectors)
	and prints out game instructions.*/
	void create_grid(int);


	/*This function prints out empty square grids that form the 
	cave labyrinth. Calls the print_room_content function
	in the center of the box. print_room_content will add 
	anything in the middle of the room that should be there. */
	void print_grid();


	/*Prints player location as an X within the grid, and locations of 
	all other events if gamemode int is 1. Only prints player location
	if int is 0.*/
	void print_room_content(int, int);

	/*This function randomly places the player in the grid,
	and modifies the escape_rope, event_present, and player_present
	values to show that these are all in this room at the time.*/
	void place_player();

	/*This function randomly places the wumpus in the grid,
	and modifies the event_present, and wumpus_present
	values to show that these are all in this room at the time.
	Will run again if the random values place it on top of another
	event. */
	void place_wumpus();

	/*This function randomly places the pits in the grid,
	and modifies the event_present, and pits_present
	values to show that these are all in this room at the time.
	Will run again if the random values place pits on top of another
	event. */
	void place_pits();

	/*This function randomly places the gold in the grid,
	and modifies the event_present, and gold_present
	values to show that these are all in this room at the time.
	Will run again if the random values place it on top
	of another event.*/
	void place_gold();

	/*This function randomly places the bats in the grid,
	and modifies the event_present, and bats_present
	values to show that these are all in this room at the time.
	Will run again if the random values place them on top
	of another event.*/
	void place_bats();

	/*This function is just a container for all of the place functions
	above. It calls place_bats 2x, place_pits 2x, place_player,
	place_wumpus, and place_gold.*/
	void populate_all();

	/*This function handles all of the movement or firing of arrows
	that the player can do. It also handles raw input so that
	you don't have to press enter to do any movements. Allows quitting
	the game by pressing z at any point. Also calls win_condition(),
	check_adjacent(), encounter_checker(), and print_grid(). */
	void player_move();

	/*This function handles movement when the player encounters bats in
	the labyrinth. Randomly moves the player to a location in the grid
	NOT containing an event. The bats do not move. */
	void bats_move_player();

	/*This function runs a check every time the player moves to 
	see if has_gold == 1 and escape_rope == 1. This effectively
	checks if the player has gotten the gold and is back in the 
	starting room, which has escape_rope == 1 set at game start. */
	void win_condition();

	/*This function runs a check every time the player moves to
	see if the player has encountered gold or bats (since wumpus
	and pits quit the game from within their functions). If
	the player has encountered gold or bats, sets has_gold to 1
	or calls bats_move_player(). */
	void encounter_checker();

	
	/*This function runs every time the player moves and calls
	the percept() function on the room above, below, left, and
	right of the player. If percept() is called on an empty room,
	nothing happens, so this is fine. */
	void check_adjacent();

	/*This function moves the wumpus to a random different room 
	in the labryinth, but only runs 75% of the time. Uses a simple
	rand() % 4 and doesn't do anything if the value is 3. Will not
	place the Wumpus on another event or the player. */
	void move_wumpus();

	/*This function moves the player north by decrementing 1 from 
	the i index of the player's current position. Checks to make sure
	that the player is not at the northern boundary, as this would
	cause seg fault. */
	void move_north();

	/*This function moves the player east by incrementing 1 to
	the j index of the player's current position. Checks to make sure
	that the player is not at the eastern boundary, as this would
	cause seg fault. */
	void move_east();

	/*This function moves the player west by decrementing 1 from
	the j index of the player's current position. Checks to make sure
	that the player is not at the western boundary, as this would
	cause seg fault. */
	void move_west();

	/*This function moves the player north by incrementing 1 to
	the i index of the player's current position. Checks to make sure
	that the player is not at the southern boundary, as this would
	cause seg fault. */
	void move_south();

	/*This function fires an arrow to the north by finding the player's
	current location and then checking up to 3 spaces in the direction
	the arrow is fired for the presence of Wumpus. Will check less than
	3 spaces if boundary is encountered beforehand to avoid seg fault.
	If wumpus is found, removes wumpus event from room and prints
	special messages to terminal.*/
	void fire_north();

	/*This function fires an arrow to the east by finding the player's
	current location and then checking up to 3 spaces in the direction
	the arrow is fired for the presence of Wumpus. Will check less than
	3 spaces if boundary is encountered beforehand to avoid seg fault.
	If wumpus is found, removes wumpus event from room and prints
	special messages to terminal.*/
	void fire_east();

	/*This function fires an arrow to the west by finding the player's
	current location and then checking up to 3 spaces in the direction
	the arrow is fired for the presence of Wumpus. Will check less than
	3 spaces if boundary is encountered beforehand to avoid seg fault.
	If wumpus is found, removes wumpus event from room and prints
	special messages to terminal.*/
	void fire_west();

	/*This function fires an arrow to the south by finding the player's
	current location and then checking up to 3 spaces in the direction
	the arrow is fired for the presence of Wumpus. Will check less than
	3 spaces if boundary is encountered beforehand to avoid seg fault.
	If wumpus is found, removes wumpus event from room and prints
	special messages to terminal.*/
	void fire_south();
};