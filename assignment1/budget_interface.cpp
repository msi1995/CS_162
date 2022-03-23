#include "budget_header.h"
using namespace std;

void bad_command(int argc, char** argv) {
	if (argc != 3) {
		cout << endl << "Command line values are not correct. Must enter a.out followed by two filenames. Exiting" << endl << endl;
		exit(0);
	}
}


user* create_users(int count) {
	user* user_db = new user[count];
	return user_db;
}


void get_user_data(user* user_db, int count2, ifstream& user_file) {
	for (int i = 0; i < count2; i++) {
		user_file >> user_db[i].name;
		user_file >> user_db[i].id;
		user_file >> user_db[i].password;
	}
	user_file.close();
}

budget* create_budgets(int count) {
	budget* budget_db = new budget[count];
	return budget_db;
}

transaction* create_transactions(int size) {
	transaction* transaction_db = new transaction[size];
	return transaction_db;

}


void get_budget_data(budget* budget_db, int count, ifstream& budget_file) {
	for (int i = 0; i < count; i++) {
		budget_file >> budget_db[i].id;
		budget_file >> budget_db[i].balance;
		budget_file >> budget_db[i].num_transactions;
		budget_db[i].t = create_transactions(budget_db[i].num_transactions);
		get_transaction_data(budget_db[i].t, budget_db[i].num_transactions, budget_file);
	}
	budget_file.close();
}

void get_transaction_data(transaction* transaction_db, int size, ifstream& budget_file) {
	for (int i = 0; i < size; i++) {
		budget_file >> transaction_db[i].date;
		budget_file >> transaction_db[i].amount;
		budget_file >> transaction_db[i].description;
		budget_file >> transaction_db[i].category;
	}
}

