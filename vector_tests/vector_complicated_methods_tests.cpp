#include "vector_tests_header.h"

void resizeTests() {
    //! тесты с int
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;
        asserter(stdVector, ftVector);

        stdVector.resize(0);
        ftVector.resize(0);

        asserter(stdVector, ftVector);

        stdVector.resize(5);
        ftVector.resize(5);

        asserter(stdVector, ftVector);

        stdVector.resize(3, 1000);
        ftVector.resize(3, 1000);

        asserter(stdVector, ftVector);

        stdVector.resize(0);
        ftVector.resize(0);

        asserter(stdVector, ftVector);
    }

    //! тесты с пользовательским классом без конструктора по умолчания, но с конструктором копирования
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;

        asserter(stdVector, ftVector);

        stdVector.resize(0);
        ftVector.resize(0);

        asserter(stdVector, ftVector);

        stdVector.resize(5);
        ftVector.resize(5);

        asserter(stdVector, ftVector);

        stdVector.resize(3, std::string("hello"));
        ftVector.resize(3, std::string("hello"));

        asserter(stdVector, ftVector);

        stdVector.resize(0);
        ftVector.resize(0);

        asserter(stdVector, ftVector);
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
    {
        std::vector<int> stdVec;
        stdVec.push_back(1);
        stdVec.push_back(2);
        stdVec.push_back(3);
        stdVec.push_back(4);

        ft::vector<int> ftVec;
        ftVec.push_back(1);
        ftVec.push_back(2);
        ftVec.push_back(3);
        ftVec.push_back(4);

        std::vector<int> stdVec2;
        ft::vector<int> ftVec2;

        stdVec2.assign(stdVec.begin(), stdVec.end());
        ftVec2.assign(ftVec.begin(), ftVec.end());
        asserter(stdVec2, ftVec2);
    }
    {
        std::vector<int> stdVec;
        stdVec.push_back(1);
        stdVec.push_back(2);
        stdVec.push_back(3);
        stdVec.push_back(4);

        ft::vector<int> ftVec;
        ftVec.push_back(1);
        ftVec.push_back(2);
        ftVec.push_back(3);
        ftVec.push_back(4);

        std::vector<int> stdVec2(10, 10);


        ft::vector<int> ftVec2(10, 10);

        stdVec2.assign(stdVec.begin(), stdVec.end());
        ftVec2.assign(ftVec.begin(), ftVec.end());
        //printer(stdVec2, ftVec2);
        asserter(stdVec2, ftVec2);
    }
    {
        std::vector<int> stdVec;
        stdVec.push_back(1);
        stdVec.push_back(2);
        stdVec.push_back(3);
        stdVec.push_back(4);

        ft::vector<int> ftVec;
        ftVec.push_back(1);
        ftVec.push_back(2);
        ftVec.push_back(3);
        ftVec.push_back(4);

        std::vector<int> stdVec2(10, 10);


        ft::vector<int> ftVec2(10, 10);

        stdVec2.assign(stdVec.begin(), stdVec.begin());
        ftVec2.assign(ftVec.begin(), ftVec.begin());
        //printer(stdVec2, ftVec2);
        asserter(stdVec2, ftVec2);
    }
    {
        std::vector<int> stdVec;

        ft::vector<int> ftVec;

        std::vector<int> stdVec2;

        ft::vector<int> ftVec2;

        stdVec2.assign(stdVec.begin(), stdVec.begin());
        ftVec2.assign(ftVec.begin(), ftVec.begin());
        //printer(stdVec2, ftVec2);
        asserter(stdVec2, ftVec2);
    }
}

void reserveTests() {
    //! тесты с int
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        asserter(stdVector, ftVector);

        stdVector.reserve(100);
        ftVector.reserve(100);

        asserter(stdVector, ftVector);

        stdVector.reserve(10);
        ftVector.reserve(10);

        asserter(stdVector, ftVector);

        stdVector.reserve(100);
        ftVector.reserve(100);

        asserter(stdVector, ftVector);

        stdVector.reserve(1000);
        ftVector.reserve(1000);

        asserter(stdVector, ftVector);
    }
    //! тесты с пользовательским классом без конструктора по умолчания, но с конструктором копирования
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;

        asserter(stdVector, ftVector);

        stdVector.reserve(100);
        ftVector.reserve(100);

        asserter(stdVector, ftVector);

        stdVector.reserve(10);
        ftVector.reserve(10);

        asserter(stdVector, ftVector);

        stdVector.reserve(100);
        ftVector.reserve(100);

        asserter(stdVector, ftVector);

        stdVector.reserve(1000);
        ftVector.reserve(1000);

        asserter(stdVector, ftVector);
    }
}

