#include <iostream>
#include <string>
#include <ctime>
#include "heap.h"
#include "number.h"
#include "tree.h"
#include "avlTree.h"

using namespace std;

int main() {
    std::srand(time(0));

    // Uebung 1.1

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
    std::cout << "========================" << std::endl << std::endl;

    // Uebung 1.2

    std::cout << "Uebung 1.2:" << std::endl << std::endl;

    Heap<int> intHeap2(10);

    for(unsigned i = 0; i < 10; i++) intHeap2.push(std::rand()%1000);

    std::cout << "unsorted:" << std::endl;
    intHeap2.print();
    intHeap2.sort();
    std::cout << "sorted:" << std::endl;
    intHeap2.print();
    std::cout << "========================" << std::endl << std::endl;

    // Uebung 1.3

    std::cout << "Uebung 1.3:" << std::endl << std::endl;

    Tree tree;
    AvlTree avltree;

    for(unsigned runns = 1; runns <= 5; runns++) {
        for(unsigned i = 0; i < 10000; i++) {
            unsigned randNumber = std::rand()%100000;
            tree.insert(randNumber);
            avltree.insert(randNumber);
        }
        std::cout << "Tested with " << runns*10000 << " nodes:" << std::endl;
        std::cout << "Tree:" << tree.height() << std::endl;
        std::cout << "AvlTree:" << avltree.height() << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    std::cout << "========================" << std::endl << std::endl;

    return 0;
}
