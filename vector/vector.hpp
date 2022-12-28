#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <memory>
#include "../iterators/iterator_traits.hpp"

namespace ft {

template <class T, typename Allocator = std::allocator<T> >
class vector {

    template<typename IT>
    class random_access_iterator {
    public:

        typedef typename iterator_traits<IT>::difference_type difference_type;
        typedef typename iterator_traits<IT>::value_type value_type;
        typedef typename iterator_traits<IT>::pointer pointer;
        typedef typename iterator_traits<IT>::reference reference;
        typedef typename iterator_traits<IT>::iterator_category iterator_category;

        random_access_iterator(IT *ptr = NULL):
        ptr_(ptr) {
        }

        random_access_iterator(const random_access_iterator<IT> &other):
        ptr_(other.ptr_) {
        }
        //todo по идее здесь вместо IT надо использовать затайпдефленные типы и что-то делать с константностью
        random_access_iterator<IT> &operator =(const random_access_iterator<IT> &other) {
            if (this != &other) {
                ptr_ = other.ptr_;
            }
        }

        ~random_access_iterator() {
        }

    private:
            IT ptr_;
    };

public:

    typedef random_access_iterator<T*> iterator;
    typedef random_access_iterator<const T*> const_iterator;

    typedef T value_type;
    typedef Allocator allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef std::size_t size_type;


    explicit vector (const allocator_type &alloc = allocator_type()):
    arr_(NULL),
    size_(0),
    capacity_(0),
    allocator_(alloc) {
    }

    explicit vector (size_type n, const value_type &value = value_type(), const allocator_type& alloc = allocator_type()):
    arr_(NULL),
    size_(0),
    capacity_(0),
    allocator_(alloc) {
        resize (n, value);
    };

    //todo может так??
//    vector (const vector& x) :  _size(0), _capacity(0){
//        *this = x;
//    }

    vector (const vector& other) {
        allocator_ = other.allocator_;
        arr_ = allocator_.allocate(other.capacity_);
        capacity_ = other.size_;
        size_ = other.size_;
        size_type i = 0;
        try {
            for (; i < size_; ++i) {
                allocator_.construct(arr_ + i, value_type(other[i]));
            }
        } catch (...) {
            //todo правильно ли здесь выставлены sz и cp после отлова исключения?
//            for (size_type j = 0; j < i; ++j) {
//                allocator_.destroy(arr_ + j);
//            }
            clear();
            if (arr_ != NULL) {
                allocator_.deallocate(arr_, capacity_);
            }
            //todo нужно ли это?
            capacity_ = 0;
            //size_ = 0;
            throw;
        }
    }
    //todo тут можно немного оптимизировать просто переприсваивая элементы (в случае, если присваиваем к меньшему вектору), а не удаляя их
    vector& operator= (const vector& other) {
        if (this == &other) {
            return *this;
        }
        clear();
        if (arr_ != NULL) {
            allocator_.deallocate(arr_, capacity_);
        }
        allocator_ = other.allocator_;
        if (other.capacity_ > capacity_) {
            capacity_ = other.capacity_;
        }
        arr_ = allocator_.allocate(capacity_);
        size_ = other.size_;
        size_type i = 0;
        try {
            for (; i < size_; ++i) {
                allocator_.construct(arr_ + i, value_type(other[i]));
            }
        } catch (...) {
            //todo правильно ли здесь выставлены sz и cp после отлова исключения?
            clear();
            if (arr_ != NULL) {
                allocator_.deallocate(arr_, capacity_);
            }
            throw;
        }
        return *this;
    }

    ~vector(){
        clear();
        if (arr_ != NULL) {
            allocator_.deallocate(arr_, capacity_);
        }
    };

    size_type size() const {
        return size_;
    }

    size_type capacity() const {
        return capacity_;
    }

    bool empty() const {
        return size_ == 0;
    }

    value_type* data() {
        return arr_;
    }

    const value_type *data() const {
        return arr_;
    }

    allocator_type get_allocator() const {
        return allocator_;
    }

    void assign (size_type n, const value_type& val) {
        clear();
        resize(n, val);
    }

    void resize(size_type n, value_type value = value_type()) {
        if (n < size_) {
            for (size_type i = n; i < size_; ++i) {
                allocator_.destroy(arr_ + i);
            }
            size_ = n;
            return;
        }
        const size_type oldCapacity = capacity_;
        if (n > capacity_) {
            reserve(n);
        }
        //todo правильно ли здесь реализована обработка исключений?
        size_type i = size_;
        try {
            for (; i < n; ++i) {
                allocator_.construct(arr_ + i, value_type(value));
            }
        } catch (...) {
            for (size_type j = size_; j < i; ++j) {
                allocator_.destroy(arr_ + j);
            }
            resize_exception_handler(oldCapacity);
            throw;
        }
        size_ = n;
    }

