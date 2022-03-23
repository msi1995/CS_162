using namespace std;
#include "zoo.h"
#include "bear.h"
#include "sealion.h"
#include "tiger.h"
#include "animal.h"
#include <stdio.h>    
#include <stdlib.h>     
#include <time.h>       

//Default Constructor
Zoo::Zoo() {
	tiger_arr = NULL;
	bear_arr = NULL;
	sealion_arr = NULL;
}

//Destructor
Zoo::~Zoo() {
	if (tiger_arr != NULL)
		delete[] tiger_arr;

	if (bear_arr != NULL)
		delete[] bear_arr;

	if (sealion_arr != NULL)
		delete[] sealion_arr;
}

int Zoo::get_int() {
	string t;
	bool f;
	while (true) {
		f = true;
		cin >> t;

		for (int i = 0; i < t.length(); i++) {
			if (t[i] == 45) {
				if (i != 0 || t.length() == 1)
					f = false;
			}
			else if (t[i] < 48 || t[i] > 57) {
				f = false;
			}
		}
		if (f == true)
			return atoi(t.c_str());
		cout << "Not an int, please enter a valid int" << endl;
	}
}

void Zoo::start() {
	bool f = true;
	int choice;
	while (f == true) {
		cout << endl << "Welcome to your zoo! You have $100,000 and no animals yet." << endl;
		cout << "You may buy up to two animals per turn, but only 1 species per turn." << endl << endl;
		cout << "Because it is your first turn, you have to buy something." << endl << endl;
		cout << "Press 1 to buy tigers. ($12,000)" << endl << "Press 2 to buy bears. ($5,000)" << endl << "Press 3 to buy sea lions. ($700) ";

		choice = get_int();
		if ((choice == 1) || (choice == 2) || (choice == 3)) {
			f = false;
		}

	}
	purchase_animal(choice, money);
	add_animal_to_array(choice, pt_numBuy, tiger_tracker, bear_tracker, sealion_tracker);
}


void Zoo::choose_animal() {
	bool f = true;
	int choice;
	while (f == true) {
		cout << "Press 0 to skip turn" << endl << "Press 1 to buy tigers. ($12,000)" << endl << "Press 2 to buy bears. ($5,000)" << endl << "Press 3 to buy sea lions. ($700)" << endl << "Press 4 to quit." << endl << endl;
		choice = get_int();
		if ((choice == 0) || (choice == 1) || (choice == 2) || (choice == 3) || (choice == 4)) {
			f = false;
		}

	}
	purchase_animal(choice, money);
	add_animal_to_array(choice, pt_numBuy, tiger_tracker, bear_tracker, sealion_tracker);
}

void Zoo::purchase_animal(int& choice, int& money) {
	if (choice == 1) {
		cout << "How many tigers do you want to buy? Max 2: ";
		numBuy = get_int();
			if (numBuy != 1 && numBuy != 2) {
				numBuy = 2;
				cout << "Invalid choice. Choice set to 2." << endl << endl;
			}
		money = money - (12000 * numBuy);
	}
	if (choice == 2) {
		cout << "How many bears do you want to buy? Max 2: ";
		numBuy = get_int();
			if (numBuy != 1 && numBuy != 2) {
				numBuy = 2;
				cout << "Invalid choice. Choice set to 2." << endl << endl;
			}
		money = money - (5000 * numBuy);
	}
	if (choice == 3) {
		cout << "How many sealions do you want to buy? Max 2: ";
		numBuy = get_int();
			if (numBuy != 1 && numBuy != 2) {
				numBuy = 2;
				cout << "Invalid choice. Choice set to 2." << endl << endl;
			}
		money = money - (700 * numBuy);
	}
	if (choice == 4) {
		exit(1);
	}
}


