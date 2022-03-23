#pragma once
#include "bear.h"
#include "sealion.h"
#include "tiger.h"
#include "animal.h"

class Zoo{


private:
	//Initial array pointers for tiger, sealion, and bear. temp arrays are used when
	//increasing array size (new animal) or shrinking array (sick animal
	// dies). Temp is used to copy.

	Tiger* tiger_arr;
	Tiger* tiger_temp;
	Sealion* sealion_arr;
	Sealion* sealion_temp;
	Bear* bear_arr;
	Bear* bear_temp;

public:

	//Default Constructor
	Zoo();

	//Destructor
	~Zoo();

	//Initial player balance
	int money = 100000;

	//Trackers for all animals and babies of the species. These
	//are used to keep track of the number of adult and baby
	//animals for each species.
	int bear_tracker = 0;
	int sealion_tracker = 0;
	int tiger_tracker = 0;
	int baby_bear_tracker = 0;
	int baby_sealion_tracker = 0;
	int baby_tiger_tracker = 0;

	//Monthly sea lion bonus revenue value
	int sealion_bonus = 0;

	//numBuy is the amount of a certain species a user chooses to buy
	//once they select the species. For example, the program will ask
	//how many tigers the user wants to buy and the user responds 2,
	//numBuy will be 2.
	int numBuy;
	int* pt_numBuy = &numBuy;




/*********************************************************************
** Function: start()
** Description: This initializes the zoo game, prints out starting 
	information to the user, and forces them to buy an animal (no 
	skipping turn allowed on first turn)
** Parameters: none
*********************************************************************/
	void start();



/*********************************************************************
** Function: get_int()
** Description: This function prompts the user for an int and runs
	various checks to ensure the entered value is an int ONLY. Will
	reprompt until an int is entered.
** Parameters: none
*********************************************************************/
	int get_int();



/*********************************************************************
** Function: choose_animal()
** Description: This function prompts the user to choose which animal
	they would like to buy, as well as printing out the price of each
	animal. Also allows the choice to skip a turn.
** Parameters: int&, int&
*********************************************************************/
	void choose_animal();



	/*********************************************************************
** Function: purchase_animal(int&, int&)
** Description: This function carries on the purchase flow where purchase_animal
	left off. Prompts the user to choose how many of their chosen animal they 
	want to buy, subtracts the amount from their balance, 
** Parameters: int&, int&
*********************************************************************/
	void purchase_animal(int&, int&);



	
	/*********************************************************************
** Function: add_animal_to_array(int, int*, int&, int&, int&)
** Description: This function calls the functions that will actually add
	the purchased animals to the proper array the correct number of times, 
	and calls the month_pass function.
** Parameters: int, int*, int&, int&, int&
*********************************************************************/
	int add_animal_to_array(int, int*, int&, int&, int&);



	/*********************************************************************
** Function: month_pass()
** Description: This is one of the largest/most intensive functions. This
	function ages all animals by 1 month, calculates the food cost and revenue for all 
	animals, and generates the new monthly balance by subtracting food cost
	from any revenue. It checks to see if any babies have aged past 6 months, 
	and decrements the baby counter for that animal if so (since the animal is
	no longer a baby.) It generates a random integer 0-4 and then calls the
	appropriate random event function based on that integer. Lastly, it prints
	the player's balance after all of that has occurred.
** Parameters: none
*********************************************************************/
	void month_pass();


	/*********************************************************************
** Function: attendance_boom()
** Description: Generates a random bonus revenue between $150-$400 for 
	each sea lion the player owns, sums them together, and reports 
	the bonus revenue to the player.
** Parameters: none
*********************************************************************/
	void attendance_boom();


	/*********************************************************************
** Function: birth_event()
** Description: This function checks to see if at least 2 adults of
	a species exist and generates the proper number of babies if 
	so. Randomly chooses between each species if all species have 
	enough adults.
** Parameters: none
*********************************************************************/
	void birth_event();

	/*********************************************************************
** Function: animal_sick()
** Description: Randomly chooses an animal that the player owns to get sick.
	Deducts the proper amount (1/2 animal cost) to heal the sick animal,
	or kills the sick animal (remove from array) if the player cannot
	afford to treat it.
** Parameters: none
*********************************************************************/
	void animal_sick();



