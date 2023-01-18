#include "vector_tests_header.h"

void reverseIterConstructorTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    ft::vector<int>::reverse_iterator ritDef;
    ft::vector<int>::reverse_iterator rit = ftVec.rbegin();
    ft::vector<int>::reverse_iterator rit1(rit);

    assert(*rit == 4);
    assert(*rit == *rit1);

    rit = ftVec.rend();
    assert(*--rit == 1);

    ft::vector<int>::const_reverse_iterator critDef;
    ft::vector<int>::const_reverse_iterator crit = ftVec.rbegin();
    ft::vector<int>::const_reverse_iterator crit1(crit);

    assert(*crit == 4);
    assert(*crit == *crit1);

    critDef = crit;
    assert(*crit == *critDef);

    ft::vector<int>::const_reverse_iterator crit2(rit1);
    assert(*crit2 == 4);
    assert(*rit1 == *crit2);

    ++rit1;
    crit2 = rit1;
    assert(*crit2 == 3);
    assert(*crit2 == *rit1);

    //Некомпилируемые строки
    //ft::vector<int>::reverse_iterator rit2(crit2);
    //rit = crit2;
}

void reverseIterBaseTest() {
    std::vector<int> stdVec;
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);
    stdVec.push_back(4);

    std::vector<int>::reverse_iterator ritStd = stdVec.rbegin();
    std::vector<int>::iterator itStd = ritStd.base();

    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    ft::vector<int>::reverse_iterator ritFt = ftVec.rbegin();
    ft::vector<int>::iterator itFt = ritFt.base();
    ft::vector<int>::iterator itFt1 = ritFt.base();

    assert(itStd == stdVec.end());
    assert(itFt == ftVec.end());
    assert(*--itStd == *--itFt);
    assert(*itStd == 4);

    ++ritStd;
    ++ritStd;
    ++ritStd;
    ++ritStd;

    ++ritFt;
    ++ritFt;
    ++ritFt;
    ++ritFt;

    itStd = ritStd.base();
    itFt = ritFt.base();

    assert(itStd == stdVec.begin());
    assert(itFt == ftVec.begin());
    assert(*itStd == *itFt);
}


void reverseIteratorDereferenceTest() {
    std::vector<int> stdVec;
    stdVec.push_back(1);
    std::vector<int>::reverse_iterator ritStd = stdVec.rbegin();
    std::vector<int>::const_reverse_iterator critStd = stdVec.rbegin();

    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ft::vector<int>::reverse_iterator ritFt = ftVec.rbegin();
    ft::vector<int>::const_reverse_iterator critFt = ftVec.rbegin();

    assert(*ritStd == *ritFt);
    assert(*critStd == *critFt);
}

void reverseIteratorPlusIntTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    ft::vector<int>::reverse_iterator ritFt = ftVec.rbegin();

    assert(*ritFt == 4);
    assert(*(ritFt + 1) == 3);
    assert(*(ritFt + 3) == 1);
    assert((ritFt + 4).base() == ftVec.begin());
}

void intPlusReverseIteratorTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    ft::vector<int>::reverse_iterator ritFt = ftVec.rbegin();

    assert(*ritFt == 4);
    assert(*(1 + ritFt) == 3);
    assert(*(3 + ritFt) == 1);
    assert((4 + ritFt).base() == ftVec.begin());
}

void reverseIteratorIncrementTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    ft::vector<int>::reverse_iterator ritFt = ftVec.rbegin();
    ft::vector<int>::const_reverse_iterator critFt = ftVec.rbegin();

    assert(*ritFt++ == 4);
    assert(*critFt++ == 4);
    assert(*ritFt == 3);
    assert(*critFt == 3);
    assert(*++ritFt == 2);
    assert(*++critFt == 2);
}

void reverseIteratorDecrementTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    ft::vector<int>::reverse_iterator ritFt = ftVec.rend();
    ft::vector<int>::const_reverse_iterator critFt = ftVec.rend();

    assert(*--ritFt == 1);
    assert(*--critFt == 1);
    assert(*ritFt-- == 1);
    assert(*critFt-- == 1);
    assert(*--ritFt == 3);
    assert(*--critFt == 3);
}

void reverseIteratorPlusEqualTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    ft::vector<int>::reverse_iterator ritFt = ftVec.rbegin();
    ft::vector<int>::const_reverse_iterator critFt = ftVec.rbegin();

    assert (*ritFt == 4);
    ritFt += 1;
    critFt += 1;
    assert (*ritFt == *critFt);

    ritFt += 2;
    critFt += 2;
    assert (*ritFt == *ftVec.begin());
    assert (*ritFt == *critFt);
}

void reverseIteratorMinusEqualTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    ft::vector<int>::reverse_iterator ritFt = ftVec.rend();
    ft::vector<int>::const_reverse_iterator critFt = ftVec.rend();

    ritFt -= 1;
    critFt -= 1;
    assert (*ritFt == 1);
    assert (*ritFt == *critFt);

    ritFt -= 3;
    critFt -= 3;
    assert (*ritFt == *--ftVec.end());
    assert (*ritFt == *critFt);
}

void reverseIteratorMinusReverseIteratorTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    std::vector<int> stdVec;
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);
    stdVec.push_back(4);

    ft::vector<int>::reverse_iterator rit1Ft = ftVec.rbegin();
    ft::vector<int>::reverse_iterator rit2Ft = ftVec.rend();
    ft::vector<int>::const_reverse_iterator crit1Ft = ftVec.rbegin();
    ft::vector<int>::const_reverse_iterator crit2Ft = ftVec.rend();

    std::vector<int>::reverse_iterator rit1Std = stdVec.rbegin();
    std::vector<int>::reverse_iterator rit2Std = stdVec.rend();
    std::vector<int>::const_reverse_iterator crit1Std = stdVec.rbegin();
    std::vector<int>::const_reverse_iterator crit2Std = stdVec.rend();

    assert(rit2Ft - rit1Ft == rit2Std - rit1Std);
    assert(crit2Ft - crit1Ft == crit2Std - crit1Std);
    assert(crit2Ft - rit1Ft == crit2Std - rit1Std);

    assert(rit1Ft - rit2Ft == rit1Std - rit2Std);
    assert(crit1Ft - crit2Ft == crit1Std - crit2Std);
    assert(crit1Ft - rit2Ft == crit1Std - rit2Std);
}

void reverseIteratorBraceTest() {
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

    std::vector<int>::reverse_iterator ritStd = stdVec.rbegin();
    ft::vector<int>::reverse_iterator ritFt = ftVec.rbegin();

    ft::vector<int>::const_reverse_iterator critFt = ftVec.rbegin();

    assert(ritStd[0] == ritFt[0]);
    assert(ritStd[1] == ritFt[1]);
    assert(ritStd[2] == ritFt[2]);
    assert(ritStd[3] == ritFt[3]);

    assert(ritStd[0] == critFt[0]);
    assert(ritStd[1] == critFt[1]);
    assert(ritStd[2] == critFt[2]);
    assert(ritStd[3] == critFt[3]);
}

void reverseIteratorRelationTest() {
    ft::vector<int> ftVec;
    ftVec.push_back(1);
    ftVec.push_back(2);
    ftVec.push_back(3);
    ftVec.push_back(4);

    ft::vector<int>::reverse_iterator rit1 = ftVec.rbegin();
    ft::vector<int>::reverse_iterator rit2 = ftVec.rbegin();
    ft::vector<int>::const_reverse_iterator crit1 = ftVec.rbegin();
    ft::vector<int>::const_reverse_iterator crit2 = ftVec.rbegin();

    std::vector<int> stdVec;
    stdVec.push_back(1);
    stdVec.push_back(2);
    stdVec.push_back(3);
    stdVec.push_back(4);

    std::vector<int>::reverse_iterator ritStd1 = stdVec.rbegin();
    std::vector<int>::reverse_iterator ritStd2 = stdVec.rbegin();
    std::vector<int>::const_reverse_iterator critStd1 = stdVec.rbegin();
    std::vector<int>::const_reverse_iterator critStd2 = stdVec.rbegin();

    assert(rit1 == rit2);
    assert(crit1 == crit2);
    assert(rit1 == crit2);

    ++rit2;
    ++crit2;

    assert(rit1 != rit2);
    assert(crit1 != crit2);
    assert(rit1 != crit2);

    ++rit1;
    ++crit1;

    assert(rit1 == rit2);
    assert(crit1 == crit2);
    assert(rit1 == crit2);

    --rit1;
    --crit1;
    --rit2;
    --crit2;

    assert((rit1 > rit2) == (ritStd1 > ritStd2));
    assert((rit1 >= rit2) == (ritStd1 >= ritStd2));
    assert((rit1 < rit2) == (ritStd1 < ritStd2));
    assert((rit1 <= rit2) == (ritStd1 <= ritStd2));

    assert((crit1 > crit2) == (critStd1 > critStd2));
    assert((crit1 >= crit2) == (critStd1 >= critStd2));
    assert((crit1 < crit2) == (critStd1 < critStd2));
    assert((crit1 <= crit2) == (critStd1 <= critStd2));

    ++rit1;
    ++ritStd1;
    ++crit1;
    ++critStd1;

    assert((rit1 > rit2) == (ritStd1 > ritStd2));
    assert((rit1 >= rit2) == (ritStd1 >= ritStd2));
    assert((rit1 < rit2) == (ritStd1 < ritStd2));
    assert((rit1 <= rit2) == (ritStd1 <= ritStd2));

    assert((crit1 > crit2) == (critStd1 > critStd2));
    assert((crit1 >= crit2) == (critStd1 >= critStd2));
    assert((crit1 < crit2) == (critStd1 < critStd2));
    assert((crit1 <= crit2) == (critStd1 <= critStd2));

    rit2 += 2;
    ritStd2 += 2;
    crit2 += 2;
    critStd2 += 2;

    assert((rit1 > rit2) == (ritStd1 > ritStd2));
    assert((rit1 >= rit2) == (ritStd1 >= ritStd2));
    assert((rit1 < rit2) == (ritStd1 < ritStd2));
    assert((rit1 <= rit2) == (ritStd1 <= ritStd2));

    assert((crit1 > crit2) == (critStd1 > critStd2));
    assert((crit1 >= crit2) == (critStd1 >= critStd2));
    assert((crit1 < crit2) == (critStd1 < critStd2));
    assert((crit1 <= crit2) == (critStd1 <= critStd2));
}
