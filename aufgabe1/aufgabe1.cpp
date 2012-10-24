#include <iostream>
#include <cstdlib>
#include <ctime>
#include "merge_lists.cpp"

void fill_list(intlist &list) {
    for(unsigned int i = 0; i <= 1000; i = i + ((std::rand()%100)+1)) {
        list.push_front(i);
    }
}

void print_list(intlist &list) {
    intlist::const_iterator iterator;
    for (iterator = list.begin(); iterator != list.end(); ++iterator) {
        std::cout << *iterator << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::srand((unsigned)time(0));

    intlist a, b, c;
    intlist lists[3] = {a, b, c};

    for(unsigned int i = 0; i < 3; i++) {
        fill_list(lists[i]);
    }

    std::cout << "Lists which should be merged together:" << std::endl;
    for(unsigned int i = 0; i < 3; i++) {
        print_list(lists[i]);
    }

    std::cout << "Merged List:" << std::endl;
    intlist merged_lists = merge_lists(lists, 3);
    print_list(merged_lists);

    return 0;
}
