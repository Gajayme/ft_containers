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
#include "../utils/is_integral.hpp"

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

        //-----------------------
        // КОНСТРУКТОРЫ ИТЕРАТОРА
        //-----------------------

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
        random_access_iterator& operator= (const random_access_iterator<B> &x) {
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

        //----------------------------------------
        // ОПЕРАТОРЫ ДОСТУПА К УКАЗАТЕЛЮ ИТЕРАТОРА
        //----------------------------------------

        /*!
         * Оператор звездочка
         */
        conditional_reference operator* () const {
            return (*ptr_);
        }

        /*!
         * Оператор стрелочка
         */
        conditional_pointer operator-> () const {
            return (ptr_);
        }

        //------------------------------
        // ОПЕРАТОРЫ СРАВНЕНИЯ ИТЕРАТОРА
        //------------------------------

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
            return ptr_ < other.operator->();
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
        conditional_reference operator[] (const difference_type n) const {
            return *(ptr_ + n);
        }

        /*!
         *  Оператор - (iter - iter)
         */
        template<bool B>
        difference_type operator - (random_access_iterator<B> other) const {
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

    //-----------------------
    // ВСЕ ВАРИАЦИИ begin/end
    //-----------------------

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

    //---------------------
    // КОНСТРУКТОРЫ ВЕКТОРА
    //---------------------

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

    /*!
     * Конструктор от двух итераторов.
     * @param first итератор на начало диапазона, значениями которого будет
     * проинициализирован вектор.
     * @param last итератор на конец диапазона, значениями которого будет
     * проинициализирован вектор.
     */
    template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
            typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0):
            arr_(NULL),
            size_(0),
            capacity_(0),
            allocator_(alloc) {
        size_type n = last - first;
        reserve(n);
        for (; first != last; ++first) {
            push_back(*first);
        }
    }

    /*!
     * Конструктор копирования
     * @param other вектор, который будет скопирован.
     */
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
            exception_cleaner(i);
            throw;
        }
    }

    /*!
     * Оператор присваивания.
     * @param other вектор, значения которого будут присвоены текущему.
     */
    vector& operator= (const vector& other) {
        if (this == &other) {
            return *this;
        }
        clear();
        if (arr_ != NULL) {
            allocator_.deallocate(arr_, capacity_);
        }
        allocator_ = other.allocator_;
        capacity_ = (other.capacity_ > capacity_) ? other.capacity_ : capacity_;
        arr_ = allocator_.allocate(capacity_);
        size_ = other.size_;
        size_type i = 0;
        try {
            for (; i < size_; ++i) {
                allocator_.construct(arr_ + i, value_type(other[i]));
            }
        } catch (...) {
            exception_cleaner(i);
            throw;
        }
        return *this;
    }

    /*!
     * Деструктор.
     */
    ~vector(){
        clear();
        if (arr_ != NULL) {
            allocator_.deallocate(arr_, capacity_);
        }
    };


    //------------------------
    // ОСНОВНЫЕ МЕТОДЫ ВЕКТОРА
    //------------------------

    /*!
     * Возвращает количество элементов в векторе.
     */
    size_type size() const {
        return size_;
    }

    /*!
     * Возвращает количество элементов в векторе, под которое
     * выделена память.
     */
    size_type capacity() const {
        return capacity_;
    }

    /*!
     * Возвращает максимально возможный размер вектора.
     */
    size_type max_size() const {
        return allocator_.max_size();
    }

    /*!
     * Пуст ли вектор.
     */
    bool empty() const {
        return size_ == 0;
    }

    /*!
     * Возвращает "сырой" указатель на данные вектора.
     */
    pointer data() {
        return arr_;
    }

    /*!
     * Возвращает константный "сырой" указатель на данные вектора.
     */
    const pointer data() const {
        return arr_;
    }

    /*!
     * Возвращает аллокатор, содержащийся в векторе.
     */
    allocator_type get_allocator() const {
        return allocator_;
    }

    /*!
     * Заменяет контент вектора, модифицирует размер вектора.
     * @param n количество элементов после изменения
     * @param val элемент, которым будет заполнен вектор после изменения
     */
    void assign (const size_type n, const value_type& val) {
        clear();
        resize(n, val);
    }

    /*!
     * Заменяет контент вектора, модифицирует размер вектора.
     * @param first количество элементов после изменения
     * @param last количество элементов после изменения
     * @param val элемент, которым будет заполнен вектор после изменения
     */
    template <class InputIterator>
    void assign (InputIterator first, InputIterator last,
                 typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
        clear();
        reserve(last - first);
        for (; first != last; ++ first) {
            push_back(*first);
        }
    }

    /*!
     * Меняет размер вектора.
     * @details Если вектор содержит больше n элементов, то его размер усекается до n элементов.
     * Если размер вектора меньше n, то добавляются недостающие элементы и инициализируются
     * значением по умолчанию.
     * @param n размер вектора после изменения.
     * @param val элемент, которым будет заполнен вектор при необходимости.
     */
    void resize(const size_type n, value_type value = value_type()) {
        if (n < size_) {
            for (size_type i = n; i < size_; ++i) {
                allocator_.destroy(arr_ + i);
            }
            size_ = n;
            return;
        }
        const size_type oldCapacity = capacity_;
        if (n > capacity_) {
            reserve((capacity_ * 2 > n) ? capacity_ * 2 : n);
        }
        size_type i = size_;
        try {
            for (; i < n; ++i) {
                allocator_.construct(arr_ + i, value);
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

    /*!
     * Меняет вместимость вектора.
     * @details Если текущая вместимость вектора больше новой, то ничего
     * не происходит. Иначе резервируется место под переданное количество элементов
     * а существующие копируются в новую память.
     * @param n новая вместимость вектора.
     */
    void reserve(const size_type n) {
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

    /*!
     * Меняет между собой содержимое векторов.
     * @param other вектор, содержимое которого будет заменено с текущим.
     */
    void swap (vector& other) {
        std::swap(arr_, other.arr_);
        std::swap(allocator_, other.allocator_);
        std::swap(capacity_, other.capacity_);
        std::swap(size_, other.size_);
    }

    /*!
     * Добавляет в вектор новый элемент.
     * @details При необходимости заново выделяет память.
     */
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

    /*!
     * Удаляет из вектора последний элемент.
     */
    void pop_back() {
        --size_;
        allocator_.destroy(arr_ + size_);
    }

    /*!
     * Добавляет в вектор элемент.
     * @param position итератор, перед которым будут добавлено новое значение.
     * @param val значение, от которого будет конструироваться добавляемый элемент.
     */
    iterator insert (const_iterator position, const value_type&  val) {
        //todo для этого я изменил оператор - у вектора (теперь он принимает рвалью ссылку. Правильно ли это?!!
        const size_type pos_distance = position - begin();
        if (capacity_ == size_) {
            capacity_ = (size_ == 0) ? 1 : (size_ * 2);
            pointer new_arr = allocator_.allocate(capacity_);
            try {
                std::uninitialized_copy(arr_, arr_ + pos_distance, new_arr);

            } catch (...) {
                allocator_.deallocate(new_arr, capacity_);
                capacity_ = size_;
                throw;
            }
            try {
                allocator_.construct(new_arr + pos_distance, val);
            } catch (...) {
                for(size_type i = 0; i < pos_distance; ++i) {
                    allocator_.destroy(new_arr + i);
                }
                allocator_.deallocate(new_arr, capacity_);
                capacity_ = size_;
                throw;
            }
            try {
                std::uninitialized_copy(arr_ + pos_distance, arr_ + size_ , new_arr + pos_distance + 1);
            } catch (...) {
                for(size_type i = 0; i <= pos_distance; ++i) {
                    allocator_.destroy(new_arr + i);
                }
                allocator_.deallocate(new_arr, capacity_);
                capacity_ = size_;
                throw;
            }
            for (size_type i = 0; i < size_; ++i) {
                allocator_.destroy(arr_ + i);
            }
            if (size_ != 0) {
                allocator_.deallocate(arr_, size_);
            }
            arr_ = new_arr;
        } else {
            for (size_type i = size_; i < pos_distance; --i) {
                allocator_.destroy(arr_+i);
                try {
                    allocator_.construct(arr_ + i, arr_[i - 1]);
                } catch (...) {
                    exception_cleaner(i);
                    throw;
                }
            }
            allocator_.destroy(arr_ + pos_distance);
            try {
                allocator_.construct(arr_ + pos_distance, val);
            } catch (...) {
                exception_cleaner(size_ - 1);
                throw;
            }
        }
        ++size_;
        return begin() + pos_distance;
    }

    /*!
     * Добавляет в вектор указанное количество элементов.
     * @param position итератор, перед которым будут добавлены новые значения.
     * @param n количество добавляемы х элементов.
     * @param val значение, от которого будут конструироваться добавляемые элементы.
     */
    void insert (const_iterator position, size_type n, const value_type& val) {
        const size_type pos_distance = position - begin();
        if (capacity_ < size_ + n) {
            size_type old_capacity = capacity_;
            capacity_ = (capacity_ * 2 < size_ + n) ? size_ + n : (capacity_ * 2);
            pointer new_arr = allocator_.allocate(capacity_);
            try {
                std::uninitialized_copy(arr_, arr_ + pos_distance, new_arr);
            } catch (...) {
                allocator_.deallocate(new_arr, capacity_);
                capacity_ = old_capacity;
                throw;
            }
            size_type j = pos_distance;
            try {
                for (; j != pos_distance + n; ++j) {
                    allocator_.construct(new_arr + j, val);
                }
            } catch (...) {
                for(size_type i = 0; i < j; ++i) {
                    allocator_.destroy(new_arr + i);
                }
                allocator_.deallocate(new_arr, capacity_);
                capacity_ = old_capacity;
                throw;
            }
            try {
                std::uninitialized_copy(arr_ + pos_distance, arr_ + size_ , new_arr + j);
            } catch (...) {
                for(size_type i = 0; i < j; ++i) {
                    allocator_.destroy(new_arr + i);
                }
                allocator_.deallocate(new_arr, capacity_);
                capacity_ = old_capacity;
                throw;
            }
            for (size_type i = 0; i < size_; ++i) {
                allocator_.destroy(arr_ + i);
            }
            if (size_ != 0) {
                allocator_.deallocate(arr_, size_);
            }
            arr_ = new_arr;
        } else {
            try {
                std::uninitialized_copy(arr_ + pos_distance, arr_ + size_, arr_ + pos_distance + n);
            } catch (...) {
                clear();
                allocator_.deallocate(arr_, capacity_);
                throw;
            }
            for (size_type i = pos_distance; i < pos_distance + n; ++i) {
                allocator_.destroy(arr_ + i);
                try {
                    allocator_.construct(arr_ + i, val);
                } catch (...) {
                    exception_cleaner(size_ + n);
                    throw;
                }
            }
        }
        size_ += n;
    }

    /*!
     * Добавляет в вектор элементы.
     * @param position итератор, перед которым будут добавлены новые значения.
     * @param first итератор на начало добавляемой последовательности.
     * @param last итератор на конец добавляемой последовательности.
     */
    template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last,
                 typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
        if (position < begin() || position > end()) {
            throw std::logic_error("vector");
        }
        const size_type pos_distance = position - begin();
        const size_type n = static_cast<size_type>(std::distance(first, last));
        if (size_ + n > capacity_) {
            size_type old_capacity = capacity_;
            capacity_ = (capacity_ * 2 < size_ + n) ? size_ + n : (capacity_ * 2);
            pointer new_arr = allocator_.allocate(capacity_);
            try {
                std::uninitialized_copy(arr_, arr_ + pos_distance, new_arr);
            } catch (...) {
                allocator_.deallocate(new_arr, capacity_);
                capacity_ = old_capacity;
                throw;
            }
            size_type j = pos_distance;
            try {
                for (; j != pos_distance + n; ++j) {
                    allocator_.construct(new_arr + j, *first);
                    ++first;
                }
            } catch (...) {
                for(size_type i = 0; i < j; ++i) {
                    allocator_.destroy(new_arr + i);
                }
                allocator_.deallocate(new_arr, capacity_);
                capacity_ = old_capacity;
                throw;
            }
            try {
                std::uninitialized_copy(arr_ + pos_distance, arr_ + size_ , new_arr + j);
            } catch (...) {
                for(size_type i = 0; i < j; ++i) {
                    allocator_.destroy(new_arr + i);
                }
                allocator_.deallocate(new_arr, capacity_);
                capacity_ = old_capacity;
                throw;
            }
            for (size_type i = 0; i < size_; ++i) {
                allocator_.destroy(arr_ + i);
            }
            if (size_ != 0) {
                allocator_.deallocate(arr_, size_);
            }
            arr_ = new_arr;
        } else {
            try {
                std::uninitialized_copy(arr_ + pos_distance, arr_ + size_, arr_ + pos_distance + n);
            } catch (...) {
                clear();
                allocator_.deallocate(arr_, capacity_);
                throw;
            }
            try {
                for (size_type i = pos_distance + n; i > pos_distance; --i) {
                    allocator_.destroy(arr_ + i);
                    allocator_.construct(arr_ + i, *last);
                    --first;
                }
            } catch (...) {
                    exception_cleaner(size_ + n);
                    throw;
            }
        }
        size_ += n;
    }

    /*!
     * Удаляет элемент по итератору.
     */
    iterator erase (const_iterator position) {
        const size_type pos_distance = position.operator->() - arr_;
        allocator_.destroy(arr_ + pos_distance);
        --size_;
        for (size_type i = pos_distance; i < size_; ++i) {
            try {
                allocator_.construct(arr_ + i, *(arr_ + i + 1));
            } catch (...) {
                clear();
                allocator_.deallocate(arr_, capacity_);
                throw ;
            }
            allocator_.destroy(arr_ + i + 1);
        }
        return (begin() + pos_distance);
    }

    /*!
     * Удаляет элементы по двум итераторам.
     * @param first итератор на первый удаляемый элемент.
     * @param last итератор на последний удаляемый элемент.
     */
    iterator erase (const_iterator first, const_iterator last) {

        const size_type first_distance = static_cast<size_type>(first.operator->() - arr_);
        const size_type size = static_cast<size_type>(last.operator->() - first.operator->());
        for (size_type i = 0; i < size; ++i) {
            allocator_.destroy(arr_ + first_distance + i);
        }

        for (size_type i = first_distance; i < size_ - size; ++i) {
            allocator_.construct(arr_ + i, *(arr_ + i + size));
            allocator_.destroy(arr_ + i + size);
        }
        size_ -= size;

        return begin() + first_distance;
    }

    /*!
     * Очищает вектор.
     * @details память не очищается, вызываются только деструкторы
     * элементов.
     */
    void clear() {
        for (size_type i = 0; i <  size_; ++i) {
            allocator_.destroy(arr_ + i);
        }
        size_ = 0;
    }

    /*!
     * Возвращает ссылку на элемент по его индексу.
     * @param n индекс элемента.
     */
    reference operator[](const size_type n) {
        return arr_[n];
    }

    /*!
     * Возвращает константную ссылку на элемент по его индексу.
     * @param n индекс элемента.
     */
    const_reference operator[](const size_type n) const {
        return  arr_[n];
    }

    /*!
     * Проверяет наличие и возвращает ссылку на элемент по его индексу.
     * @param n индекс элемента.
     * @details В случае ненахождения элемента с соответствующим индексом
     * бросается исключение.
     */
    reference at(const size_type n) {
        if (n >= size_) {
            throw std::out_of_range("Ft::vector:at: out of range");
        }
        return arr_[n];
    }

    /*!
     * Проверяет наличие и возвращает константную ссылку на элемент по его индексу.
     * @param n индекс элемента.
     * @details В случае ненахождения элемента с соответствующим индексом
     * бросается исключение.
     */
    const_reference at(const size_type n) const{
        if (n >= size_) {
            throw std::out_of_range("Ft::vector:const_at: out of range");
        }
        return arr_[n];
    }

    /*!
     * Возвращает ссылку на первый элемент вектора.
     */
    reference front() {
        return arr_[0];
    }

    /*!
     * Возвращает константную ссылку на первый элемент вектора.
     */
    const_reference front() const{
        return arr_[0];
    }

    /*!
     * Возвращает ссылку на последний элемент вектора.
     */
    reference back() {
        return arr_[size_ - 1];
    }

    /*!
     * Возвращает константную ссылку на последний элемент вектора.
     */
    const_reference back() const{
        return arr_[size_ - 1];
    }

private:
    pointer arr_;
    size_type size_;
    size_type capacity_;
    allocator_type allocator_;

    /*!
     * Функция для очистки памяти при обработке исключений.
     */
    void exception_cleaner (const size_type i) {
        for (size_type j = 0; j < i; ++j) {
            allocator_.destroy(arr_ + j);
        }
        if (arr_ != NULL) {
            allocator_.deallocate(arr_, capacity_);
        }
        capacity_ = 0;
        size_ = 0;
    }

    /*!
     * Функция для повторения поведения стандартного vector
     * при исключении, выброшенном в метода resize.
     */
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
            allocator_.deallocate(arr_, capacity_);
        }
        arr_ = newArr;
        capacity_ = oldCapacity;
    }
};

//-------------------
// СРАВНЕНИЕ ВЕКТОРОВ
//-------------------

/*!
 * Сравнение двух векторов на равенство.
 */
template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (typename vector<T, Alloc>::size_type i = 0; i < lhs.size(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

/*!
 * Сравнение двух векторов на неравенство.
 */
template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return !(rhs == lhs);
}

/*!
 * Сравнение двух векторов на меньше.
 */
template <class T, class Alloc>
bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

/*!
 * Сравнение двух векторов на меньше или равно.
 */
template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return !(lhs > rhs);
}

/*!
 * Сравнение двух векторов на больше или равно.
 */
template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return !(lhs < rhs);
}

/*!
 * Сравнение двух векторов на больше.
 */
template <class T, class Alloc>
bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return (rhs < lhs);
}

/*!
 * Обмен данными меду двумя векторами.
 */
template <typename T, typename Alloc>
void swap (vector<T,Alloc>& lhs, vector<T,Alloc>& rhs){
    lhs.swap(rhs);
}

} //namespace ft

namespace std {
//
//template <>
//void swap<vector<>


} //namespace std

#endif //VECTOR_HPP
