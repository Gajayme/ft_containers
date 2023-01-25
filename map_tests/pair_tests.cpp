
#include <string>

#include "map_tests_header.hpp"
#include "../utils/pair.hpp"

template<typename T, typename U>
void pair_assert(T lhs, U rhs) {
    assert(lhs.first == rhs.first);
    assert(lhs.second == rhs.second);
}

void constructorsTest() {
    {
        ft::pair<int, char> pair1;
        ft::pair<int, char> pair2(1, 'a');
        ft::pair<int, char> pair3(pair2);
        pair1 = pair2;

        std::pair<int, char> stdPair(1, 'a');


        assert(pair1.first == 1);
        assert(pair1.second == 'a');

        pair_assert(pair1, pair2);
        pair_assert(pair1, pair3);
        pair_assert(pair1, stdPair);
    }
    {
        ft::pair<int, char> pair1(1, 'a');
        ft::pair<int, float> pair2(pair1);
        ft::pair<int, float> pair3;
        pair3 = pair1;

        //non compiled lines of code
        //ft::pair<int, std::string> pair4(1, 1);
        //std::pair<int, std::string> stdPair4(1, 1);

        std::pair<int, char> stdPair1(1, 'a');
        std::pair<int, float> stdPair2(stdPair1);
        std::pair<int, float> stdPair3;
        stdPair3 = stdPair1;


        pair_assert(pair1, stdPair1);
        pair_assert(pair2, stdPair2);
        pair_assert(pair3, stdPair3);
    }
    {
        ft::pair<const int, char> pair2;
        //non compiled lines of code
        //pair2.first = 2;

        ft::pair<int, const char> pair3;
        //non compiled lines of code
        //pair3.second = 'b';

        std::pair<const int, char> stdPair1;
        //non compiled lines of code
        //stdPair1.first = 2;

        std::pair<int, const char> stdPair2;
        //non compiled lines of code
        //stdPair2.second = 'b';

    }
    {
        std::pair<int, char>::first_type a = 1;
        std::pair<int, char>::second_type b = 'a';

        ft::pair<int, char>::first_type c = 1;
        ft::pair<int, char>::second_type d = 'a';
    }
}


//todo продолжить отсюда
void makePairTest() {
    {
        ft::pair<int, char> pair1(1, 'a');

        assert(pair1.first ==  ft::make_pair(1, 'a').first);
        assert(pair1.second ==  ft::make_pair(1, 'a').second);
    }
    {
        ft::pair<int, char> pair1 = ft::make_pair(1, 'a');
        ft::pair<int, char> pair2 = ft::make_pair(1, 'a');

        assert(pair1.first == pair2.first);
        assert(pair1.second == pair2.second);
    }
    {
        ft::pair<int, char> pair1(1, 'a');
        ft::pair<int, char> pair2;
        pair2 = ft::make_pair(1, 'a');

        assert(pair1.first == pair2.first);
        assert(pair1.second == pair2.second);
    }
}
