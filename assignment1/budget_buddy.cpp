/******************************************************
** Program: budget_buddy.cpp
** Author: Doug Lloyd
** Date: 01/16/2020
** Description: Takes in a budget text file and user text file and creates 
	a database of this information. Prompts user for login and checks login
	against user database. Matches transaction information from budget file
	with logged in user, and allows them to sort their transactions in 
	various ways. Allows the information to be printed to the terminal
	or outputted to a file with a name of the user's choice. Repeats if the
	user chooses to perform another sort.
** Input: Two text files supplied via command line and various user input throughout the program
	for choices about functionality
** Output: Outputs information to terminal or text file (user choice) that has been sorted
	by date, category, or dollar amount (user choice). 
******************************************************/

#include "budget_header.h"


int main(int argc, char** argv) {
	int count, count2, userid, id_personal, userchoice, login_fail = 0;
	int* login_fail_int = &login_fail;
	string username_personal, password;
	ifstream user_file, budget_file;
	ofstream out_file;




	bad_command(argc, argv);

	budget_file.open(argv[2]);
	budget_file >> count;
	budget* budget_db = create_budgets(count);
	get_budget_data(budget_db, count, budget_file);

	user_file.open(argv[1]);
	user_file >> count2;
	user* user_db = create_users(count2);


	get_user_data(user_db, count2, user_file);
	login_loop(user_db, userid, password, count2, login_fail_int, id_personal, username_personal);
	cout << endl << "Logged in!" << endl << "Username: " << username_personal << " || ID: " << id_personal << endl << endl;
	userchoice_flow(budget_db, id_personal, count);



	while (true)
		userchoice_flow(budget_db, id_personal, count);



	delete_info(user_db, count2, budget_db, count);


	return 0;
}