#include <iostream>

#include "map_tests_header.hpp"

int main() {

    std::cout << "===Map tests==="<<std::endl;

    mapConstructorsTest();
    mapMakePairTest();
    mapRelationTest();

    std::cout << "===All passed==="<<std::endl;

    return 0;
}