#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP

#include "../utils/iterator_traits.hpp"
#include "conditional.hpp"

namespace ft {

template<typename Iter, typename T>
class reverse_iterator {
public:
    typedef typename std::ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef typename iterator_traits<Iter>::iterator_category iterator_category;

private:
    //typedef typename ft::conditional<IsCoconst value_type , value_type>::value conditional_value;
    //typedef typename ft::conditional<IsCoconst reference , reference>::value conditional_reference;
    //typedef typename ft::conditional<IsCoconst pointer , pointer>::value conditional_pointer;

public:

    reverse_iterator(Iter iter = NULL):
    iter_(iter) {
    }

    template<typename U, typename Y>
    reverse_iterator(const reverse_iterator<U, Y> &other):
    iter_(other.base()) {
    }

    reverse_iterator<Iter, T> &operator++() {
        --iter_;
        return *this;
    }

    Iter base() const {
        return iter_;
    }

    reverse_iterator<Iter, T> &operator--() {
        ++iter_;
        return *this;
    }

     reference operator*() const {
        Iter tmp = iter_;
        return (*--tmp);
    }

private:
    Iter iter_;
};

} //namespace ft

#endif //FT_CONTAINERS_REVERSE_ITERATOR_HPP
