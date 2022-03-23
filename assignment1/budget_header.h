
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>

using namespace std;

struct user {
	string name;
	int id;
	string password;
};

struct budget {
	int id;
	float balance;
	int num_transactions;
	struct transaction* t;
};

struct transaction {
	float amount;
	string date;
	string category;
	string description;
};


/*********************************************************************
** Function: bad_command
** Description: Checks to see if invalid command line
	arguments are provided and exits program w/ error message if so.
** Parameters: int, char**
*********************************************************************/
void bad_command(int, char**);

/*********************************************************************
** Function: get_int
** Description: Checks to see if string supplied was a valid int,
	reprompts if not an int.
** Parameters: None
*********************************************************************/
int get_int();

/*********************************************************************
** Function: create_users
** Description: Creates a dynamic array of users of a size provided
	by the users file
** Parameters: int
*********************************************************************/
user* create_users(int);

/*********************************************************************
** Function: get_user_data
** Description: Iterates through the user file supplied by command
	line and fills each member of the user_db struct (name, id, password)
** Parameters: user*, int, ifstream&
*********************************************************************/
void get_user_data(user*, int, ifstream&);

/*********************************************************************
** Function: create_budgets
** Description: Creates a dynamic array of budgets of a size provided
	by the budget file
** Parameters: int
*********************************************************************/
budget* create_budgets(int);

/*********************************************************************
** Function: get_budget_data
** Description: Iterates through the budget file supplied by command
	line and fills each member of the budget_db struct
** Parameters: budget*, int, ifstream&
*********************************************************************/
void get_budget_data(budget*, int, ifstream&);

/*********************************************************************
** Function: create_transactions
** Description: This function will dynamically allocate an array of
	transactions of size num_transactions from budget file
** Parameters: user*, int, ifstream&
*********************************************************************/
transaction* create_transactions(int);

/*********************************************************************
** Function: get_transaction_data
** Description: Iterates through the budget file supplied by command
	line and fills each member of the transaction struct
** Parameters: transaction*, int, ifstream&
*********************************************************************/
void get_transaction_data(transaction*, int, ifstream&);

/*********************************************************************
** Function: delete_info
** Description: Deletes the dynamic allocations
** Parameters: user*, int, budget*, int
*********************************************************************/
void delete_info(user* uinfo, int usize, budget* binfo, int bsize);

/*********************************************************************
** Function: get_login
** Description: Takes in user input for username and password, passed
	by reference so that it is updated in main.
** Parameters: user*, int&, string&
*********************************************************************/
void get_login(user*, int&, string&);

/*********************************************************************
** Function: check_login
** Description: Checks username and password against the user_db.
	If no match, increments a fail counter to keep track of failed logins.
** Parameters: user*, int, int, int*, string, int&, string&
*********************************************************************/
bool check_login(user*, int, int, int*, string, int&, string&);

/*********************************************************************
** Function: loop_login
** Description: Loops the get_login and check_login functions if they
	fail. Prints an error message upon fail and exits the program
	entirely if 3 fails are reached.
** Parameters: user*, int, string, int, int*, int&, string&
*********************************************************************/
int login_loop(user*, int, string, int, int*, int&, string&);

/*********************************************************************
** Function: category_sort
** Description: Loops through the budget_db and transaction_db
	and attempts to sort the transactions of an individual user
	alphabetically.
** Parameters: budget*, int, int
*********************************************************************/
void category_sort(budget*, int, int);

/*********************************************************************
** Function: date_sort
** Description: Loops through the budget_db and transaction_db
	and attempts to sort the transactions of an individual user
	chronologically.
** Parameters: budget*, int, int
*********************************************************************/
void date_sort(budget*, int, int);

/*********************************************************************
** Function: dollar_sort
** Description: Loops through the budget_db and transaction_db
	and attempts to sort the transactions of an individual user
	by dollar amount.
** Parameters: budget*, int, int
*********************************************************************/
void dollar_sort(budget*, int, int);

/*********************************************************************
** Function: output_data
** Description: Prompts the user to choose if they want the sorted
	transactions printed to terminal or a file. Handles the output
	of the transactions as well. Prompts user for filename if they
	select file output.
** Parameters: budget
*********************************************************************/
void output_data(struct budget personal_budget);

/*********************************************************************
** Function: userchoice_flow
** Description: Handles the user selection of sorting type. Calls the
	sort function selected by the user and also calls the output_data
	function.
** Parameters: budget*, int, int
*********************************************************************/
void userchoice_flow(budget*, int, int);

