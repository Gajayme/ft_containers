#ifndef STACK_HPP
#define STACK_HPP

//todo в будущем нужно заменить это на мою реализацию вектора
#include <vector>

//todo взять тесты из https://cplusplus.com/reference/stack/stack/?kw=stack
namespace ft {

//todo в будущем нужно заменить это на мою реализацию вектора
template <class T, class Container = std::vector<T> >
class stack {

public:
    typedef T value_type;
    typedef Container container_type;
    typedef typename Container::size_type size_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;

    explicit stack (const container_type& ctnr = container_type()):
    container_(ctnr) {
    }

    stack(const stack &other):
    container_(other.container_) {
    }

    stack & operator =(const stack &other) {
        if (*this != other) {
            container_ = other.container_;
        }
        return *this;
    }

    bool empty() const {
        return container_.empty();
    }

    size_type size() const {
        return container_.size();
    }

    value_type& top() {
        return container_.back();
    }

    const value_type& top() const {
        return container_.back();
    }

    void push (const value_type& val) {
        container_.push_back(val);
    }

    void pop() {
        container_.pop_back();
    }

    //todo видел реализацию с шаблонными параметрами нужны ли они здесь эти шаблонные параметры и для чего?
    friend bool operator== (const stack<value_type , container_type> &lhs, const stack<value_type , container_type> &rhs) {
        return lhs.container_ == rhs.container_;
    }

    friend bool operator!= (const stack<value_type , container_type> &lhs, const stack<value_type , container_type> &rhs) {
        return lhs.container_ != rhs.container_;
    }

    friend bool operator< (const stack<value_type , container_type> &lhs, const stack<value_type , container_type> &rhs) {
        return lhs.container_ < rhs.container_;
    }

    friend bool operator<= (const stack<value_type , container_type> &lhs, const stack<value_type , container_type> &rhs) {
        return lhs.container_ <= rhs.container_;
    }

    friend bool operator> (const stack<value_type , container_type> &lhs, const stack<value_type , container_type> &rhs) {
        return lhs.container_ > rhs.container_;
    }

    friend bool operator>= (const stack<value_type , container_type> &lhs, const stack<value_type , container_type> &rhs) {
        return lhs.container_ >= rhs.container_;
    }

private:
    container_type container_;
};

} //namespace ft

#endif //STACK_HPP
