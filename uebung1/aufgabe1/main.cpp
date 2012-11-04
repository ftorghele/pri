/*
 * main.cpp
 *
 *  Created on: Okt 29, 2012
 *      Author: torghele
 */

#include <iostream>
#include <ctime>

#include "heap.h"
#include "number.h"

int main() {
    std::srand(time(0));

    std::cout << std::endl << "Uebung 1.1:" << std::endl << std::endl;

    Heap<int> intHeap(4);
    Heap<Number> numberHeap(4);

    intHeap.push(10);
    intHeap.push(4);
    intHeap.push(3);
    intHeap.push(9);

    std::cout << "Integer Heap:" << std::endl;
    intHeap.print();

    Number n1(3.2);
    Number n2(5.5);
    Number n3(10.5);
    Number n4(3.9);

    numberHeap.push(n1);
    numberHeap.push(n2);
    numberHeap.push(n3);
    numberHeap.push(n4);

    std::cout << "'Number' Heap:" << std::endl;
    numberHeap.print();

    return 0;
}
