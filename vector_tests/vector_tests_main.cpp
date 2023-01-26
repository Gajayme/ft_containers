#include "vector_tests_header.h"
#include "../vector/vector.hpp"
#include "../utils/remove_const.hpp"
#include "vector_test_classes.hpp"

#include <iostream>

#include <assert.h>
#include <vector>

void test() {
//    std::cout << "std\n";
//    {
//        using namespace std;
//        std::vector<int> vec1;
//        vec1.push_back(1);
//        vec1.push_back(2);
//        vec1.push_back(3);
//        vec1.push_back(4);
//        vec1.push_back(5);
//
//        printer(vec1);
//        std::cout << std::endl;
//        vec1.resize(10);
//        printer(vec1);
//    }
//    std::cout << "\nft\n";
//    {
//        using namespace std;
//        ft::vector<int> vec1;
//        vec1.push_back(1);
//        vec1.push_back(2);
//        vec1.push_back(3);
//        vec1.push_back(4);
//        vec1.push_back(5);
//
//        printer(vec1);
//        std::cout << std::endl;
//        vec1.resize(10);
//        printer(vec1);
//    }
}

int main(void) {

    std::cout << "===Vector tests==="<<std::endl;

    //! Тесты конструктора, конструктора копирования и оператора присваивания
    vectorConstructorTest();
    vectorAssignmentOperatorTest();
    copyConstructorsTest();


    //! Тесты итератора вектора
    iterConstructorTest();
    iterCopyConstructorTest();
    iterAssignTest();
    iterEqualityTest();
    iterMoreLessTest();
    iterMoreLessEqualTest();
    iterPlusMinusInt ();
    iterPlusMinusEqualTest();
    iterIncrementDecrementTest();
    iterBracesTest();
    iterMinusIterTest();

    //! Тесты реверсивного итератора вектора
    reverseIterConstructorTest();
    reverseIterBaseTest();
    reverseIteratorDereferenceTest();
    reverseIteratorPlusIntTest();
    intPlusReverseIteratorTest();
    reverseIteratorIncrementTest();
    reverseIteratorDecrementTest();
    reverseIteratorPlusEqualTest();
    reverseIteratorMinusEqualTest();
    reverseIteratorMinusReverseIteratorTest();
    reverseIteratorBraceTest();
    reverseIteratorRelationTest();

    //! Тесты простых методов вектора
    dataTest();
    allocatorTest();
    swapTest ();
    maxSizeTest();
    atTest();
    frontTest();
    backTest();
    emptyTest();
    clearTest();

    //! Тесты сложных методов вектора
    resizeTests();
    assignTests();
    reserveTests();
    pushBackTest();
    popBackTest();
    exceptionSafetyTest();
    insertFirstTest();
    insertSecondTest();
    insertThirdTest();
    secondInsertTypeFirstTest();
    secondInsertTypeSecondTest();
    secondInsertTypeThirdTest();
    secondInsertTypeFourthTest();
    thirdInsertTypeFirstTest();
    eraseFirstTest();
    eraseSecondTest();
    eraseThirdTest();

    //! Тесты операторов вектора
    bracesOperatorTest();
    relationalOperatorTest();


    test();

    std::cout << "===All passed==="<<std::endl;

    return (0);
}