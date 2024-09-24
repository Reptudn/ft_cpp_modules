#include "PmergeMe.hpp"
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
	}
	return 0;
}

// create pairs and sort for largest pairs
void preSort(std::vector<int> &vec, int pack_size)
{
	for (auto it = vec.begin(); it < vec.end(); it += 2 * pack_size)
	{
		auto left = it;
		auto right = it + pack_size;

		if (*left > *right)
		{
			for (int i = 0; i < pack_size && right != vec.end(); i++)
			{
				std::swap(*left, *right);
				left++;
				right++;
			}
		}
	}
	if (pack_size * (unsigned long)2 < vec.size())
		preSort(vec, pack_size * 2);
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
	int val;

	val = pend.front();
	pend.erase(pend.begin());
	S.insert(S.begin(), val);

	std::vector<int>::iterator it;
	int index;
	int insert;
	do
	{
		index = jacobthal(pend.size()) % pend.size();
		it = pend.begin() + index;
		val = *it;
		pend.erase(it);
		insert = binarySearch(S, val) - S.begin();
		S.insert(binarySearch(S, val), val);
	} while (!pend.empty());
}

// TODO: implement sortPairs
void PmergeMe::sortPairs(std::vector<std::pair<int, int>> &pairs)
{
	for (auto it = pairs.begin(); it < pairs.end(); it++)
	{
		if (it->second > (it + 1)->second)
			std::swap(it, ++it);
	}
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
	sortPairs(pairs);

	for (auto it = pairs.begin(); it < pairs.end(); it++)
	{
		pend.push_back(it->first);
		S.push_back(it->second);
	}

	jacobthalInsert(S, pend);

	if (straggler)
		S.insert(binarySearch(S, straggler_val), straggler_val);

	for (auto it = S.begin(); it != S.end(); it++) std::cout << *it << " ";
	std::cout << std::endl;

	return S;
}

// https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort
