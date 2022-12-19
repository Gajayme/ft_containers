#include "vector.hpp"
#include <iostream>
#include <assert.h>
#include <vector>
#include "vector_test_classes.hpp"

template <typename T>
void printer(T std, T ft) {
    std::cout << "std = " << std << " | ";
    std::cout << "ft = " << ft << std::endl;
}

//todo ошибка в передаче вектора по значению (нужен конструктор копирования)
template <typename STD, typename  FT>
void asserter(STD &std, FT &my) {
    assert(std.size() == my.size());
    assert(std.capacity() == my.capacity());
}

typedef std::vector<vector_tests_classes::CopyConstructorClass> StdCopyCrtrVector;
typedef ft::vector<vector_tests_classes::CopyConstructorClass> FtCopyCrtrVector;
typedef std::vector<vector_tests_classes::CopyExceptionClass> StdExceptVector;
typedef ft::vector<vector_tests_classes::CopyExceptionClass> FtExceptVector;

//todo здесь как будто есть ошибка
void constructorsTest() {
    {
        std::vector<int> stdVector(0, 100);
        ft::vector<int> ftVector(0, 100);

        asserter(stdVector, ftVector);
    }
    {
        std::vector<int> stdVector(10, 100);
        ft::vector<int> ftVector(10, 100);
        asserter(stdVector, ftVector);
    }
}

void copyConstructorsTest() {
    {
        std::vector<int> stdVector;
        std::vector<int> stdVectorCopy(stdVector);
        ft::vector<int> ftVector;
        ft::vector<int> ftVectorCopy(ftVector);

        asserter(stdVectorCopy, ftVectorCopy);
    }
//    {
//        std::vector<int> stdVector(10, 100);
//        std::vector<int> stdVectorCopy(stdVector);
//        ft::vector<int> ftVector(10, 100);
//        ft::vector<int> ftVectorCopy(ftVector);
//
//        asserter(stdVectorCopy, ftVectorCopy);
//    }
    {
        std::vector<int> stdVector;
        for (size_t i = 0; i != 10; ++i) {
           stdVector.push_back(1);
        }
        std::vector<int> stdVectorCopy(stdVector);

        ft::vector<int> ftVector;
        for (size_t i = 0; i != 10; ++i) {
            ftVector.push_back(1);
        }
        ft::vector<int> ftVectorCopy(ftVector);
        asserter(stdVectorCopy, ftVectorCopy);
    }
}

//! нужны тесты на значения, которые будут лежать внутри векторов
void resizeTests() {
    //! тесты с int
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;
        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);

        stdVector.resize(0);
        ftVector.resize(0);

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);

        stdVector.resize(5);
        ftVector.resize(5);

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);

        stdVector.resize(3, 1000);
        ftVector.resize(3, 1000);

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);

        stdVector.resize(0);
        ftVector.resize(0);

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);
    }

    //! тесты с пользовательским классом без конструктора по умолчания, но с конструктором копирования
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;

        asserter<StdCopyCrtrVector, FtCopyCrtrVector>(stdVector, ftVector);

        stdVector.resize(0);
        ftVector.resize(0);

        asserter<StdCopyCrtrVector, FtCopyCrtrVector>(stdVector, ftVector);

        stdVector.resize(5);
        ftVector.resize(5);

        asserter<StdCopyCrtrVector, FtCopyCrtrVector>(stdVector, ftVector);

        stdVector.resize(3, std::string("hello"));
        ftVector.resize(3, std::string("hello"));

        asserter<StdCopyCrtrVector, FtCopyCrtrVector>(stdVector, ftVector);

        stdVector.resize(0);
        ftVector.resize(0);

        asserter<StdCopyCrtrVector, FtCopyCrtrVector>(stdVector, ftVector);
    }
}