int Zoo::add_animal_to_array(int choice, int* pt_numBuy, int& tiger_tracker, int& bear_tracker, int& sealion_tracker)
{
	if (choice == 1) {
		for (int i = 0; i < *pt_numBuy; i++) {
			bought_tigers();
		}
	}
	if (choice == 2) {
		for (int i = 0; i < *pt_numBuy; i++) {
			bought_bears();
		}
	}
	if (choice == 3) {
		for (int i = 0; i < *pt_numBuy; i++) {
			bought_sealions();
		}
	}
	month_pass();
}

void Zoo::month_pass() {
	check_money();
	Tiger tiger;
	Bear bear;
	Sealion sealion;
	srand(time(NULL));

	int food_cost = (tiger_tracker * 5 * tiger.get_food_cost()) + (bear_tracker * 3 * bear.get_food_cost()) + (sealion_tracker * sealion.get_food_cost());
	
	money = money + ((tiger_tracker * 1200) + (bear_tracker * 500) + (sealion_tracker * 140) + (baby_tiger_tracker * 1200) + (baby_bear_tracker * 500) + (baby_sealion_tracker * 140) - food_cost);

	cout << endl << "______________________________________________________________________________________________" << endl;
	for (int i = 0; i < tiger_tracker; i++) {
		tiger_arr[i].increment_age();
		//cout << "Tiger " << i + 1 << " is " << tiger_arr[i].get_age() << " months old" << endl;
		if (tiger_arr[i].get_age() == 7) {
			baby_tiger_tracker--;
		}
	}
	for (int i = 0; i < bear_tracker; i++) {
		bear_arr[i].increment_age();
		//cout << "Bear " << i + 1 << " is " << bear_arr[i].get_age() << " months old" << endl;
		if (bear_arr[i].get_age() == 7)
			baby_bear_tracker--;
	}
	for (int i = 0; i < sealion_tracker; i++) {
		sealion_arr[i].increment_age();
		//cout << "Sealion " << i + 1 << " is " << sealion_arr[i].get_age() << " months old" << endl;
		if (sealion_arr[i].get_age() == 7)
			baby_sealion_tracker--;
	}


	int random_event = rand() % 4;
	
	if (random_event == 0) {
		cout << endl << "No event occurred this month." << endl << endl;
	}
	if (random_event == 1) {
		attendance_boom();
	}
	if (random_event == 2) {
		birth_event();
	}
	if (random_event == 3) {
		animal_sick();
	}
	print_money(food_cost);
	choose_animal();
}

void Zoo::attendance_boom() {
	int x = 0;
	sealion_bonus = 0;
	for (int i = 0; i < sealion_tracker; i++) {
		x = rand() % 150 + 250;
			sealion_bonus += x;
	}
	money = money + sealion_bonus;
	cout << endl << "There was a boom in attendance! Your " << sealion_tracker << " sea lions earned an extra $" << sealion_bonus << " this month." << endl << endl;
}

void Zoo::birth_event() {
	int tiger_range = tiger_tracker - baby_tiger_tracker;
	int bear_range = tiger_tracker + bear_tracker - baby_tiger_tracker - baby_bear_tracker;
	int sealion_range = tiger_tracker + bear_tracker + sealion_tracker - baby_tiger_tracker - baby_bear_tracker - baby_sealion_tracker;
	int birth_animal = rand() % sealion_range + 1;
	if (tiger_tracker > 1 && (birth_animal <= tiger_range)) {
		baby_tiger();
		baby_tiger();
		baby_tiger();
		cout << "Three baby tigers have been born!" << endl << endl;
	}
	if ((bear_tracker > 1) && (birth_animal > tiger_range) && (birth_animal <= bear_range)) {
		baby_bear();
		baby_bear();
		cout << "Two baby bears have been born!" << endl << endl;
	}
	if ((sealion_tracker > 1) && (birth_animal > bear_range) && (birth_animal <= sealion_range)) {
		baby_sealion();
		cout << "A baby sealion has been born!" << endl << endl;
	}
	if ((tiger_tracker <= 1) && (bear_tracker <= 1) && (sealion_tracker <= 1)){
		cout << "A birth event occurred, but no animals were eligible to give birth." << endl << endl;
	}
}

