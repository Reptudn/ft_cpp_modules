#pragma once

#include <exception>
#include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int _size;
		T *_array;
	public:
		Array() : _size(0), _array(new T[0]) { };
		Array(std::size_t size) : _size(size), _array(new T[size]) { };
		Array(const Array &other)
		{
			if (_array) delete [] _array;
			_size = other.size();
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		};
		~Array()
		{ 
			if (_array) delete [] _array;
		};
		unsigned int size() const
		{
			return _size;
		};
		class ArrayIndexOutOfBounds : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Array index out of bounds";
				};
		};
		T& operator[](unsigned int index) const
		{
			if (index >= _size)
				throw ArrayIndexOutOfBounds();
			return _array[index];
		};
		Array& operator=(const Array &other)
		{
			if (this == &other) return *this;
			if (_array) delete [] _array;
			_size = other.size();
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
			return *this;
		};
};