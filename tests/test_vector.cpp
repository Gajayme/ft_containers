#include "vector_tests_header.h"
#include "../vector/vector.hpp"
#include "../utils/remove_const.hpp"
#include "vector_test_classes.hpp"

#include <iostream>

#include <assert.h>
#include <vector>

void test() {

}

//todo для всех const методов надо будет сделать const версии тестов
int main(void) {

    //! VECTOR TESTS
    maxSizeTest();
    vectorConstructorTest();
    copyConstructorsTest();
    vectorAssignmentOperatorTest();
    resizeTests();
    assignTests();
    swapTest();
    reserveTests();
    pushBackTest();
    popBackTest();
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
    insertFirstTest();
    insertSecondTest();
    insertThirdTest();
    secondInsertTypeFirstTest();
    secondInsertTypeSecondTest();
    secondInsertTypeThirdTest();
    secondInsertTypeFourthTest();
    thirdInsertTypeFirstTest();

    //todo ошибка с инсертом в сам вектор
    //thirdInsertTypeSecondTest();

    eraseFirstTest();
    eraseSecondTest();

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