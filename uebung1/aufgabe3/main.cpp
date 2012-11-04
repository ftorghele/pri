/*
 * main.cpp
 *
 *  Created on: Okt 29, 2012
 *      Author: torghele
 */

#include <iostream>
#include <ctime>
#include "tree.h"
#include "avltree.h"

int main() {
	std::srand(time(0));

    std::cout << "Uebung 1.3:" << std::endl << std::endl;

    Tree<int> tree;
    AvlTree<int> avltree;

    for(unsigned runns = 1; runns <= 5; runns++) {
        for(unsigned i = 0; i < 10000; i++) {
            unsigned randNumber = std::rand()%10000;
            tree.insert(randNumber);
            avltree.insert(randNumber);
        }
        std::cout << "Tested with " << runns*10000 << " nodes:" << std::endl;
        std::cout << "Tree:" << tree.height() << std::endl;
        std::cout << "AvlTree:" << avltree.height() << std::endl;
        std::cout << "------------------------" << std::endl;
    }

    return 0;
}
