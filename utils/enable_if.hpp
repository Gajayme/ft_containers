#ifndef FT_CONTAINERS_ENABLE_IF_HPP
#define FT_CONTAINERS_ENABLE_IF_HPP

namespace ft{

template <bool B, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
    typedef T type;
};

} //namespace ft

#endif //FT_CONTAINERS_ENABLE_IF_HPP
