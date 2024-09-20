#include "PmergeMe.hpp"
#include <exception>
#include <ios>
#include <stdexcept>
#include <string>
#include <iostream>
#include <chrono>
#include <utility>
#include <vector>

PmergeMe::PmergeMe(char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		try {
			int num = std::stoi(argv[i]);
			if (num < 0)
				throw std::runtime_error("Negative number");
			this->vec.push_back(num);
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

int PmergeMe::jacobthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobthal(n - 1) + 2 * jacobthal(n - 2);
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

	{
		auto start = std::chrono::high_resolution_clock::now();
		this->list.sort();
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		
		std::cout << "After:\t";
		for (auto it = this->list.begin(); it != this->list.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << std::showpoint << duration.count() << " nanoseconds" << std::endl;
	}
	{
		auto start = std::chrono::high_resolution_clock::now();
		vec = fordJohnsonSort(vec);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << std::showpoint << duration.count() << " nanoseconds" << std::endl;
	}

	if (vec.size() == list.size())
	{
		auto it = this->list.begin();
		auto it2 = this->vec.begin();
		for (; it != this->list.end(); it++, it2++)
		{
			if (*it != *it2)
			{
				std::cout << "Sort failed: Containers are not the same!" << std::endl;
				return;
			}
		}
		std::cout << "Sort succeeded: Containers are the same!" << std::endl;
	}
}

std::vector<int> PmergeMe::merge(const std::vector<int>& left, const std::vector<int>& right) {
	
	std::vector<int> result;

	auto itLeft = left.begin();
	auto itRight = right.begin();

	do
	{

		if (*itLeft < *itRight)
		{
			result.push_back(*itLeft);
			itLeft++;
		}
		else
		{
			result.push_back(*itRight);
			itRight++;
		}

	} while (itLeft != left.end() && itRight != right.end());

	while (itLeft != left.end())
	{
		result.push_back(*itLeft);
		itLeft++;
	}

	while (itRight != right.end())
	{
		result.push_back(*itRight);
		itRight++;
	}

	return result;
}

std::vector<int> PmergeMe::fordJohnsonSort(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return vec;

	std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
	std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());
	
	left = fordJohnsonSort(left);
	right = fordJohnsonSort(right);

	return merge(left, right);
}

std::vector<int> PmergeMe::newFordJohnsonSort(std::vector<int> &vec)
{
	std::vector<std::pair<int, int>> pairs;

	for (auto i = vec.begin(); i != vec.end(); i++)
	{
		int a = *i;
		int b = *(++i);
		if (a > b)
			pairs.push_back(std::make_pair(b, a));
		else
			pairs.push_back(std::make_pair(a, b));
	}

}