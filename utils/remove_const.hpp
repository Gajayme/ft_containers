#ifndef FT_CONTAINERS_REMOVE_CONST_HPP
#define FT_CONTAINERS_REMOVE_CONST_HPP

namespace ft {

    template <typename T>
    struct remove_const {
        typedef T type;
    };

    template <typename T>
    struct remove_const<const T> {
        typedef T type;
    };

}

#endif //FT_CONTAINERS_REMOVE_CONST_HPP
