#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP

#include "../utils/iterator_traits.hpp"
#include "conditional.hpp"

namespace ft {

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

private:
    Iter iter_;
};

template <typename T>
reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type n, reverse_iterator<T> &iter) {
    return reverse_iterator<T>(iter + n);
}

} //namespace ft

#endif //FT_CONTAINERS_REVERSE_ITERATOR_HPP
