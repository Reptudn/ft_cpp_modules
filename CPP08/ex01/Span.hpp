#pragma once

#include <exception>
#include <set>

class Span
{
	private:
		unsigned int _n;
		std::multiset<int> _set;
	public:
		Span();
		~Span();
		Span(unsigned int n);
		Span(const Span &span);
		Span &operator=(const Span &span);
		void addNumber(int n);
		class SpanMaxReachedException : public std::exception // when trying to add a number and this is full already
		{
			public:
				virtual const char* what() const throw()
				{
					return "Span reached max size";
				}
		};
		class SpanNoSpanException : public std::exception // when shortestSpan() or longestSpan() are called and there is only one number
		{
			public:
				virtual const char* what() const throw()
				{
					return "No Span available";
				}
		};
		int shortestSpan() const;
		int longestSpan() const;
};