#include "PmergeMe.hpp"
#include <exception>
#include <ios>
#include <stdexcept>
#include <string>
#include <iostream>
#include <chrono>

PmergeMe::PmergeMe(char **argv, int argc)
{
	for (int i = 1; argv[i]; i++)
	{
		try {
			std::cout << argv[i] << std::endl;
			int num = std::stoi(argv[i]);
			if (num < 0)
				throw std::runtime_error("Negative number");
			this->arr.push_back(num);
			this->list.push_back(num);
		} catch (std::exception &e) {
			(void)e;
			throw std::runtime_error("Invalid input");
		}
	}
}

PmergeMe::~PmergeMe()
{
	return;
}

void PmergeMe::showSortResults()
{
	auto it = this->list.begin();
	std::cout << "Before:\t";
	while (it != this->list.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	
	this->containerSort();
	this->cringeSort();
}

void PmergeMe::containerSort()
{
	auto start = std::chrono::high_resolution_clock::now();
	this->list.sort();
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

	std::cout << "After:\t";
	for (auto it = this->list.begin(); it != this->list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of 3000 elements with std::list : " << std::showpoint << duration.count() << " nanoseconds" << std::endl;
}

void PmergeMe::cringeSort()
{
	auto start = std::chrono::high_resolution_clock::now();


	// This is the cringe sort
	johnson(0);


	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << "Time to process a range of 3000 elements with std::list : " << std::showpoint << duration.count() << " nanoseconds" << std::endl;
}

void PmergeMe::johnson(unsigned int ind)
{
	int size = this->arr.size();

	if (ind >= size || ind + 1 == size)
		return;

	std::list<std::pair<int, int>> pairs;
	auto it = this->arr.begin();
	for (; it != arr.end(); it++)
	{
		auto a = it;
		auto b = ++it;
		if (*a < *b)
			pairs.push_back(std::make_pair(*a, *b));
		else
			pairs.push_back(std::make_pair(*b, *a));
	}

	std::list<int> tmp;
	for (auto it = pairs.begin(); it != pairs.end(); it++)
	{
		tmp.push_back(it->first);
		tmp.push_back(it->second);
	}
}