all: main

aufgabe3: main.cpp
	$(CXX) -Wall -g -o $@ main.cpp 

test: all
	./main 

clean: 
	rm -f main

valgrind:
	valgrind --leak-check=yes ./main