#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	std::list<int> list;

	mstack.push(5);
	list.push_back(5);

	mstack.push(17);
	list.push_back(17);

	std::cout << "TOP: " << mstack.top() << " | " << list.back() << std::endl;

	mstack.pop();
	list.pop_back();

	std::cout << "SIZE: " << mstack.size() << " | " << list.size() << std::endl;

	mstack.push(3);
	list.push_back(3);

	mstack.push(5);
	list.push_back(5);

	mstack.push(737);
	list.push_back(737);

	mstack.push(42);
	list.push_back(42);

	mstack.push(0);
	list.push_back(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lite = list.end();

	++lit;
	--lit;
	++it;
	--it;
	while (it != ite && lit != lite)
	{
		std::cout << *it << " | " << *lit << std::endl;
		++it;
		++lit;
	}

	std::cout << "----------" << std::endl;

	MutantStack<int> mstack2 = MutantStack<int>(mstack);
	MutantStack<int>::iterator it2 = mstack2.begin();
	MutantStack<int>::iterator ite2 = mstack2.end();

	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		it2++;
	}

	return 0;
}
