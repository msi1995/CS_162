using namespace std;
#include "tiger.h"

//Default Constructor
Tiger::Tiger() {

}

//Destructor
Tiger::~Tiger() {

}

//Alternate constructor for babies. Pass in 0 and age is set to 0
//I have a special function for generating babies where it is called as tiger(0).
Tiger::Tiger(int x) {
	set_age(x);
}


Tiger& Tiger::operator=(const Tiger& tiger) {
	this->age_months = tiger.age_months;
	this->base_food_cost = tiger.base_food_cost;

	return *this;

}