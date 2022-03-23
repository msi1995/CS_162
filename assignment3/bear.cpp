using namespace std;
#include "bear.h"

//Default Constructor
Bear::Bear() {

}

//Destructor
Bear::~Bear() {

}

//Alternate constructor for babies. Pass in 0 and age is set to 0
//I have a special function for generating babies where it is called as bear(0).
Bear::Bear(int x) {
	set_age(x);
}


Bear& Bear::operator=(const Bear& bear) {
	this->age_months = bear.age_months;
	this->base_food_cost = bear.base_food_cost;

	return *this;

}