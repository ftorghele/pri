all: aufgabe4

aufgabe4: main.cpp
	$(CXX) -Wall -g -o $@ main.cpp

test: aufgabe4
	./aufgabe4

clean: 
	rm -f aufgabe4
	
valgrind:
	valgrind --tool=memcheck --leak-check=yes ./aufgabe4