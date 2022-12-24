#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <memory>

namespace ft {

template <class T, typename AllocatorType = std::allocator<T> >
class vector {
public:
    explicit vector (const AllocatorType& alloc = AllocatorType()):
    arr_(NULL),
    size_(0),
    capacity_(0),
    allocator_(alloc) {
    }

    //todo точно ли такой конструктор
    explicit vector (size_t n, const T &value = T(), const AllocatorType& alloc = AllocatorType()):
    arr_(NULL),
    size_(0),
    capacity_(0),
    allocator_(alloc) {
//        reserve(n);
//        for (size_t i = 0; i < n; ++i) {
//            allocator_.construct(arr_ + i, value);
//        }
//        size_ = n;
        resize (n, value);
    };

    vector (const vector& other) {
        allocator_ = other.allocator_;
        arr_ = allocator_.allocate(other.capacity_);
        //arr_ = reinterpret_cast<T*>(::new int8_t[other.size_ * sizeof(T)]);
        capacity_ = other.size_;
        size_ = other.size_;
        for (size_t i = 0; i < size_; ++i) {
            allocator_.construct(arr_ + i, T(other[i]));
            //::new (arr_ + i) T(other[i]);
        }
    }

    ~vector(){
        for (size_t i = 0; i < size_; ++i) {
            allocator_.destroy(arr_ + i);
            //(arr_ + i)->~T();
        }
        if (arr_ != NULL) {
            allocator_.deallocate(arr_, capacity_);
        }
        //delete[] reinterpret_cast<int8_t *>(arr_);
    };

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
                allocator_.destroy(arr_ + i);
                //(arr_ + i)->~T();
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
        T *newArr = allocator_.allocate(n);
        //T *newArr = reinterpret_cast<T*>(::new int8_t[n * sizeof(T)]);
        try {
            std::uninitialized_copy(arr_, arr_ + size_, newArr);
        } catch (...) {
            allocator_.deallocate(newArr, n);
            //delete[] reinterpret_cast<int8_t *>(arr_);
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
            allocator_.destroy(arr_ + i);
            //(arr_ + i)->~T();
        }
        allocator_.deallocate(arr_, capacity_);
        //delete[] reinterpret_cast<int8_t *>(arr_);
        arr_ = newArr;
        capacity_ = n;
    }

    void push_back(const T &value) {
        if (capacity_ == size_) {
            reserve (size_ == 0 ? 1 : (size_ * 2));
        }
        //todo правильно ли здесь реализована обработка исключений?
        try {
            allocator_.construct(arr_ + size_, T(value));
            //::new (arr_ + size_) T(value);
        } catch(...) {
            throw;
        }
        ++size_;
    }

    void pop_back() {
        --size_;
        //(arr_ + size_)->~T();
        allocator_.destroy(arr_ + size_);
    }

    void clear() {
        for (size_t i = 0; i <  size_; ++i) {
            allocator_.destroy(arr_ + i);
            //(arr_ + i)->~T();
        }
        size_ = 0;
    }

    T& operator[](const size_t n) {
        return arr_[n];
    }

    const T& operator[](const size_t n) const {
        return  arr_[n];
    }

    T& at(const size_t n) {
        if (n >= size_) {
            throw std::out_of_range("Ft::vector:at: out of range");
        }
        return arr_[n];
    }

    const T& at(const size_t n) const{
        if (n >= size_) {
            throw std::out_of_range("Ft::vector:const_at: out of range");
        }
        return arr_[n];
    }

    T& front() {
        return arr_[0];
    }

    const T& front() const{
        return arr_[0];
    }

    T& back() {
        return arr_[size_ - 1];
    }

    const T& back() const{
        return arr_[size_ - 1];
    }


private:
    T *arr_;
    size_t size_;
    size_t capacity_;
    AllocatorType  allocator_;

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
            allocator_.destroy(arr_ + i);
            //(arr_ + i)->~T();
        }
        delete[] reinterpret_cast<int8_t *>(arr_);
        arr_ = newArr;
        capacity_ = oldCapacity;
    }
};

} //namespace ft

#endif //VECTOR_HPP
