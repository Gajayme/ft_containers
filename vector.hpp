#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <iostream>

namespace ft {

template <class T>
class vector {
public:
    explicit vector (/* const allocator_type& alloc = allocator_type() */):
    arr_(NULL),
    size_(0),
    capacity_(0) {
    }

    size_t size() const {
        return size_;
    }

    size_t capacity() const {
        return capacity_;
    }

    bool empty() {
        return size_ == 0;
    }

    void resize(size_t n, const T &value = T()) {
        if (n < size_) {
            for (size_t i = n; i < size_; ++i) {
                (arr_ + i)->~T();
            }
            size_ = n;
            return;
        }
        if (n > capacity_) {
            reserve(n);
        }
        for (size_t i = size_; i < n; ++i) {
            new (arr_ + i) T(value);
        }
        size_ = n;
    }

    void reserve(size_t n) {
        if (n <= capacity_) {
            return;
        }
        T *newArr = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);
        for (size_t i = 0; i < size_; ++i) {
            new(newArr + i) T(arr_[i]);
        }
        for (size_t i = 0; i <  size_; ++i) {
            (arr_ + i)->~T();
        }
        delete[] reinterpret_cast<int8_t *>(arr_);
        arr_ = newArr;
        capacity_ = n;
    }

    void push_back(const T &value) {
        if (capacity_ == size_) {
            reserve (size_ == 0 ? 1 : (size_ * 2));
        }
        new (arr_ + size_) T(value);
        ++size_;
    }

    void pop_back() {
        if (size_ == 0) {
            return;
        }
        (arr_ + size_)->~T();
        --size_;
    }

//	T &operator [](size_t n) {
//
//	}
//
//	const T &operator [](size_t n) {
//
//	}

private:
    T *arr_;
    size_t size_;
    size_t capacity_;
};

} //namespace ft

#endif //VECTOR_HPP