	/*********************************************************************
** Function: print_money(int)
** Description: Prints the user's current balance, revenue from the last month,
	bonus revenue from babies and bonus revenue from sea lions during attendance boom.
** Parameters: int
*********************************************************************/
	void print_money(int);

	/*********************************************************************
** Function: check_money()
   Description: Checks every turn to see if the player is bankrupt and ends
	the game if so.
** Parameters: none
*********************************************************************/
	void check_money();

	/*********************************************************************
** Function: bought_tigers()
   Description: Creates a new tiger object, copies old tiger_arr to tiger_temp
   which is 1 size greater than tiger_arr and contains new tiger at last index,
   deletes tiger_arr, and then creates new tiger_arr of appropriate size
   and sets it equal to tiger_temp. (Array resize by copying, adds a tiger
   to array when called).
** Parameters: none
*********************************************************************/
	void bought_tigers();




	/*********************************************************************
** Function: bought_bears()
   Description: Creates a new bear object, copies old bear_arr to bear_temp
   which is 1 size greater than bear_arr and contains new bear at last index,
   deletes bear_arr, and then creates new bear_arr of appropriate size
   and sets it equal to bear_temp. (Array resize by copying, adds a bear
   to array when called.
** Parameters: none
*********************************************************************/
	void bought_bears();




	/*********************************************************************
** Function: bought_sealions()
   Description: Creates a new sealion object, copies old sealion_arr to sealion_temp
	   which is 1 size greater than sealion_arr and contains new sealion at last index,
	   deletes sealion_arr, and then creates new sealion_arr of appropriate size
	   and sets it equal to sealion_temp. (Array resize by copying, adds a sealion
	   to array when called).
** Parameters: none
*********************************************************************/
	void bought_sealions();




	/*********************************************************************
** Function: baby_bear()
   Description: Creates a new baby bear object, copies old bear_arr to bear_temp
   which is 1 size greater than bear_arr and contains new bear at last index,
   deletes bear_arr, and then creates new bear_arr of appropriate size
   and sets it equal to bear_temp. (Array resize by copying, adds a baby bear
   to array when called.
** Parameters: none
*********************************************************************/
	void baby_bear();




	/*********************************************************************
** Function: baby_tiger()
   Description: Creates a new baby tiger object, copies old tiger_arr to tiger_temp
   which is 1 size greater than tiger_arr and contains new tiger at last index,
   deletes tiger_arr, and then creates new tiger_arr of appropriate size
   and sets it equal to tiger_temp. (Array resize by copying, adds a baby tiger
   to array when called).
** Parameters: none
*********************************************************************/
	void baby_tiger();




	/*********************************************************************
** Function: bought_sealions()
   Description: Creates a new baby sealion object, copies old sealion_arr to sealion_temp
	   which is 1 size greater than sealion_arr and contains new sealion at last index,
	   deletes sealion_arr, and then creates new sealion_arr of appropriate size
	   and sets it equal to sealion_temp. (Array resize by copying, adds a baby sealion
	   to array when called).
** Parameters: none
*********************************************************************/
	void baby_sealion();




	/*********************************************************************
** Function: kill_tiger()
   Description: Removes a tiger from the tiger array when called.
	Used for when a player cannot afford to cure a sick animal. Does so
	by resizing the array to respective tracker minus one (cuts off last
	animal in array).
** Parameters: none
*********************************************************************/
	void kill_tiger();




	/*********************************************************************
** Function: kill_bear()
   Description: Removes a bear from the bear array when called.
	Used for when a player cannot afford to cure a sick animal. Does so
	by resizing the array to respective tracker minus one (cuts off last
	animal in array).
** Parameters: none
*********************************************************************/
	void kill_bear();




	/*********************************************************************
** Function: kill_sealion()
   Description: Removes a sealion from the sealion array when called.
	Used for when a player cannot afford to cure a sick animal. Does so
	by resizing the array to respective tracker minus one (cuts off last
	animal in array).
** Parameters: none
*********************************************************************/
	void kill_sealion();

};