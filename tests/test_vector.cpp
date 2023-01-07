#include "../vector/vector.hpp"
#include <iostream>
#include <assert.h>
#include <vector>
#include "vector_test_classes.hpp"
#include "../utils/remove_const.hpp"

template <typename T>
void printer(T std, T ft) {
    std::cout << "std = " << std << " | ";
    std::cout << "ft = " << ft << std::endl;
}

//todo ошибка в передаче вектора по значению (нужен конструктор копирования)
template <typename STD, typename  FT>
void asserter(STD &std, FT &ft) {
    assert(std.size() == ft.size());
    assert(std.capacity() == ft.capacity());
    if (!std.empty() && !ft.empty()) {
        assert(std.front() == ft.front());
        assert(std.back() == ft.back());
    }
}

typedef std::vector<vector_tests_classes::CopyConstructorClass> StdCopyCrtrVector;
typedef ft::vector<vector_tests_classes::CopyConstructorClass> FtCopyCrtrVector;
typedef std::vector<vector_tests_classes::CopyExceptionClass> StdExceptVector;
typedef ft::vector<vector_tests_classes::CopyExceptionClass> FtExceptVector;

void constructorsTest() {
    {
        std::vector<int> stdVector(1, 100);
        ft::vector<int> ftVector(1, 100);

        asserter(stdVector, ftVector);
    }
    {
        std::vector<int> stdVector(10, 100);
        ft::vector<int> ftVector(10, 100);
        asserter(stdVector, ftVector);
    }
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;
    }
    {
        try {
            StdExceptVector stdVec(10, std::string("bye"));
            FtExceptVector ftVec(10, std::string("bye"));
        } catch (...) {
        }
    }
}

void assignmentOperatorTest() {
    {
        std::vector<int> stdVector(1, 100);
        ft::vector<int> ftVector(1, 100);

        std::vector<int> stdVector2(2, 50);
        ft::vector<int> ftVector2(2, 50);

        stdVector = stdVector2;
        ftVector = ftVector2;
        asserter(ftVector, stdVector);
    }
    {
        StdCopyCrtrVector stdVector(10, std::string("hi"));
        FtCopyCrtrVector ftVector(10, std::string("hi"));

        StdCopyCrtrVector stdVector2(5, std::string("hello"));
        FtCopyCrtrVector ftVector2(5, std::string("hello"));

        ftVector = ftVector2;
        stdVector = stdVector2;
        asserter(ftVector, stdVector);
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
    {
        std::vector<int> stdVector(10, 100);
        std::vector<int> stdVectorCopy(stdVector);
        ft::vector<int> ftVector(10, 100);
        ft::vector<int> ftVectorCopy(ftVector);

        asserter(stdVectorCopy, ftVectorCopy);
    }
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

void dataTest() {
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;
        assert(stdVector.data() == NULL);
        assert(ftVector.data() == NULL);
    }
    {
        std::vector<int> stdVector(1, 100);
        ft::vector<int> ftVector(1, 100);
        assert(stdVector.data()[0] = ftVector.data()[0]);
    }
}

void allocatorTest() {
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;
        assert(stdVector.get_allocator() == ftVector.get_allocator());
    }
}

void swapTest () {
    {
        std::vector<int> stdVector(9, 9);
        std::vector<int> stdVector1(10, 10);
        ft::vector<int> ftVector(10, 10);
        ft::vector<int> ftVector1(9, 9);
        ftVector.swap(ftVector1);
        asserter(stdVector, ftVector);
        asserter(stdVector1, ftVector1);
    }
    {
        std::vector<int> stdVector;
        std::vector<int> stdVector1(10, 10);
        ft::vector<int> ftVector(10, 10);
        ft::vector<int> ftVector1;
        ftVector.swap(ftVector1);
        asserter(stdVector, ftVector);
        asserter(stdVector1, ftVector1);
    }
}

//todo нужны тесты на значения, которые будут лежать внутри векторов
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

void assignTests() {
    //! тесты с int
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        stdVector.assign(10, 99);
        ftVector.assign(10, 99);

        asserter(stdVector, ftVector);

        stdVector.assign(5, 88);
        ftVector.assign(5, 88);

        asserter(stdVector, ftVector);
    }
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        stdVector.assign(10, 99);
        ftVector.assign(10, 99);
        asserter(stdVector, ftVector);
    }
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        stdVector.assign(10, 99);
        ftVector.assign(10, 99);

        asserter(stdVector, ftVector);

        stdVector.assign(100, 77);
        ftVector.assign(100, 77);

        asserter(stdVector, ftVector);
    }
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        stdVector.assign(10, 99);
        ftVector.assign(10, 99);

        asserter(stdVector, ftVector);

        stdVector.assign(5, 88);
        ftVector.assign(5, 88);

        stdVector.assign(100, 77);
        ftVector.assign(100, 77);

        asserter(stdVector, ftVector);
    }
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        stdVector.assign(0, 99);
        ftVector.assign(0, 99);

        asserter(stdVector, ftVector);
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

