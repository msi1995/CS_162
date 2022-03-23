CC = g++ -std=c++11
exe_file = Wumpus
$(exe_file): event.o wumpus.o pit.o gold.o bats.o room.o game.o  driver.o
	     $(CC) event.o wumpus.o pit.o gold.o bats.o room.o game.o  driver.o -o $(exe_file)
event.o: event.cpp
	     $(CC) -c event.cpp
wumpus.o: wumpus.cpp
	     $(CC) -c wumpus.cpp
pit.o: pit.cpp
	     $(CC) -c pit.cpp
gold.o: gold.cpp
	     $(CC) -c gold.cpp
bats.o: bats.cpp
	     $(CC) -c bats.cpp
room.o: room.cpp
	     $(CC) -c room.cpp
game.o: game.cpp
	$(CC) -c game.cpp
driver.o: driver.cpp
		$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
