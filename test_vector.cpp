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

//! нужны тесты на значения, которые будут лежать внутри векторов
void resizeTests() {
    //! тесты с int
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.resize(0);
        ftVector.resize(0);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.resize(5);
        ftVector.resize(5);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.resize(3, 1000);
        ftVector.resize(3, 1000);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.resize(0);
        ftVector.resize(0);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());
    }

    //! тесты с пользовательским классом без конструктора по умолчания, но с конструктором копирования
    {
        std::vector<vector_tests_classes::CopyConstructorClass> stdVector;
        ft::vector<vector_tests_classes::CopyConstructorClass> ftVector;

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.resize(0);
        ftVector.resize(0);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.resize(5);
        ftVector.resize(5);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.resize(3, std::string("hello"));
        ftVector.resize(3, std::string("hello"));

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.resize(0);
        ftVector.resize(0);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());
    }
}

void reserveTests() {
    //! тесты с int
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.reserve(100);
        ftVector.reserve(100);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.reserve(10);
        ftVector.reserve(10);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.reserve(100);
        ftVector.reserve(100);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.reserve(1000);
        ftVector.reserve(1000);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());
    }
    //! тесты с пользовательским классом без конструктора по умолчания, но с конструктором копирования
    {
        std::vector<vector_tests_classes::CopyConstructorClass> stdVector;
        ft::vector<vector_tests_classes::CopyConstructorClass> ftVector;

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.reserve(100);
        ftVector.reserve(100);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.reserve(10);
        ftVector.reserve(10);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.reserve(100);
        ftVector.reserve(100);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());

        stdVector.reserve(1000);
        ftVector.reserve(1000);

        assert(ftVector.size() == stdVector.size());
        assert(ftVector.capacity() == stdVector.capacity());
    }
}


int main(void) {

//    resizeTests();
//    reserveTests();

    std::vector<int> vec;
    ft::vector<int> ftvec;
    vec.push_back(1);
    ftvec.push_back(1);
    printer(vec.size(), ftvec.size());
    printer(vec.capacity(), ftvec.capacity());
    vec.push_back(2);
    ftvec.push_back(2);
    printer(vec.size(), ftvec.size());
    printer(vec.capacity(), ftvec.capacity());
    vec.push_back(3);
    ftvec.push_back(3);
    printer(vec.size(), ftvec.size());
    printer(vec.capacity(), ftvec.capacity());
    printer(vec.size(), ftvec.size());
    printer(vec.capacity(), ftvec.capacity());

    ftvec.resize(1);
    vec.resize(1);

    printer(vec.size(), ftvec.size());
    printer(vec.capacity(), ftvec.capacity());

    return (0);
}