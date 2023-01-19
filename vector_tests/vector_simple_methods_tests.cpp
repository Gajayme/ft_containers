#include "vector_tests_header.h"

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

void maxSizeTest() {
    ft::vector<int> vec(10, 10);
    size_t  n = vec.max_size();
    assert(n != 0);
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

        stdVector.push_back(1);
        ftVector.push_back(1);
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
