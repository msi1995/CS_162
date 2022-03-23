CC = g++ -std=c++11
exe_file = ZooTycoon
$(exe_file): animal.o tiger.o sealion.o bear.o zoo.o driver.o
	     $(CC) animal.o tiger.o sealion.o bear.o zoo.o driver.o -o $(exe_file)
animal.o: animal.cpp
	     $(CC) -c animal.cpp
tiger.o: tiger.cpp
	     $(CC) -c tiger.cpp
sealion.o: sealion.cpp
	     $(CC) -c sealion.cpp
bear.o: bear.cpp
	     $(CC) -c bear.cpp
zoo.o: zoo.cpp
	     $(CC) -c zoo.cpp
driver.o: driver.cpp
	     $(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)