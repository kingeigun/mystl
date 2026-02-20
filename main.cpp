#include <iostream>
#include "test/test_list.h"

int main() {
    test_list t_list = test_list();
    std::cout << "===========================" << "t_list.test_push_back()" << std::endl;
    t_list.test_push_back();
    std::cout << "===========================" << "t_list.test_push_front()" << std::endl;
    t_list.test_push_front();
    std::cout << "===========================" << "t_list.test_push_front_and_push_back()" << std::endl;
    t_list.test_push_front_and_push_back();
    std::cout << "===========================" << "t_list.test_pop_back()" << std::endl;
    t_list.test_pop_back();
    std::cout << "===========================" << "t_list.test_pop_front()" << std::endl;
    t_list.test_pop_front();
    std::cout << "===========================" << "t_list.test_ite_from_head()" << std::endl;
    t_list.test_ite_from_head();
    std::cout << "===========================" << "t_list.test_remove_nth()" << std::endl;
    t_list.test_remove_nth();
    std::cout << "===========================" << "t_list.test_remove_nth_2()" << std::endl;
    t_list.test_remove_nth_2();
    return 0;
}