output: tiktacktoe.o
	g++ -lSDL2 -lSDL2_image -lSDL2_ttf -lstdc++ tiktacktoe.o -o output

tiktacktoe.o: tiktacktoe.cpp
	g++ -c tiktacktoe.cpp

clean: 
	rm *.o output

run: 
	./output