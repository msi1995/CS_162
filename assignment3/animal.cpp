using namespace std;

#include "animal.h"

//Default Constructor
Animal::Animal() {

}

//Destructor
Animal::~Animal() {

}

int Animal::get_age() {

	return age_months;
}

void Animal::increment_age() {
	age_months++;
}

void Animal::set_age(int new_age) {
	age_months = new_age;
}

int Animal::get_food_cost() {
	int x = rand() % 41 + 80;
	float z = x * 0.01;
	return base_food_cost * z;
}