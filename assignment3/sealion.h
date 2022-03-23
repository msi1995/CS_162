#pragma once
#include "tiger.h"

class Sealion : public Animal {

private:

public:

	//Default Constructor
	Sealion();

	//Destructor
	~Sealion();

	//Alternate constructor used for babies that takes int
	// Used to set baby age to 0 months
	Sealion(int);

	//Assignment operator overload for sealion
	Sealion& operator=(const Sealion&);

};