all: aufgabe1

aufgabe1: main.c
	gcc -Wall -g -DCLS=`getconf LEVEL1_DCACHE_LINESIZE` -std=c99 -msse2 -O3 -o $@ main.c

test: aufgabe1
	./aufgabe1

clean: 
	rm -f aufgabe1