void pushBackTest(void) {
    //! int
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        asserter(stdVector, ftVector);

        stdVector.push_back(1);
        ftVector.push_back(1);

        asserter(stdVector, ftVector);

        stdVector.push_back(2);
        ftVector.push_back(2);
        stdVector.push_back(3);
        ftVector.push_back(3);
        stdVector.push_back(4);
        ftVector.push_back(4);

        asserter(stdVector, ftVector);
    }
    //! custom classes
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;

        asserter(stdVector, ftVector);

        stdVector.push_back(std::string ("hello"));
        ftVector.push_back(std::string("hello"));

        asserter(stdVector, ftVector);

        stdVector.push_back(vector_tests_classes::CopyConstructorClass());
        ftVector.push_back(vector_tests_classes::CopyConstructorClass());

        asserter(stdVector, ftVector);
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

        asserter(stdVector, ftVector);

        ftVector.push_back(1);
        ftVector.push_back(2);
        ftVector.push_back(3);
        ftVector.pop_back();

        stdVector.push_back(1);
        stdVector.push_back(2);
        stdVector.push_back(3);

        stdVector.pop_back();

        asserter(stdVector, ftVector);
    }
    //! custom classes
    {
        StdCopyCrtrVector stdVector;
        FtCopyCrtrVector ftVector;

        stdVector.push_back(std::string("hello"));
        stdVector.push_back(std::string("hello"));

        ftVector.push_back(std::string("hello"));
        ftVector.push_back(std::string("hello"));

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

        asserter(stdVector, ftVector);

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
        asserter(stdVector, ftVector);
    }
    {
        StdExceptVector stdVector;
        FtExceptVector ftVector;

        stdVector.push_back(std::string("hello"));
        ftVector.push_back(std::string("hello"));

        asserter(stdVector, ftVector);

        try {
            stdVector.push_back(std::string("bye"));
            ftVector.push_back(std::string("bye"));
        } catch(...) {
            asserter(stdVector, ftVector);
        }
    }
}

void insertFirstTest() {
    std::vector<int> stdVec;
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);
    stdVec.push_back(4);

    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    std::vector<int>::const_iterator stdIt = ++stdVec.begin();
    ft::vector<int>::iterator ftIt = ++ftVec.begin();

    assert(*(ftVec.insert(ftIt, 9)) == *(stdVec.insert(stdIt, 9)));
    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());

    ftIt = ++ftVec.begin();
    stdIt = ++stdVec.begin();

    assert(*ftVec.insert(ftVec.insert(ftIt, 9), 100) == *stdVec.insert(stdVec.insert(stdIt, 9), 100));

    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());

    stdIt = stdVec.end();
    ftIt = ftVec.end();

    ftIt = ftVec.insert(ftIt, 9);
    stdIt = stdVec.insert(stdIt, 9);
    assert(*ftIt == *stdIt);

}

void insertSecondTest() {
    std::vector<int> stdVec;
    stdVec.push_back(1);
    ft::vector<int> ftVec;
    ftVec.push_back(1);

    std::vector<int>::const_iterator stdIt = stdVec.begin();
    ft::vector<int>::iterator ftIt = ftVec.begin();

    assert(*stdVec.insert(stdIt, 2) == *ftVec.insert(ftIt, 2));
    stdVec.pop_back();
    ftVec.pop_back();

    stdIt = stdVec.end();
    ftIt = ftVec.end();
    assert(*stdVec.insert(stdIt, 3) == *ftVec.insert(ftIt, 3));

    ftIt = ++ftVec.end();
    try {
        ftVec.insert(ftIt, 3);
        assert(1 == 2);
    } catch(...) {
    }
}

void insertThirdTest() {
    std::vector<int> stdVec;
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);

    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);

    std::vector<int>::const_iterator stdIt = ++stdVec.begin();
    ft::vector<int>::iterator ftIt = ++ftVec.begin();

    assert(*(ftVec.insert(ftIt, 9)) == *(stdVec.insert(stdIt, 9)));
    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());

    ftIt = ++ftVec.begin();
    stdIt = ++stdVec.begin();

    assert(*ftVec.insert(ftVec.insert(ftIt, 9), 100) == *stdVec.insert(stdVec.insert(stdIt, 9), 100));

    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());

    stdIt = stdVec.end();
    ftIt = ftVec.end();

    ftIt = ftVec.insert(ftIt, 9);
    stdIt = stdVec.insert(stdIt, 9);
    assert(*ftIt == *stdIt);

}

void secondInsertTypeFirstTest() {
    std::vector<int> stdVec;
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);
    stdVec.push_back(4);

    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    std::vector<int>::iterator itStd = ++stdVec.begin();
    ft::vector<int>::iterator itFt = ++ftVec.begin();

    ftVec.insert(itFt, 2, 9);
    stdVec.insert(itStd, 2, 9);

    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());
    for (size_t i = 0; i != ftVec.size(); ++i) {
        assert(ftVec[i] == stdVec[i]);
    }

    itStd = ++stdVec.begin();
    itFt = ++ftVec.begin();

    ftVec.insert(itFt, 10, 9);
    stdVec.insert(itStd, 10, 9);
    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());
    for (size_t i = 0; i != ftVec.size(); ++i) {
        assert(ftVec[i] == stdVec[i]);
    }
}

