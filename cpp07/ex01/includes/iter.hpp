#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T, typename Func>
void iter(T* _array, size_t _length, Func _func) {
	if (!_array || _length < 1)
		return;
	for (size_t i = 0; i < _length; i++) {
		_func(_array[i]);
	}
}

template <typename T>
void printElement(T& elem) {
    std::cout << elem << " ";
}

template <typename T>
void increment(T& elem) {
    ++elem;
}

#endif