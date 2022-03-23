#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Card {
private:
	int suit = 1000;
	int rank = 1000;
public:
	Card();
	~Card();

	void set_suit(int);
	void set_rank(int);
	int get_suit();
	int get_rank();
};