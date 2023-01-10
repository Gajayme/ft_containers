#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>
#include <iostream>
#include <memory>
#include "../utils/iterator_traits.hpp"
#include "../utils/remove_const.hpp"
#include "../utils/enable_if.hpp"
#include "../utils/conditional.hpp"
#include "../utils/lexicographical_compare.hpp"
#include "../utils/reverse_iterator.hpp"

namespace ft {

/*!
 * Класс vector.
 * Полностью повторяет функционал vector из библиотеки STL.
 */
template <class T, typename Allocator = std::allocator<T> >
class vector {

    /*!
     * Класс итератора с произвольным доступом.
     * Полностью повторяет функционал random_access_iterator из библиотеки STL.
     */
    template<bool IsConst>
    class random_access_iterator {
    public:

        typedef std::ptrdiff_t difference_type ;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef std::random_access_iterator_tag iterator_category;

        /*!
         * Конструктор итератора по умолчанию
         */
        random_access_iterator(const pointer ptr = NULL):
        ptr_(ptr) {
        }

        /*!
         * Конструктор копирования итератора
         */
        template <bool B>
        random_access_iterator (const random_access_iterator<B> & x, typename ft::enable_if<!B>::type* = 0) {
            ptr_ = x.operator->();
        }

        /*!
         * Оператор присваивания итератора
         */
        template<bool B>
        random_access_iterator& operator=(const random_access_iterator<B> &x) {
            ptr_ = x.operator->();
            return (*this);
        }

        /*!
         * Деструктор итератора
         */
        ~random_access_iterator() {
        }

    private:
        typedef typename ft::conditional<IsConst, const T, value_type>::value conditional_value;
        typedef typename ft::conditional<IsConst, const T&, reference>::value conditional_reference;
        typedef typename ft::conditional<IsConst, const T*, pointer>::value conditional_pointer;

        friend class reverse_iterator<random_access_iterator<IsConst> >;

    public:

        //------------------------------
        // ОПЕРАТОРЫ ДОСТУПА К УКАЗАТЕЛЮ
        //------------------------------

        /*!
         * Оператор звездочка
         */
        conditional_reference operator *() const {
            return (*ptr_);
        }

        /*!
         * Оператор стрелочка
         */
        conditional_pointer operator ->() const {
            return (ptr_);
        }

        //--------------------
        // ОПЕРАТОРЫ СРАВНЕНИЯ
        //--------------------

        /*!
         * Оператор ==
         */
        template<bool B>
        bool operator ==(const random_access_iterator<B> &other) const {
            return ptr_ == other.operator->();
        }

        /*!
         * Оператор !=
         */
        template <bool B>
        bool operator != (const random_access_iterator<B> &other) const {
            return ptr_ != other.operator->();
        }

        /*!
         * Оператор >
         */
        template<bool B>
        bool operator > (const random_access_iterator<B> &other) const {
            return ptr_ > other.operator->();
        }

        /*!
         * Оператор <
         */
        template<bool B>
        bool operator < (const random_access_iterator<B> &other) const {
            return ptr_ < other.ptr_;
        }

        /*!
         * Оператор >=
         */
        template<bool B>
        bool operator >= (const random_access_iterator<B> &other) const {
            return ptr_ >= other.operator->();
        }

        /*!
         * Оператор <=
         */
        template<bool B>
        bool operator <= (const random_access_iterator<B> &other) const {
            return ptr_ <= other.operator->();
        }

        //------------------------------------------------------
        // ОПЕРАТОРЫ ИНКРЕМЕНТА, ДЕКРЕМЕНТА, +/- int , +=/-= int
        //------------------------------------------------------

        /*!
         * Оператор iter + int
         */
        random_access_iterator<IsConst> operator +(const difference_type n) {
            return random_access_iterator<IsConst>(ptr_ + n);
        }

        /*!
         * Оператор -
         */
        random_access_iterator<IsConst> operator -(const difference_type n) {
            return random_access_iterator<IsConst>(ptr_ - n);
        }

        /*!
         * Оператор int + iter
         */
        random_access_iterator<IsConst> friend operator+(const int n, const random_access_iterator<IsConst> &iter) {
            random_access_iterator<IsConst> copy = iter;
            return (copy + n);
        }

        /*!
         * Оператор +=
         */
        random_access_iterator<IsConst> &operator+=(const difference_type n) {
            ptr_ += n;
            return *this;
        }

