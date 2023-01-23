#include "vector_tests_header.h"
#include "../vector/vector.hpp"
#include "../utils/remove_const.hpp"
#include "vector_test_classes.hpp"

#include <iostream>

#include <assert.h>
#include <vector>

void test() {
    std::cout << "std\n";
    {
        using namespace std;
        std::vector<int> vec1;
        vec1.push_back(1);
        vec1.push_back(2);
        vec1.push_back(3);
        vec1.push_back(4);
        vec1.push_back(5);

        printer(vec1);
        std::cout << std::endl;
        vec1.resize(10);
        printer(vec1);
    }
    std::cout << "\nft\n";
    {
        using namespace std;
        ft::vector<int> vec1;
        vec1.push_back(1);
        vec1.push_back(2);
        vec1.push_back(3);
        vec1.push_back(4);
        vec1.push_back(5);

        printer(vec1);
        std::cout << std::endl;
        vec1.resize(10);
        printer(vec1);
    }
}

int main(void) {

    //! VECTOR COMPLICATED METHODS TESTS
    reserveTests();
    resizeTests();
    assignTests();
    pushBackTest();
    popBackTest();
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

    //! VECTOR CONSTRUCTOR TESTS
    vectorConstructorTest();
    copyConstructorsTest();
    vectorAssignmentOperatorTest();

    //! VECTOR SIMPLE METHODS TESTS
    maxSizeTest();
    atTest();
    frontTest();
    backTest();
    emptyTest();
    clearTest();
    dataTest();
    allocatorTest();



    swapTest();
    bracesOperatorTest();
    exceptionSafetyTest();
    relationalOperatorTest();


    //! ITER TESTS
    iterConstructorTest();
    iterCopyConstructorTest();
    iterAssignTest();
    iterEqualityTest();
    iterMoreLessTest();
    iterMoreLessEqualTest();
    iterPlusMinusInt();
    iterPlusMinusEqualTest();
    iterIncrementDecrementTest();
    iterBracesTest();
    iterMinusIterTest();

    //! REVERSE ITER TESTS
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

    test();
    return (0);
}