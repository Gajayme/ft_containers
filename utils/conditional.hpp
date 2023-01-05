#ifndef FT_CONTAINERS_CONDITIONAL_HPP
#define FT_CONTAINERS_CONDITIONAL_HPP

namespace ft {

template <bool B, typename T, typename U>
struct conditional {
    typedef U value;
};

template <typename T, typename U>
struct conditional<true, T, U> {
    typedef T value;
};

} // namespace ft

#endif //FT_CONTAINERS_CONDITIONAL_HPP