        /*!
         * Оператор -=
         */
        random_access_iterator<IsConst> &operator-=(const difference_type n) {
            ptr_ -= n;
            return *this;
        }

        /*!
         * Префиксный оператор --
         */
        random_access_iterator<IsConst> &operator --() {
            --ptr_;
            return *this;
        }

        /*!
         * Постфиксный оператор --
         */
        random_access_iterator<IsConst> operator --(int) {
            random_access_iterator<IsConst> tmp(ptr_);
            --ptr_;
            return tmp;
        }

        /*!
         *  Префиксный оператор ++
         */
        random_access_iterator<IsConst> &operator ++() {
            ++ptr_;
            return *this;
        }

        /*!
         *  Постфиксный оператор ++
         */
        random_access_iterator operator ++(int) {
            random_access_iterator<IsConst> tmp(ptr_);
            ++ptr_;
            return tmp;
        }

        /*!
         *  Оператор []
         */
        conditional_reference operator[](const difference_type n) const {
            return *(ptr_ + n);
        }

        /*!
         *  Оператор - (iter - iter)
         */
        template<bool B>
        difference_type operator -(random_access_iterator<B> &other) const {
            return ptr_ - other.operator->();
        }

    private:
            pointer ptr_;
    };

public:

    typedef T value_type;
    typedef Allocator allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef std::size_t size_type;

    typedef random_access_iterator<false> iterator;
    typedef random_access_iterator<true> const_iterator;
    typedef reverse_iterator<const_iterator> const_reverse_iterator;
    typedef reverse_iterator<iterator> reverse_iterator;

    /*!
     * Создает и возвращает итератор,
     * с внутренним указателем на первый элемент вектора.
     */
    iterator begin() {
        return iterator (arr_);
    }

    /*!
     * Создает и возвращает итератор,
     * с внутренним указателем элемент вектора, следующий за последним.
     */
    iterator end() {
        return iterator(arr_ + size_);
    }

    /*!
     * Создает и возвращает константный итератор,
     * с внутренним указателем на первый элемент вектора.
     */
    const_iterator begin() const {
        return const_iterator(arr_);
    }

    /*!
     * Создает и возвращает константный итератор,
     * с внутренним указателем элемент вектора, следующий за последним.
     */
    const_iterator end() const {
        return const_iterator(arr_ + size_);
    }

    /*!
     * Создает и возвращает реверсивный итератор,
     * с внутренним указателем элемент вектора, следующий за последним.
     */
    reverse_iterator rbegin() {
        return reverse_iterator(end());
    }

    /*!
     * Создает и возвращает реверсивный итератор,
     * с внутренним указателем на первый элемент вектора.
     */
    reverse_iterator rend() {
        return reverse_iterator(begin());
    }

    /*!
     * Создает и возвращает константный реверсивный итератор,
     * с внутренним указателем элемент вектора, следующий за последним.
     */
    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(end());
    }

    /*!
     * Создает и возвращает константный реверсивный итератор,
     * с внутренним указателем на первый элемент вектора.
     */
    const_reverse_iterator rend() const {
        return const_reverse_iterator(begin());
    }

    /*!
     * Конструктор по-умолчанию.
     */
    explicit vector (const allocator_type &alloc = allocator_type()):
    arr_(NULL),
    size_(0),
    capacity_(0),
    allocator_(alloc) {
    }

    /*!
     * Конструктор от элемента и количества элементов.
     * @param value элемент, копиями которого будет заполнен вектор.
     * @param n количество элементов.
     */
    explicit vector (const size_type n, const value_type &value = value_type(), const allocator_type& alloc = allocator_type()):
    arr_(NULL),
    size_(0),
    capacity_(0),
    allocator_(alloc) {
        resize (n, value);
    }

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
    //todo тут можно немного оптимизировать переприсваиванием элементов (в случае, если присваиваем к меньшему вектору), а не удаляя их
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
        for (i = 0; i <  size_; ++i) {
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
    return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool operator <= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return !(lhs > rhs);
}

template <class T, class Alloc>
bool operator >= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return !(lhs < rhs);
}

template <class T, class Alloc>
bool operator > (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return (rhs < lhs);
}

template <typename T, typename Alloc>
void swap (vector<T,Alloc>& lhs, vector<T,Alloc>& rhs){
    lhs.swap(rhs);
}

} //namespace ft

#endif //VECTOR_HPP
