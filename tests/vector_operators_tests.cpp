#include "vector_tests_header.h"

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