void secondInsertTypeSecondTest() {
    std::vector<int> stdVec;
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);
    stdVec.push_back(4);
    stdVec.reserve(100);

    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);
    ftVec.reserve(100);

    std::vector<int>::iterator itStd = ++stdVec.begin();
    ft::vector<int>::iterator itFt = ++ftVec.begin();

    ftVec.insert(itFt, 10, 9);
    stdVec.insert(itStd, 10, 9);

    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());
    for (size_t i = 0; i != ftVec.size(); ++i) {
        assert(ftVec[i] == stdVec[i]);
    }
}

void secondInsertTypeThirdTest() {
    std::vector<int> stdVec;
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);
    stdVec.push_back(4);
    std::vector<int>::iterator itStd = stdVec.end();

    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);
    ft::vector<int>::iterator itFt = ftVec.end();

    ftVec.insert(itFt, 5, 9);
    stdVec.insert(itStd, 5, 9);

    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());
    for (size_t i = 0; i != ftVec.size(); ++i) {
        assert(ftVec[i] == stdVec[i]);
    }
}

void secondInsertTypeFourthTest() {
    std::vector<int> stdVec;
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);
    stdVec.push_back(4);
    std::vector<int>::iterator itStd = stdVec.begin();

    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);
    ft::vector<int>::iterator itFt = ftVec.begin();

    ftVec.insert(itFt, 5, 9);
    stdVec.insert(itStd, 5, 9);

    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());
    for (size_t i = 0; i != ftVec.size(); ++i) {
        assert(ftVec[i] == stdVec[i]);
    }
}


void thirdInsertTypeFirstTest() {
    std::vector<int> stdVec;
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);
    stdVec.push_back(4);

    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    std::vector<int>::iterator itStd = ++stdVec.begin();
    ft::vector<int>::iterator itFt = ++ftVec.begin();

    ftVec.insert(itFt, ftVec.begin(), ftVec.begin() + 2);
    stdVec.insert(itStd, stdVec.begin(), stdVec.begin() + 2);

    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());
    for (size_t i = 0; i != ftVec.size(); ++i) {
        assert(ftVec[i] == stdVec[i]);
    }

    itStd = ++stdVec.begin();
    itFt = ++ftVec.begin();

    ftVec.insert(itFt, ftVec.begin(), ftVec.end());
    stdVec.insert(itStd, stdVec.begin(), stdVec.end());

    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());
    for (size_t i = 0; i != ftVec.size(); ++i) {
        assert(ftVec[i] == stdVec[i]);
    }
}

//todo ошибка в этом инсерте
void thirdInsertTypeSecondTest() {
    std::vector<int> stdVec;
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);
    stdVec.push_back(4);
    stdVec.reserve(100);

    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);
    ftVec.reserve(100);


    std::vector<int>::iterator itStd = ++stdVec.begin();
    ft::vector<int>::iterator itFt = ++ftVec.begin();

    stdVec.insert(itStd, stdVec.begin(), stdVec.end());
    ftVec.insert(itFt, ftVec.begin(), ftVec.end());

//    for (size_t i = 0; i != ftVec.size(); ++ i) {
//        std::cout << ftVec[i] << std::endl;
//    }
//    std::cout << std::endl;
//    for (size_t i = 0; i != stdVec.size(); ++ i) {
//        std::cout << stdVec[i] << std::endl;
//    }


    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());
    for (size_t i = 0; i != ftVec.size(); ++i) {
        assert(ftVec[i] == stdVec[i]);
    }
}

void eraseFirstTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);
    ft::vector<int>::iterator itft = ++ftVec.begin();

    std::vector<int> stdVec;
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);
    stdVec.push_back(4);
    std::vector<int>::iterator itStd = ++stdVec.begin();

    assert(*ftVec.erase(itft) == *stdVec.erase(itStd));

    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());
    for (size_t i = 0; i != ftVec.size(); ++ i) {
        assert(ftVec[i] == stdVec[i]);
    }
}

void eraseSecondTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);
    ft::vector<int>::iterator itft = ftVec.end();

    std::vector<int> stdVec;
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);
    stdVec.push_back(4);
    std::vector<int>::iterator itStd = stdVec.end();

    itStd = stdVec.begin();
    itft = ftVec.begin();


    assert(*ftVec.erase(itft) == *stdVec.erase(itStd));

    assert(ftVec.size() == stdVec.size());
    assert(ftVec.capacity() == stdVec.capacity());
    for (size_t i = 0; i != ftVec.size(); ++ i) {
        assert(ftVec[i] == stdVec[i]);
    }
}
