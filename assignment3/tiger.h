#pragma once
#include "animal.h"

class Tiger : public Animal {

private:

public:

	//Default Constructor
	Tiger();

	//Destructor
	~Tiger();

	//Alternate constructor used for babies that takes int
	// Used to set baby age to 0 months
	Tiger(int);

	//Assignment operator overload for Tiger
	Tiger& operator=(const Tiger&);
};