using namespace std;
#include "sealion.h"

//Default Constructor
Sealion::Sealion() {

}

//Destructor
Sealion::~Sealion() {

}

//Alternate constructor for babies. Pass in 0 and age is set to 0
//I have a special function for generating babies where it is called as sealion(0).
Sealion::Sealion(int x) {
	set_age(x);
}


Sealion& Sealion::operator=(const Sealion& sealion) {
	this->age_months = sealion.age_months;
	this->base_food_cost = sealion.base_food_cost;

	return *this;

}