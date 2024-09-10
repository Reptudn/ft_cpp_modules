#include "Span.hpp"

Span::Span() : _n(0), _size(0), _array(nullptr) { }

Span::Span(unsigned int n) : _n(n), _size(0), _array(new int[n]) { }

Span::~Span()
{
	if (_array) delete [] _array;
}

Span::Span(const Span &span)
{
	if (_array) delete [] _array;
	_n = span._n;
	_size = span._size;
	_array = new int[_n];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = span._array[i];
}

Span &Span::operator=(const Span &span)
{
	if (this == &span)
		return *this;

	if (_array) delete [] _array;
	_n = span._n;
	_size = span._size;
	_array = new int[_n];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = span._array[i];
}