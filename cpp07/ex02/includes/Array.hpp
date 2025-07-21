#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template<typename T>
class Array
{
private:
	unsigned int _size;
	T* _data;
public:
	Array();
	Array(unsigned int size);
	~Array();
	Array(const Array &other);
	Array &operator=(const Array &other);

	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;
	unsigned int size() const;
};

#include "Array.tpp"
#endif