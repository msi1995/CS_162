/******************************************************
** Program: Wumpus
** Author: Doug Lloyd
** Date: 02/28/2020
** Description: Plays Hunt the Wumpus. The goal of the game
is to move your player through the labyrinth (in this case
a 2D Vector with visual representation via squares in the
terminal), collect the gold, and escape. The labyrinth
has numerous hazards including the Wumpus which can 
randomly move if you miss your arrow. The player can move
by pressing w/a/s/d and shoot by pressing space followed by
w/a/s/d. Hints are given when nearing hazards.
** Input: Terminal input w/a/s/d (no enter key needed)
** Output: Output to terminal of 2D Vector represented
by box couts as well as game hints and prompts in text 
form.
******************************************************/

#include "room.h"
#include "game.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <stdio.h>      
#include <stdlib.h>     
using namespace std;
using std::vector;



int main(int argc, char** argv) {
	srand(time(NULL));
	int gridsize = atoi(argv[1]);
	Game Wumpus(gridsize);

	if (string(argv[2]) == "true") {
		Wumpus.create_grid(1);
	}
	if (string(argv[2]) == "false") {
		Wumpus.create_grid(0);
	}
	if (string(argv[2]) == "expert") {
		Wumpus.create_grid(2);
	}

	return 0;
}