void relationalOperatorTest() {
    //! == test
    {
        std::vector<int> stdVec;
        std::vector<int> stdVec1;
        ft::vector<int> ftVec;
        ft::vector<int> ftVec1;

        assert((stdVec == stdVec1) == (ftVec == ftVec1));

        stdVec.push_back(1);
        stdVec1.push_back(1);
        ftVec.push_back(1);
        ftVec1.push_back(1);

        assert((stdVec == stdVec1) == (ftVec == ftVec1));

        stdVec.reserve(10);
        stdVec1.reserve(10);
        ftVec.reserve(10);
        ftVec1.reserve(10);

        assert((stdVec == stdVec1) == (ftVec == ftVec1));

        stdVec.resize(100);
        stdVec1.resize(100);
        ftVec.resize(100);
        ftVec1.resize(100);

        assert((stdVec == stdVec1) == (ftVec == ftVec1));

        stdVec.resize(1000, 9);
        stdVec1.resize(1000, 9);
        ftVec.resize(1000, 9);
        ftVec1.resize(1000, 9);

        assert((stdVec == stdVec1) == (ftVec == ftVec1));

        stdVec1.push_back(1);
        ftVec1.push_back(1);

        assert((stdVec == stdVec1) == (ftVec == ftVec1));
    }
    //! != test
    {
        std::vector<int> stdVec;
        std::vector<int> stdVec1;
        ft::vector<int> ftVec;
        ft::vector<int> ftVec1;

        assert((stdVec != stdVec1) == (ftVec != ftVec1));

        stdVec.push_back(1);
        stdVec1.push_back(1);
        ftVec.push_back(1);
        ftVec1.push_back(1);

        assert((stdVec != stdVec1) == (ftVec != ftVec1));

        stdVec.reserve(10);
        stdVec1.reserve(10);
        ftVec.reserve(10);
        ftVec1.reserve(10);

        assert((stdVec != stdVec1) == (ftVec != ftVec1));

        stdVec.resize(100);
        stdVec1.resize(100);
        ftVec.resize(100);
        ftVec1.resize(100);

        assert((stdVec != stdVec1) == (ftVec != ftVec1));

        stdVec1.push_back(1);
        ftVec1.push_back(1);

        assert((stdVec == stdVec1) == (ftVec == ftVec1));
    }
    //! < test
    {
        std::vector<int> stdVec;
        std::vector<int> stdVec1;
        ft::vector<int> ftVec;
        ft::vector<int> ftVec1;

        assert((stdVec < stdVec1) == (ftVec < ftVec1));

        stdVec1.push_back(1);
        ftVec1.push_back(1);

        assert((stdVec < stdVec1) == (ftVec < ftVec1));

        stdVec.push_back(1);
        stdVec.push_back(1);
        ftVec.push_back(1);
        ftVec.push_back(1);

        assert((stdVec < stdVec1) == (ftVec < ftVec1));

        stdVec1.push_back(1);
        ftVec1.push_back(1);

        assert((stdVec < stdVec1) == (ftVec < ftVec1));

        stdVec1.push_back(10);
        ftVec1.push_back(10);

        assert((stdVec < stdVec1) == (ftVec < ftVec1));

        stdVec.push_back(10);
        ftVec.push_back(10);

        assert((stdVec < stdVec1) == (ftVec < ftVec1));
    }
    //! <= test
    {
        std::vector<int> stdVec;
        std::vector<int> stdVec1;
        ft::vector<int> ftVec;
        ft::vector<int> ftVec1;

        assert((stdVec <= stdVec1) == (ftVec <= ftVec1));

        stdVec1.push_back(1);
        ftVec1.push_back(1);

        assert((stdVec <= stdVec1) == (ftVec <= ftVec1));

        stdVec.push_back(1);
        stdVec.push_back(1);
        ftVec.push_back(1);
        ftVec.push_back(1);

        assert((stdVec <= stdVec1) == (ftVec <= ftVec1));

        stdVec1.push_back(1);
        ftVec1.push_back(1);

        assert((stdVec <= stdVec1) == (ftVec <= ftVec1));

        stdVec1.push_back(10);
        ftVec1.push_back(10);

        assert((stdVec <= stdVec1) == (ftVec <= ftVec1));

        stdVec.push_back(10);
        ftVec.push_back(10);

        assert((stdVec < stdVec1) == (ftVec < ftVec1));
    }
    //! > test
    {
        std::vector<int> stdVec;
        std::vector<int> stdVec1;
        ft::vector<int> ftVec;
        ft::vector<int> ftVec1;

        assert((stdVec > stdVec1) == (ftVec > ftVec1));

        stdVec1.push_back(1);
        ftVec1.push_back(1);

        assert((stdVec > stdVec1) == (ftVec > ftVec1));

        stdVec.push_back(1);
        stdVec.push_back(1);
        ftVec.push_back(1);
        ftVec.push_back(1);

        assert((stdVec > stdVec1) == (ftVec > ftVec1));

        stdVec1.push_back(10);
        ftVec1.push_back(10);

        assert((stdVec > stdVec1) == (ftVec > ftVec1));

        stdVec.push_back(10);
        ftVec.push_back(10);

        assert((stdVec < stdVec1) == (ftVec < ftVec1));
    }
    //! >= test
    {
        std::vector<int> stdVec;
        std::vector<int> stdVec1;
        ft::vector<int> ftVec;
        ft::vector<int> ftVec1;

        assert((stdVec >= stdVec1) == (ftVec >= ftVec1));

        stdVec1.push_back(1);
        ftVec1.push_back(1);

        assert((stdVec >= stdVec1) == (ftVec >= ftVec1));

        stdVec.push_back(1);
        stdVec.push_back(1);
        ftVec.push_back(1);
        ftVec.push_back(1);

        assert((stdVec >= stdVec1) == (ftVec >= ftVec1));

        stdVec1.push_back(1);
        ftVec1.push_back(1);

        assert((stdVec >= stdVec1) == (ftVec >= ftVec1));

        stdVec1.push_back(10);
        ftVec1.push_back(10);

        assert((stdVec >= stdVec1) == (ftVec >= ftVec1));

        stdVec.push_back(10);
        ftVec.push_back(10);

        assert((stdVec < stdVec1) == (ftVec < ftVec1));
    }
    //! swap test
    {
        std::vector<int> stdVec(10, 100);
        std::vector<int> stdVec1;
        ft::vector<int> ftVec(10, 100);
        ft::vector<int> ftVec1;

        ft::swap(ftVec, ftVec1);
        std::swap(stdVec, stdVec1);
        asserter(stdVec1, ftVec1);
        asserter(stdVec, ftVec);

        ft::swap(ftVec, ftVec1);
        std::swap(stdVec, stdVec1);
        asserter(stdVec, ftVec);
        asserter(stdVec1, ftVec1);
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

void iterConstructorTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);

    ft::vector<int>::iterator empty_it;
    ft::vector<int>::const_iterator empty_const_it;

    assert(empty_it.operator->() == NULL);
    assert(empty_const_it.operator->() == NULL);

    empty_const_it = empty_it;

    //некомпилируемая строка
    //empty_it = empty_cIt;

    ft::vector<int>::iterator it = ftVec.begin();
    ft::vector<int>::const_iterator const_it = ftVec.end();

    const_it = it;
    assert(*it == *const_it);

    //некомпилируемая строка
    //it = cIt;
}

void iterCopyConstructorTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);

    ft::vector<int>::iterator it = ftVec.begin();
    ft::vector<int>::const_iterator const_it = ftVec.begin();

    ft::vector<int>::iterator copy_it(it);
    //некомпилируемая строка
    //ft::vector<int>::iterator copy_it1(const_it);
    ft::vector<int>::const_iterator copy_const_it(it);
    ft::vector<int>::const_iterator copy_const_it1(const_it);

    assert(*it == *copy_it);
    assert(*it == *copy_const_it1);
    assert(*const_it == *copy_const_it1);
}

void iterAssignTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);

    ft::vector<int>::iterator it = ftVec.begin();
    ft::vector<int>::const_iterator const_it = ftVec.begin();

    ft::vector<int>::iterator new_it;
    ft::vector<int>::const_iterator new_const_it;

    new_it = it;
    new_const_it = it;

    assert(*it == * new_it);
    assert(*it == * new_const_it);

    //некомпилируемая строка
    //new_it = const_it;
    new_const_it = const_it;
    assert(*const_it == * new_const_it);
}

void iterEqualityTest() {
    ft::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    ft::vector<int>::iterator it1;
    ft::vector<int>::iterator it2;

    //todo разобраться с противоречиями тут и в компараторе
    //assert(it1 != it2);

    it1 = vec.begin();
    it2 = vec.begin();

    assert(it1 == it2);

    ft::vector<int>::const_iterator cIt1 = vec.begin();
    ft::vector<int>::const_iterator cIt2 = vec.begin();

    assert(cIt1 == cIt2);
    assert(cIt1 == it1);

    ft::vector<int>::iterator it3 = vec.end();
    ft::vector<int>::const_iterator cIt3 = vec.end();

    assert(it3 == cIt3);
    assert(it1 != it3);
    assert(cIt1 != cIt3);
    assert(it1 != cIt3);
}


