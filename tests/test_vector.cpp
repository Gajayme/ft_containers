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

void iterator_tests() {
    //! ITERATOR CONSTRUCTORS INTEGRAL TYPES
    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);
    ftVec.push_back(5);
    ftVec.push_back(6);
    ftVec.push_back(7);

    //! Создание итератора по-умолчанию
    {
        ft::vector<int>::iterator ftIt;
    }

    //! Инициализация итератора с помощью begin
    {
        ft::vector<int>::iterator ftIt = ftVec.begin();
        assert(*ftIt == ftVec.front());
    }

    //! Инициализация итератора с помощью end
    {
        ft::vector<int>::iterator ftIt = ftVec.end();
        assert(*ftIt == ftVec.back());
    }

    //! Конструктор копирования
    {
        ft::vector<int>::iterator ftIt = ftVec.end();
        ft::vector<int>::iterator ftItCopy(ftIt);

        assert(*ftIt == *ftItCopy);
    }

    //! Оператор присваивания
    {
        ft::vector<int>::iterator ftIt = ftVec.end();
        ft::vector<int>::iterator ftItCopy;
        ftItCopy = ftIt;

        assert(*ftIt == *ftItCopy);
    }

    //! operator *
    {
        ft::vector<int>::iterator ftIt = ftVec.begin();

        assert(*ftIt == ftVec.front());

        const int num = 10;
        *ftIt = num;

        assert(*ftIt == num);

        ftIt = ftVec.end();

        assert(*ftIt == ftVec.back());
    }

    //todo как правильно проверить этот оператор
    //! operator ->
    {
        ft::vector<int>::iterator ftIt = ftVec.begin();

        assert(*ftIt.operator->() == ftVec.front());
    }

    //! Operator +
    {
        ft::vector<int>::iterator ftIt = ftVec.begin();
        ftIt = ftIt + 1;

        assert(*ftIt == ftVec[1]);
        assert(*(ftIt + 1) == ftVec[2]);
        assert(*(ftIt + 5) == ftVec[6]);
    }

    //! Operator -
    {
        ft::vector<int>::iterator ftIt = ftVec.end();
        ftIt = ftIt - 1;

        assert(*ftIt == ftVec[5]);
        assert(*(ftIt - 1) == ftVec[4]);
        assert(*(ftIt - 5) == ftVec[0]);
    }
}

//void iter_const_test() {
//    ft::vector<int> ftVec;
//    ftVec.push_back(1);
//    ftVec.push_back(2);
//
//    ft::vector<int>::iterator it = ftVec.begin();
//    ft::vector<int>::const_iterator cIt = ftVec.begin();
//}

void test() {

    std::vector<int> vec;

    std::vector<int>::const_iterator cIt1 = vec.begin();
    std::vector<int>::const_iterator cIt2 = cIt1;

    cIt2 = cIt1;



//    ft::vector<int> ftVec;
//    ftVec.push_back(1);
//    ftVec.push_back(2);
//
//    ft::vector<int>::iterator it = ftVec.begin();
//    ft::vector<int>::const_iterator cIt = ftVec.begin();
//
//    cIt = it;
//
//    it = cIt;

}

int main(void) {

//    std::cout << "Tests\n";
//    constructorsTest();
//    copyConstructorsTest();
//    assignmentOperatorTest();
//    resizeTests();
//    assignTests();
//    swapTest();
//    reserveTests();
//    pushBackTest();
//    popBackTest();
//    //todo для всех const методов надо будет сделать const версии тестов
//    bracesOperatorTest();
//    atTest();
//    frontTest();
//    backTest();
//    emptyTest();
//    clearTest();
//    dataTest();
//    allocatorTest();
//    exceptionSafetyTest();
//    relationalOperatorTest();
//    iterator_tests();
    test();

    return (0);
}