void Zoo::animal_sick() {
	int tiger_range = tiger_tracker;
	int bear_range = tiger_tracker + bear_tracker;
	int sealion_range = tiger_tracker + bear_tracker + sealion_tracker;
	int sick_animal = rand() % sealion_range;
		if (sick_animal < tiger_range) {
			if (money <= 12000) {
				cout << endl << "A tiger has fallen ill. You could not afford treatment so it died." << endl;
				kill_tiger();
			}
				if (money > 12000) {
					cout << endl << "A tiger has fallen ill. $6000 has been deducted to nurse your tiger back to health." << endl;
					money = money - 6000;
				}
		}
		if (sick_animal > tiger_range && sick_animal <= bear_range) {
			if (money <= 5000) {
				cout << "A bear has fallen ill. You could not afford treatment so it died." << endl;
				kill_bear();
				}
				if (money > 5000) {
					cout << endl << "A bear has fallen ill. $2500 has been deducted to nurse your bear back to health." << endl;
					money = money - 2500;
				}
		}
		if (sick_animal > bear_range && sick_animal <= sealion_range) {
			if (money <= 700) {
				cout << "A sea lion has fallen ill. You could not afford treatment so it died." << endl;
				kill_sealion();
			}
				if (money > 700) {
					cout << endl << "A sea lion has fallen ill. $350 has been deducted to nurse your sea lion back to health." << endl;
				money = money - 350;
				}
		}
}


void Zoo::check_money() {
	if (money <= 0) {
		cout << endl << endl << "Oh no! Your zoo has gone bankrupt and must close! Better luck next time..." << endl << endl;
		exit(1);
	}
}


void Zoo::print_money(int food_cost) {
	cout << endl << endl << "Total tigers: " << tiger_tracker << endl << "Baby tigers: " << baby_tiger_tracker << endl;
	cout << "Total bears: " << bear_tracker << endl << "Baby bears: " << baby_bear_tracker << endl;
	cout << "Total sea lions: " << sealion_tracker << endl << "Baby sea lions: " << baby_sealion_tracker << endl;
	cout << endl << "Current Balance: $" << money << ". Your food cost last month was $" << food_cost;
	cout << ". Your revenue last month was $" << (tiger_tracker * 1200) + (bear_tracker * 500) + (sealion_tracker * 140) + (baby_tiger_tracker * 1200) + (baby_bear_tracker * 500) + (baby_sealion_tracker * 140) + (sealion_bonus);
	cout << "." << endl << "$" << (baby_tiger_tracker * 1200) + (baby_bear_tracker * 500) + (baby_sealion_tracker * 140) << " of this was extra revenue from baby animals. $" << sealion_bonus << " of this was from an attendance boom." << endl << endl;
	sealion_bonus = 0;
}


void Zoo::bought_tigers() {

	Tiger tiger1;
	int size = tiger_tracker;
	tiger_tracker++;
	tiger_temp = new Tiger[tiger_tracker];


	if(size > 0)
		for (int i = 0; i < size; i++) 
			tiger_temp[i] = tiger_arr[i];

		delete[] tiger_arr;


	tiger_arr = new Tiger[tiger_tracker];

	for (int i = 0; i < tiger_tracker; i++)
		tiger_arr[i] = tiger_temp[i];

	delete[] tiger_temp;

}

void Zoo::kill_tiger() {

	int size = tiger_tracker;
	tiger_tracker--;
	tiger_temp = new Tiger[tiger_tracker];


	if (size > 0)
		for (int i = 0; i < size-1; i++)
			tiger_temp[i] = tiger_arr[i];

	delete[] tiger_arr;


	tiger_arr = new Tiger[tiger_tracker];

	for (int i = 0; i < tiger_tracker; i++)
		tiger_arr[i] = tiger_temp[i];

	delete[] tiger_temp;

}


