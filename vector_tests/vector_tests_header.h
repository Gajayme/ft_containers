#ifndef FT_CONTAINERS_VECTOR_TESTS_HEADER_H
#define FT_CONTAINERS_VECTOR_TESTS_HEADER_H

#include <vector>
#include <cstddef>

#include "../vector/vector.hpp"
#include "assert.h"
#include "vector_test_classes.hpp"

typedef std::vector<vector_tests_classes::CopyConstructorClass> StdCopyCrtrVector;
typedef ft::vector<vector_tests_classes::CopyConstructorClass> FtCopyCrtrVector;
typedef std::vector<vector_tests_classes::CopyExceptionClass> StdExceptVector;
typedef ft::vector<vector_tests_classes::CopyExceptionClass> FtExceptVector;

//! Тесты конструктора, конструктора копирования и оператора присваивания
void vectorConstructorTest();
void vectorAssignmentOperatorTest();
void copyConstructorsTest();


//! Тесты итератора вектора
void iterConstructorTest();
void iterCopyConstructorTest();
void iterAssignTest();
void iterEqualityTest();
void iterMoreLessTest();
void iterMoreLessEqualTest();
void iterPlusMinusInt ();
void iterPlusMinusEqualTest();
void iterIncrementDecrementTest();
void iterBracesTest();
void iterMinusIterTest();

//! Тесты реверсивного итератора вектора
void reverseIterConstructorTest();
void reverseIterBaseTest();
void reverseIteratorDereferenceTest();
void reverseIteratorPlusIntTest();
void intPlusReverseIteratorTest();
void reverseIteratorIncrementTest();
void reverseIteratorDecrementTest();
void reverseIteratorPlusEqualTest();
void reverseIteratorMinusEqualTest();
void reverseIteratorMinusReverseIteratorTest();
void reverseIteratorBraceTest();
void reverseIteratorRelationTest();

//! Тесты простых методов вектора
void dataTest();
void allocatorTest();
void swapTest ();
void maxSizeTest();
void atTest();
void frontTest();
void backTest();
void emptyTest();
void clearTest();


//! Тесты сложных методов вектора
void resizeTests();
void assignTests();
void reserveTests();
void pushBackTest(void);
void popBackTest();
void exceptionSafetyTest();
void insertFirstTest();
void insertSecondTest();
void insertThirdTest();
void secondInsertTypeFirstTest();
void secondInsertTypeSecondTest();
void secondInsertTypeThirdTest();
void secondInsertTypeFourthTest();
void thirdInsertTypeFirstTest();
void eraseFirstTest();
void eraseSecondTest();
void eraseThirdTest();


//! Тесты операторов вектора
void bracesOperatorTest();
void relationalOperatorTest();


template <typename T>
void printer(T &vec) {

    std::cout << "size = " << vec.size() << " capacity = " << vec.capacity() << std::endl;
    for (size_t i = 0; i != vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

template <typename STD, typename  FT>
void asserter(STD &std, FT &ft) {
    assert(std.size() == ft.size());
    assert(std.capacity() == ft.capacity());
    if (!std.empty() && !ft.empty()) {
        for (size_t i = 0; i != ft.size(); ++i) {
            assert(std[i] == ft[i]);
//            assert(std.front() == ft.front());
//            assert(std.back() == ft.back());
        }
    }
}

#endif //FT_CONTAINERS_VECTOR_TESTS_HEADER_H