int get_int() {
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

void get_login(user* user_db, int& userid, string& password) {
	cout << "Enter username" << endl;
	userid = get_int();
	cout << "Enter password" << endl;
	cin.ignore();
	getline(cin, password);
}

bool check_login(user* user_db, int userid, int count2, int* login_fail_int, string password, int& id_personal, string& username_personal) {
	for (int i = 0; i < count2; i++) {
		if (userid == user_db[i].id) {
			id_personal = user_db[i].id;
			username_personal = user_db[i].name;
			if (password == user_db[i].password) {
				return true;
			}
		}
	}
	(*login_fail_int)++;
	return false;
}

int login_loop(user* user_db, int userid, string password, int count2, int* login_fail_int, int& id_personal, string& username_personal) {
	bool result = false;
	while (result == false) {
		get_login(user_db, userid, password);
		result = check_login(user_db, userid, count2, login_fail_int, password, id_personal, username_personal);
		if (result == false) {
			cout << "Login fails: " << *login_fail_int << ". You will be kicked out after 3 fails." << endl << endl;
			if (*login_fail_int == 3) {
				cout << "You are locked out. Exiting." << endl << endl;
				exit(0);
			}
		}
	}
}

void category_sort(budget* budget_db, int id, int size) {
	float a;
	string d;
	string c;
	string des;

	for (int j = 0; j < size; j++) {

		if (id == budget_db[j].id) {
			for (int i = 0; i < budget_db[j].num_transactions; i++) {
				for (int k = i + 1; k < budget_db[j].num_transactions; k++)

					if (budget_db[j].t[i].category > budget_db[j].t[k].category) {
						a = budget_db[j].t[i].amount;
						d = budget_db[j].t[i].date;
						c = budget_db[j].t[i].category;
						des = budget_db[j].t[i].description;

						budget_db[j].t[i].amount = budget_db[j].t[k].amount;
						budget_db[j].t[i].date = budget_db[j].t[k].date;
						budget_db[j].t[i].category = budget_db[j].t[k].category;
						budget_db[j].t[i].description = budget_db[j].t[k].description;

						budget_db[j].t[k].amount = a;
						budget_db[j].t[k].date = d;
						budget_db[j].t[k].category = c;
						budget_db[j].t[k].description = des;



					}
			}

		}

	}
}

void date_sort(budget* budget_db, int id, int size) {
	float a;
	string d;
	string c;
	string des;

	for (int j = 0; j < size; j++) {
		if (id == budget_db[j].id) {
			for (int i = 0; i < budget_db[j].num_transactions; i++) {
				for (int k = i + 1; k < budget_db[j].num_transactions; k++)

					if (budget_db[j].t[i].date > budget_db[j].t[k].date) {
						a = budget_db[j].t[i].amount;
						d = budget_db[j].t[i].date;
						c = budget_db[j].t[i].category;
						des = budget_db[j].t[i].description;

						budget_db[j].t[i].amount = budget_db[j].t[k].amount;
						budget_db[j].t[i].date = budget_db[j].t[k].date;
						budget_db[j].t[i].category = budget_db[j].t[k].category;
						budget_db[j].t[i].description = budget_db[j].t[k].description;

						budget_db[j].t[k].amount = a;
						budget_db[j].t[k].date = d;
						budget_db[j].t[k].category = c;
						budget_db[j].t[k].description = des;
					}
			}
		}
	}
}

void dollar_sort(budget* budget_db, int id, int size) {
	float a;
	string d;
	string c;
	string des;

	for (int j = 0; j < size; j++) {
		if (id == budget_db[j].id) {
			for (int i = 0; i < budget_db[j].num_transactions; i++) {
				for (int k = i + 1; k < budget_db[j].num_transactions; k++)

					if (budget_db[j].t[i].amount < budget_db[j].t[k].amount) {
						a = budget_db[j].t[i].amount;
						d = budget_db[j].t[i].date;
						c = budget_db[j].t[i].category;
						des = budget_db[j].t[i].description;

						budget_db[j].t[i].amount = budget_db[j].t[k].amount;
						budget_db[j].t[i].date = budget_db[j].t[k].date;
						budget_db[j].t[i].category = budget_db[j].t[k].category;
						budget_db[j].t[i].description = budget_db[j].t[k].description;

						budget_db[j].t[k].amount = a;
						budget_db[j].t[k].date = d;
						budget_db[j].t[k].category = c;
						budget_db[j].t[k].description = des;
					}
			}
		}
	}
}

void output_data(struct budget personal_budget) {

	int writefile;
	string writefile_name;

	cout << "Press 1 for data printed to terminal, 2 to write data to a text file: ";
	cin >> writefile;
	cin.ignore();
	if (writefile == 2) {
		cout << "Enter a name for your text file. Example: file1.txt ";
		getline(cin, writefile_name);
		ofstream output;
		output.open(writefile_name.c_str());
		cout << endl;
		for (int i = 0; i < personal_budget.num_transactions; i++) {
			output << personal_budget.t[i].date << " ";
			output << personal_budget.t[i].amount << " ";
			output << personal_budget.t[i].description << " ";
			output << personal_budget.t[i].category << " " << endl;
		}
		output.close();
	}
	else {
		cout << endl;
		for (int i = 0; i < personal_budget.num_transactions; i++) {
			cout << personal_budget.t[i].date << " ";
			cout << personal_budget.t[i].amount << " ";
			cout << personal_budget.t[i].description << " ";
			cout << personal_budget.t[i].category << endl;
		}
		cout << endl;
	}


}

void userchoice_flow(budget* budget_db, int id, int size) {
	int x, userchoice;
	cout << "Press 1 to sort by Category, 2 for by date, 3 for by dollar amount, any other key to quit program: ";
	cin >> userchoice;
	if (userchoice == 1)
		category_sort(budget_db, id, size);
	else if (userchoice == 2)
		date_sort(budget_db, id, size);
	else if (userchoice == 3)
		dollar_sort(budget_db, id, size);
	else {
		cout << "Exiting program." << endl << endl;
		exit(0);
	}

	for (int j = 0; j < size; j++)
		if (id == budget_db[j].id) {
			x = j;
		}

	output_data(budget_db[x]);
}

void delete_info(user** uinfo, int usize, budget** binfo, int bsize) {

	delete[] *uinfo;
	for (int i = 0; i < bsize; i++) {
		delete[] binfo[i]->t;
	}
	delete[] *binfo;

}
