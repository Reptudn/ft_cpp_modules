#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() { };
		~MutantStack() = default;
		MutantStack(const MutantStack<T> &other) : std::stack<T>(other) { };
		MutantStack &operator=(const MutantStack<T> &other)
		{
			if (this == *other) return *this;
			this->c = other.c;
			return *this;
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); };
		iterator end() { return this->c.end(); };
};
