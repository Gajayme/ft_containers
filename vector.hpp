#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstddef>

namespace ft {

template <class T>
class vector {
public:
	explicit vector (/* const allocator_type& alloc = allocator_type() */){
		ptr_(NULL);
		size_ = 0;
		capacity_ = 0;
	}

	size_t size() const {
		return size_;
	}

	size_t capacity() const {
		return capacity_;
	}


	bool empty() {

	}

	void rezerve(size_t n) {

	}

	void resize(size_t n, const T &value = T()) {

	}

	void push_back(const T &value) {

	}

	void pop_back() {

	}

	T &operator [](size_t n) {

	}

	const T &operator [](size_t n) {

	}

private:
    T *ptr_;
    size_t size_;
    size_t capacity_
};


} //namespace ft

#endif //VECTOR_H
