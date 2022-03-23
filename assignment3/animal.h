#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Animal {


protected:
	//These are the base ages for adult animals and base food cost
	//these values are used by the specific animal classes later in 
	//the program
	int age_months = 47;
	int base_food_cost = 80;

public:

	//default constructor
	Animal();

	//Destructor
	~Animal();

	//getter for the age_months value
	int get_age();

	//setter for age_months
	void set_age(int);

	//function that increase age of all animals by 1 month when called
	void increment_age();

	//getter for base_food_cost
	int get_food_cost();
};