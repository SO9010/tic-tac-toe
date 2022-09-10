output: tic-tac-toe.o
	g++ -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lstdc++ tic-tac-toe.o -o output

tic-tac-toe.o: tic-tac-toe.cpp
	g++ -c tic-tac-toe.cpp

clean: 
	rm *.o output

run: 
	./output
