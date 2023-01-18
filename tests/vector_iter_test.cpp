#pragma once
#include "vector_tests_header.h"

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
    ft::vector<int> vecFt;
    vecFt.push_back(1);
    vecFt.push_back(2);
    vecFt.push_back(3);

    ft::vector<int>::iterator it1 = vecFt.begin();
    ft::vector<int>::iterator it2 = ++vecFt.begin();
    ft::vector<int>::const_iterator cit1 = vecFt.begin();
    ft::vector<int>::const_iterator cit2 = ++vecFt.begin();

    std::vector<int> vecStd;
    vecStd.push_back(1);
    vecStd.push_back(2);
    vecStd.push_back(3);

    std::vector<int>::iterator itStd1 = vecStd.begin();
    std::vector<int>::iterator itStd2 = ++vecStd.begin();
    std::vector<int>::const_iterator citStd1 = vecStd.begin();
    std::vector<int>::const_iterator citStd2 = ++vecStd.begin();


    assert(it2 - it1 == itStd2 - itStd1);
    assert(it1 - it2 == itStd1 - itStd2);
    assert(cit2 - cit1 == citStd2 - citStd1);
    assert(cit1 - cit2 == citStd1 - citStd2);
    assert(cit2 - it1 == citStd2 - itStd1);
}
