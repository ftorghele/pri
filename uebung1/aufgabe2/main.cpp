/*
 * main.cpp
 *
 *  Created on: Okt 29, 2012
 *      Author: torghele
 */

#include <iostream>
#include <ctime>
#include "heap.h"

int main() {
    std::srand(time(0));

    std::cout << "Uebung 1.2:" << std::endl << std::endl;

    Heap<int> intHeap2(10);

    for(unsigned i = 0; i < 10; i++) intHeap2.push(std::rand()%1000);

    std::cout << "unsorted:" << std::endl;
    intHeap2.print();

    intHeap2.sort();

    std::cout << "sorted:" << std::endl;
    intHeap2.print();

    return 0;
}
