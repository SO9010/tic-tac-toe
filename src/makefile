output: tic-tac-toe.o
	g++ -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lstdc++ tic-tac-toe.o -o tic-tac-toe.build
	rm tic-tac-toe.o

tic-tac-toe.o: tic-tac-toe.cpp
	g++ -c tic-tac-toe.cpp

clean: 
	rm *.o tic-tac-toe.build

run: 
	./tic-tac-toe.build
