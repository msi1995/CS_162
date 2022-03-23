CC = g++ -std=c++11
exe_file = LinkedList
$(exe_file): node.o linked_list.o driver.o
	     $(CC) node.o linked_list.o driver.o -o $(exe_file)
node.o: node.cpp
	     $(CC) -c node.cpp
linked_list.o: linked_list.cpp
	     $(CC) -c linked_list.cpp
driver.o: driver.cpp
	     $(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)