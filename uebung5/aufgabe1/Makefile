all: cachesim

cachesim: main.cpp
	$(CXX) -Wall -g -o $@ main.cpp 

test: all
	./cachesim 

clean: 
	rm -f cachesim

valgrind:
	valgrind --leak-check=yes ./cachesim trace-ls.txt