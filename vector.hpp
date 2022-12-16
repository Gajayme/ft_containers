#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <memory>

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
        const size_t oldCapacity = capacity_;
        if (n > capacity_) {
            reserve(n);
        }
        //todo правильно ли здесь реализована обработка исключений?
        size_t i = size_;
        try {
            for (; i < n; ++i) {
               ::new (arr_ + i) T(value);
            }
        } catch (...) {
            for (size_t j = size_; j < i; ++j) {
                (arr_ + j)->~T();
            }
            resize_exception_handler(oldCapacity);
            throw;
        }
        size_ = n;
    }

    void reserve(size_t n) {
        if (n <= capacity_) {
            return;
        }
        T *newArr = reinterpret_cast<T*>(::new int8_t[n * sizeof(T)]);
        try {
            std::uninitialized_copy(arr_, arr_ + size_, newArr);
        } catch (...) {
            delete[] reinterpret_cast<int8_t *>(arr_);
            throw;
        }
        //        size_t  i = 0;
//        try {
//            for (; i < size_; ++i) {
//                new(newArr + i) T(arr_[i]);
//            }
//        } catch(...) {
//            for (size_t j = 0; j < i; ++j) {
//                (newArr + j)->~T();
//            }
//            delete[] reinterpret_cast<int8_t *>(arr_);
//            throw;
//        }
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
        //todo правильно ли здесь реализована обработка исключений?
        try {
            ::new (arr_ + size_) T(value);
        } catch(...) {
            throw;
        }
        ++size_;
    }

    //todo нужно ли убрать эту защиту от переполнения size_
    // при pop_back( пустого вектора. В обычном векторе ее нет.
    void pop_back() {
        if (size_ == 0) {
            return;
        }
        (arr_ + size_)->~T();
        --size_;
    }

private:
    T *arr_;
    size_t size_;
    size_t capacity_;

    void resize_exception_handler (const size_t oldCapacity) {
        T *newArr = reinterpret_cast<T*>(::new int8_t[oldCapacity * sizeof(T)]);
        size_t  i = 0;
        try {
            for (; i < size_; ++i) {
                ::new(newArr + i) T(arr_[i]);
            }
        } catch(...) {
            for (size_t j = 0; j < i; ++j) {
                (newArr + j)->~T();
            }
            delete[] reinterpret_cast<int8_t *>(arr_);
            throw;
        }
        for (size_t i = 0; i <  size_; ++i) {
            (arr_ + i)->~T();
        }
        delete[] reinterpret_cast<int8_t *>(arr_);
        arr_ = newArr;
        capacity_ = oldCapacity;
    }
};

} //namespace ft

#endif //VECTOR_HPP
