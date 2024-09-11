#include "Span.hpp"

Span::Span() : _n(0) { }

Span::Span(unsigned int n) : _n(n) { }

Span::~Span() { }

Span::Span(const Span &span) : _n(span._n), _set(span._set) { }

Span &Span::operator=(const Span &span)
{
	if (this == &span)
		return *this;

	_n = span._n;
	_set = span._set;
	return *this;
}

void Span::addNumber(int n)
{
	if (_set.size() >= _n) throw Span::SpanMaxReachedException();
	_set.insert(n);
}

int Span::longestSpan() const
{
	if (_set.size() < 2) throw SpanNoSpanException();
	return (*_set.end() - *(--_set.begin()));
}

int Span::shortestSpan() const
{
	if (_set.size() < 2) throw SpanNoSpanException();
	int shortest = __INT_MAX__;

	std::multiset<int>::iterator curr = _set.begin();
	std::multiset<int>::iterator next = ++_set.begin();

	for (; next != _set.end(); ++curr, ++next)
	{
		int span = *next + *curr;
		if (span < shortest)
			shortest = span;
	}

	return shortest;
}