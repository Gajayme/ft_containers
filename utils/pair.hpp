#ifndef FT_CONTAINERS_PAIR_HPP
#define FT_CONTAINERS_PAIR_HPP

namespace ft {

template<typename T1, typename T2>
struct pair {
    typedef T1 first_type;
    typedef T2 second_type;


    pair():
    first(),
    second() {
    };

    pair (const first_type& a, const second_type& b):
            first(a),
            second(b) {
    }

    template<class U, class V>
    pair(const pair<U , V>& other):
    first(other.first),
    second(other.second) {
    };

    pair& operator=(const pair &other) {
        if (this == &other) {
            return *this;
        }
        first = other.first;
        second = other.second;
        return *this;
    };

    T1 first;
    T2 second;

};

template <class T1,class T2>
pair<T1,T2> make_pair (T1 a, T2 b)
{
    return pair<T1,T2>(a, b);
}

template <class T1, class T2>
bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first==rhs.first && lhs.second==rhs.second; }

template <class T1, class T2>
bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return !(lhs==rhs); }

template <class T1, class T2>
bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
}

template <class T1, class T2>
bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return !(rhs<lhs);
}

template <class T1, class T2>
bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return rhs<lhs;
}

template <class T1, class T2>
bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return !(lhs<rhs);
}

} //namespace ft

#endif //FT_CONTAINERS_PAIR_HPP