    void reserve(size_type n) {
        if (n <= capacity_) {
            return;
        }
        pointer newArr = allocator_.allocate(n);
        try {
            std::uninitialized_copy(arr_, arr_ + size_, newArr);
        } catch (...) {
            allocator_.deallocate(newArr, n);
            throw;
        }
        for (size_type i = 0; i <  size_; ++i) {
            allocator_.destroy(arr_ + i);
        }
        if (arr_ != NULL) {
            allocator_.deallocate(arr_, capacity_);
        }
        arr_ = newArr;
        capacity_ = n;
    }

    void swap (vector& other) {
        std::swap(arr_, other.arr_);
        std::swap(allocator_, other.allocator_);
        std::swap(capacity_, other.capacity_);
        std::swap(size_, other.size_);
    }

    void push_back(const value_type &value) {
        if (capacity_ == size_) {
            reserve (size_ == 0 ? 1 : (size_ * 2));
        }
        //todo правильно ли здесь реализована обработка исключений?
        try {
            allocator_.construct(arr_ + size_, value_type (value));
        } catch(...) {
            throw;
        }
        ++size_;
    }

    void pop_back() {
        --size_;
        allocator_.destroy(arr_ + size_);
    }

    void clear() {
        for (size_type i = 0; i <  size_; ++i) {
            allocator_.destroy(arr_ + i);
        }
        size_ = 0;
    }

    reference operator[](const size_type n) {
        return arr_[n];
    }

    const_reference operator[](const size_type n) const {
        return  arr_[n];
    }

    reference at(const size_type n) {
        if (n >= size_) {
            throw std::out_of_range("Ft::vector:at: out of range");
        }
        return arr_[n];
    }

    const_reference at(const size_type n) const{
        if (n >= size_) {
            throw std::out_of_range("Ft::vector:const_at: out of range");
        }
        return arr_[n];
    }

    reference front() {
        return arr_[0];
    }

    const_reference front() const{
        return arr_[0];
    }

    reference back() {
        return arr_[size_ - 1];
    }

    const_reference back() const{
        return arr_[size_ - 1];
    }


private:
    pointer arr_;
    size_type size_;
    size_type capacity_;
    allocator_type allocator_;

    void resize_exception_handler (const size_type oldCapacity) {
        pointer newArr = allocator_.allocate(oldCapacity);
        size_type i = 0;
        try {
            for (; i < size_; ++i) {
                allocator_.construct(newArr + i, value_type (arr_[i]));
            }
        } catch(...) {
            for (size_type j = 0; j < i; ++j) {
                allocator_.destroy(arr_ + j);
            }
            if (arr_ != NULL) {
                allocator_.deallocate(arr_, capacity_);
            }
            throw;
        }
        for (size_type i = 0; i <  size_; ++i) {
            allocator_.destroy(arr_ + i);
        }
        if (arr_ != NULL) {
            delete[] reinterpret_cast<int8_t *>(arr_);
        }
        arr_ = newArr;
        capacity_ = oldCapacity;
    }
};

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (typename vector<T, Alloc>::size_type i = 0; i != lhs.size(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

template <class T, class Alloc>
bool operator != (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return !(rhs == lhs);
}

template <class T, class Alloc>
bool operator < (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    for (typename vector<T, Alloc>::size_type i = 0; ; ++ i) {
        if (i == lhs.size() && i == rhs.size()) {
            return false;
        } else if ((i == lhs.size()) && (i != rhs.size())) {
            return true;
        } else if (i == rhs.size() && i != lhs.size()) {
            return false;
        } else if (lhs[i] != rhs[i]) {
            return (lhs[i] < rhs[i]);
        }
    }
}

template <class T, class Alloc>
bool operator <= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    for (typename vector<T, Alloc>::size_type i = 0; ; ++ i) {
        if ((i == lhs.size()) && (i == rhs.size())) {
            return true;
        } else if ((i == lhs.size()) && (i != rhs.size())) {
            return true;
        } else if ((i == rhs.size()) && (i != lhs.size())) {
            return false;
        } else if (lhs[i] != rhs[i]) {
            return (lhs[i] < rhs[i]);
        }
    }
}

template <class T, class Alloc>
bool operator >= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    for (typename vector<T, Alloc>::size_type i = 0; ; ++ i) {
        if ((i == lhs.size()) && (i == rhs.size())) {
            return true;
        } else if ((i == lhs.size()) && (i != rhs.size())) {
            return false;
        } else if ((i == rhs.size()) && (i != lhs.size())) {
            return true;
        } else if (lhs[i] != rhs[i]) {
            return (lhs[i] > rhs[i]);
        }
    }
}

template <class T, class Alloc>
bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    for (typename vector<T, Alloc>::size_type i = 0; ; ++ i) {
        if ((i == lhs.size()) && (i == rhs.size())) {
            return false;
        } else if ((i == lhs.size()) && (i != rhs.size())) {
            return false;
        } else if ((i == rhs.size()) && (i != lhs.size())) {
            return true;
        } else if (lhs[i] != rhs[i]) {
            return (lhs[i] > rhs[i]);
        }
    }
}

template <class T, class Alloc>
void swap (vector<T,Alloc>& lhs, vector<T,Alloc>& rhs){
    lhs.swap(rhs);
}

} //namespace ft

#endif //VECTOR_HPP
