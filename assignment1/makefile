CC = g++
exe_file = budgetbuddy
$(exe_file): budget_interface.o budget_buddy.o
	     $(CC) budget_interface.o budget_buddy.o -o $(exe_file)
budget_interface.o: budget_interface.cpp
	     $(CC) -c budget_interface.cpp
budget_buddy.o: budget_buddy.cpp
	     $(CC) -c budget_buddy.cpp
clean:
	rm -f *.out *.o $(exe_file)
