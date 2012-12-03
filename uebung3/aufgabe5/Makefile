all: aufgabe5

aufgabe5: main.cpp
	$(CXX) -Wall -g -o $@ main.cpp

test: aufgabe5
	./aufgabe5

clean: 
	rm -f aufgabe5
	
valgrind:
	valgrind --tool=memcheck --leak-check=yes ./aufgabe5