void Zoo::baby_tiger() {

	Tiger tiger1(0);
	int size = tiger_tracker;
	tiger_tracker++;
	baby_tiger_tracker++;
	tiger_temp = new Tiger[tiger_tracker];


	if (size > 0)
		for (int i = 0; i < size; i++)
			tiger_temp[i] = tiger_arr[i];

	delete[] tiger_arr;
	tiger_temp[tiger_tracker - 1] = tiger1;

	tiger_arr = new Tiger[tiger_tracker];

	for (int i = 0; i < tiger_tracker; i++)
		tiger_arr[i] = tiger_temp[i];

	delete[] tiger_temp;

}

void Zoo::baby_bear() {

	Bear bear1(0);
	int size = bear_tracker;
	bear_tracker++;
	baby_bear_tracker++;
	bear_temp = new Bear[bear_tracker];


	if (size > 0)
		for (int i = 0; i < size; i++)
			bear_temp[i] = bear_arr[i];

	delete[] bear_arr;

	bear_temp[bear_tracker - 1] = bear1;

	bear_arr = new Bear[bear_tracker];

	for (int i = 0; i < bear_tracker; i++)
		bear_arr[i] = bear_temp[i];

	delete[] bear_temp;

}

void Zoo::kill_bear() {

	int size = bear_tracker;
	bear_tracker--;
	bear_temp = new Bear[bear_tracker];


	if (size > 0)
		for (int i = 0; i < size - 1; i++)
			bear_temp[i] = bear_arr[i];

	delete[] bear_arr;


	bear_arr = new Bear[bear_tracker];

	for (int i = 0; i < bear_tracker; i++)
		bear_arr[i] = bear_temp[i];

	delete[] bear_temp;

}


void Zoo::baby_sealion() {

	Sealion sealion1(0);
	int size = sealion_tracker;
	sealion_tracker++;
	baby_sealion_tracker++;
	sealion_temp = new Sealion[sealion_tracker];


	if (size > 0)
		for (int i = 0; i < size; i++)
			sealion_temp[i] = sealion_arr[i];

	delete[] sealion_arr;

	sealion_temp[sealion_tracker - 1] = sealion1;

	sealion_arr = new Sealion[sealion_tracker];

	for (int i = 0; i < sealion_tracker; i++)
		sealion_arr[i] = sealion_temp[i];

	delete[] sealion_temp;

}

void Zoo::bought_bears() {

	Bear bear1;
	int size = bear_tracker;
	bear_tracker++;
	bear_temp = new Bear[bear_tracker];


	if (size > 0)
		for (int i = 0; i < size; i++)
			bear_temp[i] = bear_arr[i];

	delete[] bear_arr;

	bear_arr = new Bear[bear_tracker];

	for (int i = 0; i < bear_tracker; i++)
		bear_arr[i] = bear_temp[i];

	delete[] bear_temp;

}

void Zoo::bought_sealions() {

	Sealion sealion1;
	int size = sealion_tracker;
	sealion_tracker++;
	sealion_temp = new Sealion[sealion_tracker];


	if (size > 0)
		for (int i = 0; i < size; i++)
			sealion_temp[i] = sealion_arr[i];

	delete[] sealion_arr;

	sealion_arr = new Sealion[sealion_tracker];

	for (int i = 0; i < sealion_tracker; i++)
		sealion_arr[i] = sealion_temp[i];

	delete[] sealion_temp;

}

void Zoo::kill_sealion() {

	int size = sealion_tracker;
	sealion_tracker--;
	sealion_temp = new Sealion[sealion_tracker];


	if (size > 0)
		for (int i = 0; i < size - 1; i++)
			sealion_temp[i] = sealion_arr[i];

	delete[] sealion_arr;


	sealion_arr = new Sealion[sealion_tracker];

	for (int i = 0; i < sealion_tracker; i++)
		sealion_arr[i] = sealion_temp[i];

	delete[] sealion_temp;

}