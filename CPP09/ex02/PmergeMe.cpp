#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <exception>
#include <ios>
#include <stdexcept>
#include <string>
#include <iostream>
#include <chrono>
#include <utility>
#include <vector>

PmergeMe::PmergeMe(char **argv, int argc)
{
	this->vec.reserve(argc - 1);
	for (int i = 1; argv[i]; i++)
	{
		try {
			int num = std::stoi(argv[i]);
			if (num < 0)
				throw std::runtime_error("Negative number");
			this->vec.push_back(num);
			this->list.push_back(num);
		} catch (std::exception &e) {
			throw std::runtime_error(e.what());
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

int PmergeMe::showSortResults()
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
		// TODO: implement sort for list too
		this->list.sort();
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		
		std::cout << "After:\t";
		for (auto it = this->list.begin(); it != this->list.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "Time to process a range of " << list.size() << " elements with std::list\t: " << std::showpoint << duration.count() << " nanoseconds" << std::endl;
	}
	{
		auto start = std::chrono::high_resolution_clock::now();
		vec = fordJohnsonSort(vec);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		std::cout << "Time to process a range of " << vec.size() << " elements with std::vector\t: " << std::showpoint << duration.count() << " nanoseconds" << std::endl;
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
				return 1;
			}
		}
		std::cout << "Sort succeeded: Containers are the same!" << std::endl;
	} else {
		std::cout << "Sort failed: Containers are not the same!" << std::endl;
		return 1;
	}
	return 0;
}

std::vector<int>::iterator PmergeMe::binarySearch(std::vector<int>& result, int num)
{
	auto it = result.begin();
	auto end = result.end();
	while (it != end)
	{
		auto mid = it + (end - it) / 2;
		if (*mid == num)
			return mid;
		if (*mid < num)
			it = mid + 1;
		else
			end = mid;
	}
	return it;
}

void PmergeMe::jacobthalInsert(std::vector<int> &S, std::vector<int> &pend)
{
	int val = pend.front();
	pend.erase(pend.begin());
	S.insert(S.begin(), val);

	std::vector<int>::iterator it;
	int index = -1;
	while (!pend.empty())
	{
		size_t jacob = 0;
		while ((size_t)jacobthal(jacob) < pend.size())
			jacob++;

		index = jacobthal(jacob - 1);
		it = pend.begin() + index;
		val = *it;
		pend.erase(it);
		S.insert(binarySearch(S, val), val);
	}
}

std::vector<std::pair<int, int>> PmergeMe::mergePairs(std::vector<std::pair<int, int>> &left, std::vector<std::pair<int, int>> &right)
{
	std::vector<std::pair<int, int>> res;

	auto itLeft = left.begin();
	auto itRight = right.begin();

	do
	{
		
		if (itLeft->second < itRight->second)
		{
			res.push_back(*itLeft);
			itLeft++;
		}
		else
		{
			res.push_back(*itRight);
			itRight++;
		}

	} while (itLeft != left.end() && itRight != right.end());


	while (itLeft != left.end())
	{
		res.push_back(*itLeft);
		itLeft++;
	}

	while (itRight != right.end())
	{
		res.push_back(*itRight);
		itRight++;
	}

	return res;
}

std::vector<std::pair<int, int>> PmergeMe::sortPairs(std::vector<std::pair<int, int>> &pairs)
{
	if (pairs.size() <= 1) return pairs;

	std::vector<std::pair<int, int>> left(pairs.begin(), pairs.begin() + pairs.size() / 2);
	std::vector<std::pair<int, int>> right(pairs.begin() + pairs.size() / 2, pairs.end());


	left = sortPairs(left);
	right = sortPairs(right);

	return mergePairs(left, right);
}

std::vector<std::pair<int, int>> PmergeMe::createPairs(std::vector<int> &vec)
{
	std::vector<std::pair<int, int>> pairs;
	pairs.reserve(vec.size() / 2);
	for (auto it = vec.begin(); it < vec.end(); it += 2)
	{
		if (*it > *(it + 1))
			pairs.push_back(std::make_pair(*(it + 1), *it));
		else
			pairs.push_back(std::make_pair(*it, *(it + 1)));
	}
	return pairs;
}

std::vector<int> PmergeMe::fordJohnsonSort(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return vec;

	bool straggler = false;
	int straggler_val = 0;

	std::vector<std::pair<int, int>> pairs;
	std::vector<int> S;
	std::vector<int> pend;


	S.reserve(vec.size());
	if (vec.size() % 2 != 0)
	{
		straggler_val = vec.back();
		vec.pop_back();
		straggler = true;
	}
	pend.reserve(vec.size() / 2);

	pairs = createPairs(vec);
	pairs = sortPairs(pairs);

	for (auto it = pairs.begin(); it < pairs.end(); it++)
	{
		pend.push_back(it->first);
		S.push_back(it->second);
	}

	jacobthalInsert(S, pend);

	if (straggler)
		S.insert(binarySearch(S, straggler_val), straggler_val);

	return S;
}

// https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort
