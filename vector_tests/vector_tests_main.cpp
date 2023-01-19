#include "vector_tests_header.h"
#include "../vector/vector.hpp"
#include "../utils/remove_const.hpp"
#include "vector_test_classes.hpp"

#include <iostream>

#include <assert.h>
#include <vector>

void test() {
    std::vector<int> vec1(1, 1);

    std::vector<int> vec2;
    vec2.push_back(1);
    vec2.push_back(2);
    vec2.push_back(2);
    vec2.push_back(2);
    vec2.push_back(2);
    vec2.push_back(2);
    vec2.push_back(2);

    vec1.assign(vec2.begin(), vec2.end());

    //std::cout << vec1.size() << " " << vec1.capacity() << std::endl;
}

//todo для всех const методов надо будет сделать const версии тестов
int main(void) {

    //! VECTOR COMPLICATED METHODS TESTS
    resizeTests();
    assignTests();
    pushBackTest();
    popBackTest();
    //insertFirstTest();
    insertSecondTest();
    insertThirdTest();
    secondInsertTypeFirstTest();
    secondInsertTypeSecondTest();
    secondInsertTypeThirdTest();
    secondInsertTypeFourthTest();
    thirdInsertTypeFirstTest();
    eraseFirstTest();
    eraseSecondTest();
    //todo ошибка с инсертом в сам вектор
    //thirdInsertTypeSecondTest();

    //! VECTOR TESTS


    maxSizeTest();
    vectorConstructorTest();
    copyConstructorsTest();
    vectorAssignmentOperatorTest();



    swapTest();
    reserveTests();

    bracesOperatorTest();
    atTest();
    frontTest();
    backTest();
    emptyTest();
    clearTest();
    dataTest();
    allocatorTest();
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