#ifndef FT_CONTAINERS_UTILITY_HPP
#define FT_CONTAINERS_UTILITY_HPP

#include <stddef.h>
#include <iterator>

namespace ft {

template <bool B, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
    typedef T type;
};

template <typename Iterator>
struct iterator_traits {
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
};

template <class T>
struct iterator_traits<T*> {
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef std::random_access_iterator_tag iterator_category;
};

template <class T>
struct iterator_traits<const T*> {
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef const T* pointer;
    typedef const T& reference;
    typedef std::random_access_iterator_tag iterator_category;
};

template<typename Iter>
class reverse_iterator {
public:
    typedef typename iterator_traits<Iter>::difference_type difference_type;
    typedef typename iterator_traits<Iter>::value_type value_type;
    typedef typename iterator_traits<Iter>::pointer pointer;
    typedef typename iterator_traits<Iter>::reference reference;
    typedef typename iterator_traits<Iter>::iterator_category iterator_category;

private:
    typedef typename Iter::conditional_value conditional_value;
    typedef typename Iter::conditional_reference conditional_reference;
    typedef typename Iter::conditional_pointer conditional_pointer;

public:

    reverse_iterator(Iter iter = NULL):
            iter_(iter) {
    }

    template<typename T>
    reverse_iterator(const reverse_iterator<T> &other):
            iter_(other.base()) {
    }

    Iter base() const {
        return iter_;
    }

    conditional_reference operator*() const {
        Iter tmp = iter_;
        return (*--tmp);
    }

    conditional_pointer operator->() const {
        return &(operator*());
    }

    reverse_iterator<Iter> operator+(difference_type n) const {
        Iter tmp = iter_;
        return reverse_iterator<Iter>(tmp - n);
    }

    reverse_iterator<Iter> &operator++() {
        --iter_;
        return *this;
    }

    reverse_iterator<Iter> operator++(int) {
        reverse_iterator<Iter> tmp(iter_);
        --iter_;
        return tmp;
    }

    reverse_iterator<Iter>& operator+=(difference_type n) {
        iter_ -= n;
        return *this;
    }

    reverse_iterator<Iter> &operator--() {
        ++iter_;
        return *this;
    }

    reverse_iterator<Iter>  operator--(int) {
        reverse_iterator<Iter> tmp(iter_);
        ++iter_;
        return tmp;
    }

    reverse_iterator<Iter>& operator-=(difference_type n) {
        iter_ += n;
        return *this;
    }

    reverse_iterator<Iter> operator-(difference_type n) const {
        Iter tmp = iter_;
        return reverse_iterator<Iter>(tmp + n);
    }

    template <typename T>
    difference_type operator-(const reverse_iterator<T>& other) const {
        return (other.operator->() - operator->());
    }

    conditional_reference operator[](const difference_type n) const {
        return iter_[-n - 1];
    }

    template <class Iterator>
    bool operator== (const reverse_iterator<Iterator> &other) const {
        return other.base() == iter_;
    }

    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator> &other) const {
        return other.base() != iter_;
    }

    template <class Iterator>
    bool operator< (const reverse_iterator<Iterator> &other) const {
        return iter_ > other.base();
    }

    template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator> &other) const {
        return iter_ >= other.base();
    }

    template <class Iterator>
    bool operator> (const reverse_iterator<Iterator> &other) const {
        return iter_ < other.base();
    }

    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator> &other) const {
        return iter_ <= other.base();
    }

private:
    Iter iter_;
};

template <typename T>
reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type n, reverse_iterator<T> &iter) {
    return reverse_iterator<T>(iter + n);
}


template <typename T>
struct remove_const {
    typedef T type;
};

template <typename T>
struct remove_const<const T> {
    typedef T type;
};

template<typename T> struct is_integral { static const bool value = false;};

template<> struct is_integral<bool> { static const bool value = true;};
template<> struct is_integral<char> { static const bool value = true;};
//template<> struct is_integral<char16_t> { static const bool value = true;};
//template<> struct is_integral<char32_t> { static const bool value = true;};
template<> struct is_integral<wchar_t> { static const bool value = true;};
template<> struct is_integral<signed char> { static const bool value = true;};
template<> struct is_integral<short int> { static const bool value = true;};
template<> struct is_integral<int> { static const bool value = true;};
template<> struct is_integral<long int> { static const bool value = true;};
template<> struct is_integral<long long int> { static const bool value = true;};
template<> struct is_integral<unsigned char> { static const bool value = true;};
template<> struct is_integral<unsigned short int> { static const bool value = true;};
template<> struct is_integral<unsigned int> { static const bool value = true;};
template<> struct is_integral<unsigned long int> { static const bool value = true;};
template<> struct is_integral<unsigned long long int> { static const bool value = true;};

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                              InputIterator2 first2, InputIterator2 last2) {
    while (first1!=last1)
    {
        if (first2==last2 || *first2<*first1) {
            return false;
        } else if (*first1<*first2) {
            return true;
        }
        ++first1;
        ++first2;
    }
    return (first2!=last2);
}


template <bool B, typename T, typename U>
struct conditional {
    typedef U value;
};

template <typename T, typename U>
struct conditional<true, T, U> {
    typedef T value;
};


#endif //FT_CONTAINERS_UTILITY_HPP
