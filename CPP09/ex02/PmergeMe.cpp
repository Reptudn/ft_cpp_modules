#include "PmergeMe.hpp"
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>

PmergeMe::PmergeMe(char **argv, int argc)
{
	this->arr = new int[argc];
	for (int i = 1; argv[i]; i++)
	{
		try {
			std::cout << argv[i] << std::endl;
			int num = std::stoi(argv[i]);
			if (num < 0)
				throw std::runtime_error("Negative number");
			this->arr[i] = num;
			this->list.push_back(num);
		} catch (std::exception &e) {
			(void)e;
			throw std::runtime_error("Invalid input");
		}
	}
}

PmergeMe::~PmergeMe()
{
	delete [] this->arr;
}

void PmergeMe::showSortResults()
{
	auto it = this->list.begin();
	std::cout << "Before:\t";
	while (it != this->list.end())
		std::cout << (*it)++;
	std::cout << std::endl;

	
	this->containerSort();
	this->cringeSort();
}

void PmergeMe::containerSort()
{

	this->list.sort();
}

void PmergeMe::cringeSort()
{
	
}