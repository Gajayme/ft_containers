#include "vector_tests_header.h"

void vectorConstructorTest() {
    {
        std::vector<int> stdVector;
        ft::vector<int> ftVector;

        asserter(stdVector, ftVector);
    }
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

        std::vector<int> stdVec2(stdVec.begin(), stdVec.end());
        ft::vector<int> ftVec2(ftVec.begin(), ftVec.end());
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

        std::vector<int> stdVec2(stdVec.begin(), stdVec.begin());
        ft::vector<int> ftVec2(ftVec.begin(), ftVec.begin());
        asserter(stdVec2, ftVec2);
    }
}

void vectorAssignmentOperatorTest() {
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