void reserveTests() {
    //! тесты с int
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);

        stdVector.reserve(100);
        ftVector.reserve(100);

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);

        stdVector.reserve(10);
        ftVector.reserve(10);

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);

        stdVector.reserve(100);
        ftVector.reserve(100);

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);

        stdVector.reserve(1000);
        ftVector.reserve(1000);

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);
    }
    //! тесты с пользовательским классом без конструктора по умолчания, но с конструктором копирования
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;

        asserter<StdCopyCrtrVector, FtCopyCrtrVector>(stdVector, ftVector);

        stdVector.reserve(100);
        ftVector.reserve(100);

        asserter<StdCopyCrtrVector, FtCopyCrtrVector>(stdVector, ftVector);

        stdVector.reserve(10);
        ftVector.reserve(10);

        asserter<StdCopyCrtrVector, FtCopyCrtrVector>(stdVector, ftVector);

        stdVector.reserve(100);
        ftVector.reserve(100);

        asserter<StdCopyCrtrVector, FtCopyCrtrVector>(stdVector, ftVector);

        stdVector.reserve(1000);
        ftVector.reserve(1000);

        asserter<StdCopyCrtrVector, FtCopyCrtrVector>(stdVector, ftVector);
    }
}

void pushBackTest(void) {
    //! int
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);

        stdVector.push_back(1);
        ftVector.push_back(1);

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);

        stdVector.push_back(2);
        ftVector.push_back(2);
        stdVector.push_back(3);
        ftVector.push_back(3);
        stdVector.push_back(4);
        ftVector.push_back(4);

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);
    }
    //! custom classes
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;

        asserter<StdCopyCrtrVector, FtCopyCrtrVector>(stdVector, ftVector);

        stdVector.push_back(std::string ("hello"));
        ftVector.push_back(std::string("hello"));

        asserter<StdCopyCrtrVector, FtCopyCrtrVector>(stdVector, ftVector);

        stdVector.push_back(vector_tests_classes::CopyConstructorClass());
        ftVector.push_back(vector_tests_classes::CopyConstructorClass());

        asserter<StdCopyCrtrVector, FtCopyCrtrVector>(stdVector, ftVector);
    }
}

void popBackTest() {
    //! int
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        ftVector.push_back(1);
        ftVector.pop_back();

        stdVector.push_back(1);
        stdVector.pop_back();

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);

        ftVector.push_back(1);
        ftVector.push_back(2);
        ftVector.push_back(3);
        ftVector.pop_back();

        stdVector.push_back(1);
        stdVector.push_back(2);
        stdVector.push_back(3);

        stdVector.pop_back();

        asserter<std::vector<int>, ft::vector<int> >(stdVector, ftVector);
    }
    //! custom classes
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;

        stdVector.push_back(std::string("hello"));
        stdVector.push_back(std::string("hello"));

        ftVector.push_back(std::string("hello"));
        ftVector.push_back(std::string("hello"));

        asserter<StdCopyCrtrVector , FtCopyCrtrVector >(stdVector, ftVector);
    }
}

void bracesOperatorTest() {
    //! int
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        stdVector.push_back(1);
        ftVector.push_back(1);

        assert(stdVector[0] == ftVector[0]);

        stdVector.push_back(10);
        ftVector.push_back(10);

        assert(stdVector[1] == ftVector[1]);
    }
    //! custom classes
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;

        stdVector.push_back(std::string("hello"));
        stdVector.push_back(std::string("hi"));

        ftVector.push_back(std::string("hello"));
        ftVector.push_back(std::string("hi"));

        assert(stdVector[0] == ftVector[0]);
        assert(stdVector[1] == ftVector[1]);
    }
}

