#ifndef TEST_LIST_H
#define TEST_LIST_H

#include "../src/list.h"
#include <iostream>

struct test_list {
    void test_in_dev() {
        mystl::list<int> *mylist = new mystl::list<int>();
        mylist->push_back(1);
        mylist->push_back(2);
        mylist->push_back(3);
        mylist->push_back(4);
        mylist->push_back(5);

        mylist->ite_from_head([](int i) {
            std::cout << i << std::endl;
        });

        delete mylist;
    }
};

#endif