void iterMoreLessTest() {
    ft::vector<int> vec;
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(3);

    ft::vector<int>::iterator it1 = vec.begin();
    ft::vector<int>::iterator it2 = vec.begin();

    it2 = it2 + 1;
    assert(it2 > it1);
    it1 = it1 + 2;
    assert(it2 < it1);

    ft::vector<int>::const_iterator cit1 = vec.begin();
    ft::vector<int>::const_iterator cit2 = vec.begin();

    assert(it2 > cit1);
    assert(it1 > cit1);

    cit2 = cit2 + 1;
    assert(cit2 > cit1);

    cit1 = cit1 + 2;
    assert(cit2 < cit1);
}

void iterMoreLessEqualTest() {
    ft::vector<int> vec;
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(3);

    ft::vector<int>::iterator it1 = vec.begin();
    ft::vector<int>::iterator it2 = vec.begin();

    assert(it1 >= it2);
    assert(it1 <= it2);
    assert(it2 >= it1);
    assert(it2 >= it1);

    it2 = it2 + 1;
    assert(it2 >= it1);
    it1 = it1 + 2;
    assert(it2 <= it1);

    ft::vector<int>::const_iterator cit1 = vec.begin();
    ft::vector<int>::const_iterator cit2 = vec.begin();

    assert(cit1 >= cit2);
    assert(cit1 <= cit2);
    assert(cit2 >= cit1);
    assert(cit2 >= cit1);

    assert(it2 >= cit1);
    assert(it1 >= cit1);

    cit2 = cit2 + 1;
    assert(cit2 >= cit1);

    cit1 = cit1 + 2;
    assert(cit2 <= cit1);
}

void iterPlusMinusInt () {
    ft::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    ft::vector<int>::iterator it = vec.begin();
    ft::vector<int>::const_iterator cit = vec.begin();

    assert(it == cit);
    assert(*it == 1);
    assert(*cit == 1);

    it = it + 2;
    cit = cit + 2;

    assert(it == cit);
    assert(*it == 3);
    assert(*cit == 3);

    it = it + 1;
    cit = cit + 1;

    assert(it == cit);
    assert(it == vec.end());
    assert(cit == vec.end());

    it = it - 3;
    cit = cit - 3;

    assert(*it == 1);
    assert(it == cit);
    assert(it == vec.begin());
    assert(cit == vec.begin());

    *(it + 1) = 5;
    assert(*(cit + 1) == 5);
    //некомпилируемая строка
    //*(cit + 1) = 5;

    it = vec.begin();
    cit = vec.begin();
}

void iterPlusMinusEqualTest() {
    ft::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    ft::vector<int>::iterator it = vec.begin();
    ft::vector<int>::const_iterator cit = vec.begin();

    assert(it == cit);
    assert(*it == 1);
    assert(*cit == 1);

    it += 2;
    cit += 2;

    assert(it == cit);
    assert(*it == 3);
    assert(*cit == 3);

    it += 1;
    cit +=  1;

    assert(it == cit);
    assert(it == vec.end());
    assert(cit == vec.end());

    it -= 3;
    cit -= 3;

    assert(*it == 1);
    assert(it == cit);
    assert(it == vec.begin());
    assert(cit == vec.begin());

    it = 1 + it;
    cit = 1 + cit;

    assert(*it == 2);
    assert(it == cit);
}

void iterIncrementDecrementTest() {
    ft::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    ft::vector<int>::iterator it = vec.begin();
    ft::vector<int>::const_iterator cit = vec.begin();

    ++it;
    ++cit;

    assert(*it == 2);
    assert(it == cit);

    assert(*(it++) == 2);
    assert(*(cit++) == 2);

    assert(*it == 3);
    assert(it == cit);

    --it;
    --cit;
    assert(*it == 2);
    assert(it == cit);

    assert(*(it--) == 2);
    assert(*(cit--) == 2);

    assert(*it == 1);
    assert(it == cit);

    ++it;
    ++it;
    ++it;
    ++cit;
    ++cit;
    ++cit;
    assert(it == vec.end());
    assert(cit == vec.end());
}

void iterBracesTest() {
    ft::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    ft::vector<int>::iterator it = vec.begin();
    ft::vector<int>::const_iterator cit = vec.begin();

    assert(it[0] == 1);
    assert(it[0] == cit[0]);
    assert(it[1] == 2);
    assert(it[1] == cit[1]);
    assert(it[2] == 3);
    assert(it[2] == cit[2]);
}

void iterMinusIterTest() {

}

void test() {

}

int main(void) {

    std::cout << "Tests\n";
    constructorsTest();
    copyConstructorsTest();
    assignmentOperatorTest();
    resizeTests();
    assignTests();
    swapTest();
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
    dataTest();
    allocatorTest();
    exceptionSafetyTest();
    relationalOperatorTest();
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
    //test();
    return (0);
}