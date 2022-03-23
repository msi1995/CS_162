CC = g++ -std=c++11
exe_file = C8
$(exe_file): card_interface.o deck_interface.o hand_interface.o player_interface.o game_interface.o driver.o
	     $(CC) card_interface.o deck_interface.o hand_interface.o player_interface.o game_interface.o driver.o -o $(exe_file)
card_interface.o: card_interface.cpp
	     $(CC) -c card_interface.cpp
deck_interface.o: deck_interface.cpp
	     $(CC) -c deck_interface.cpp
hand_interface.o: hand_interface.cpp
	     $(CC) -c hand_interface.cpp
player_interface.o: player_interface.cpp
	     $(CC) -c player_interface.cpp
game_interface.o: game_interface.cpp
	     $(CC) -c game_interface.cpp
driver.o: driver.cpp
	     $(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
