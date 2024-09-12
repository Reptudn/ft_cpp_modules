#include <iostream>
#include <stack>
#include "MutantStack.hpp"

int main()
{
	std::stack<int> stack;
	MutantStack<int> mutantStack;

	for (int i = 0; i < 100; i++)
	{
		stack.push(i);
		mutantStack.push(i);
	}

	stack.pop();
	mutantStack.pop();

	std::list<int>::iterator stack_it = stack.begin();

}