void atTest() {
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        stdVector.push_back(1);
        ftVector.push_back(1);

        assert(stdVector.at(0) == ftVector.at(0));

        stdVector.push_back(10);
        ftVector.push_back(10);

        assert(stdVector.at(1) == ftVector.at(1));
    }
    //! custom classes
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;

        stdVector.push_back(std::string("hello"));
        stdVector.push_back(std::string("hi"));

        ftVector.push_back(std::string("hello"));
        ftVector.push_back(std::string("hi"));

        assert(stdVector.at(0) == ftVector.at(0));
        assert(stdVector.at(1) == ftVector.at(1));
        try {
            ftVector.at(3);
        } catch (std::out_of_range) {

        }
    }
}

void frontTest() {
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        stdVector.push_back(1);
        ftVector.push_back(1);

        assert(stdVector.front() == ftVector.front());
    }
    //! custom classes
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;

        stdVector.push_back(std::string("hello"));
        stdVector.push_back(std::string("hi"));

        ftVector.push_back(std::string("hello"));
        ftVector.push_back(std::string("hi"));

        assert(stdVector.front() == ftVector.front());
    }
}

void backTest() {
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        stdVector.push_back(1);
        ftVector.push_back(1);

        assert(stdVector.back() == ftVector.back());
    }
    //! custom classes
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;

        stdVector.push_back(std::string("hello"));
        stdVector.push_back(std::string("hi"));

        ftVector.push_back(std::string("hello"));
        ftVector.push_back(std::string("hi"));

        assert(stdVector.back() == ftVector.back());
    }
}

void emptyTest() {
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;
        assert(stdVector.empty() == ftVector.empty());
    }
}

void clearTest() {
    //! int
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        stdVector.clear();
        ftVector.clear();
        asserter(stdVector, ftVector);

        stdVector.push_back(1);
        stdVector.push_back(1);
        stdVector.push_back(1);
        ftVector.push_back(1);
        ftVector.push_back(1);
        ftVector.push_back(1);

        stdVector.clear();
        ftVector.clear();

        asserter(stdVector, ftVector);
    }
    //!custom classes
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;

        stdVector.clear();
        ftVector.clear();
        asserter(stdVector, ftVector);

        stdVector.push_back(std::string("hello"));
        stdVector.push_back(std::string("hi"));

        ftVector.push_back(std::string("hello"));
        ftVector.push_back(std::string("hi"));

        stdVector.clear();
        ftVector.clear();

        asserter(stdVector, ftVector);
    }
}

void exceptionSafetyTest() {

    {
        StdExceptVector stdVector;
        FtExceptVector ftVector;
        size_t n = 10;

        ftVector.resize(n, std::string("hello"));
        stdVector.resize(n, std::string("hello"));

        asserter<StdExceptVector , FtExceptVector>(stdVector, ftVector);

        n *= 2;
        //todo если увеличить на 15, то capacity у стандартного вектора станет 20 почему-то

        try {
            ftVector.resize(n, std::string("bye"));
        } catch (...) {
        }
        try {
            stdVector.resize(n, std::string("bye"));
        } catch (...) {
        }
        asserter<StdExceptVector , FtExceptVector>(stdVector, ftVector);
    }
    {
        StdExceptVector stdVector;
        FtExceptVector ftVector;

        stdVector.push_back(std::string("hello"));
        ftVector.push_back(std::string("hello"));

        asserter<StdExceptVector , FtExceptVector>(stdVector, ftVector);

        try {
            stdVector.push_back(std::string("bye"));
            ftVector.push_back(std::string("bye"));
        } catch(...) {
            asserter<StdExceptVector , FtExceptVector>(stdVector, ftVector);
        }

    }
}

void test() {
    std::vector<int> vec(15, 100);
    std::cout << vec.size() << std::endl;
    std::cout << vec.capacity() << std::endl;
}

int main(void) {

    //constructorsTest();
    copyConstructorsTest();
    resizeTests();
    reserveTests();
    pushBackTest();
    popBackTest();
    //todo для всех const методов надо будет сделать const версии тестов
    bracesOperatorTest();
    atTest();
    frontTest();
    backTest();
    emptyTest();
    clearTest();
    exceptionSafetyTest();

    //test();

    return (0);
}