#ifndef TEST_LIST_H
#define TEST_LIST_H

#include "../src/list.h"
#include <iostream>

struct test_list {
    void test_push_back() {
        auto *mylist = new mystl::list<int>();
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

    void test_push_front() {
        auto *mylist = new mystl::list<int>();
        mylist->push_front(1);
        mylist->push_front(2);
        mylist->push_front(3);
        mylist->push_front(4);
        mylist->push_front(5);

        mylist->ite_from_head([](int i) {
            std::cout << i << std::endl;
        });

        delete mylist;
    }

    void test_push_front_and_push_back() {
        auto *mylist = new mystl::list<int>();
        mylist->push_front(1);
        mylist->push_front(2);
        mylist->push_front(3);
        mylist->push_back(4);
        mylist->push_back(5);
        mylist->push_front(6);
        mylist->push_front(7);

        mylist->ite_from_head([](int i) {
            std::cout << i << std::endl;
        });

        delete mylist;
    }

    void test_pop_back() {
        auto *mylist = new mystl::list<int>();
        mylist->push_back(1);
        mylist->push_back(2);
        mylist->push_back(3);
        mylist->push_back(4);
        mylist->push_back(5);

        while (mylist->size() > 0) {
            auto popped = mylist->pop_back();
            std::cout << "移除的元素是: " << popped << std::endl;
        }
    }

    void test_pop_front() {
        auto *mylist = new mystl::list<int>();
        mylist->push_front(1);
        mylist->push_front(2);
        mylist->push_front(3);
        mylist->push_front(4);
        mylist->push_front(5);

        while (mylist->size() > 0) {
            auto popped = mylist->pop_front();
            std::cout << "移除的元素是: " << popped << std::endl;
        }
    }


    void test_ite_from_head() {
        auto *mylist = new mystl::list<int>();
        mylist->push_back(1);
        mylist->push_back(2);
        mylist->push_back(3);
        mylist->push_back(4);
        mylist->push_back(5);

        std::cout << "enhanced for loop" << std::endl;
        for (const int& data : *mylist) {
            std::cout << data << std::endl;
        }

        std::cout << "legacy for loop" << std::endl;
        for (auto begin = mylist->begin(); begin != mylist->end(); ++begin) {
            std::cout << *begin << std::endl;
        }

        delete mylist;
    }

    void test_remove_nth() {
        auto *mylist = new mystl::list<int>();
        mylist->push_back(1);

        mylist->remove_nth(0);

        delete mylist;
    }

    void test_remove_nth_2() {
        auto *mylist = new mystl::list<int>();
        mylist->push_back(1);
        mylist->push_back(2);

        mylist->remove_nth(0); // 删除头节点1，剩余节点2
        mylist->push_back(3);  // 尝试在尾部插入3

        delete mylist;
    }
};

#endif