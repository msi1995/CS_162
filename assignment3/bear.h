#pragma once
#include "sealion.h"

class Bear : public Animal {

private:

public:

	//default constructor
	Bear();

	//destructor
	~Bear();

	//Alternate constructor used for babies that takes int
	// Used to set baby age to 0 months
	Bear(int);

	//Assignment operator overload for Bear
	Bear& operator=(const Bear&);

};