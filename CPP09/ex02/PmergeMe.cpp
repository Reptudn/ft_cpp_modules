#include "PmergeMe.hpp"
#include <exception>
#include <ios>
#include <stdexcept>
#include <string>
#include <iostream>
#include <chrono>

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

int PmergeMe::jacobus(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobus(n - 1) + 2 * jacobus(n - 2);
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

	std::cout << left.size() << " " << right.size() << std::endl;

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

void preSort(std::vector<int> &vec, int pack_size)
{
	std::cout << "pack_size: " << pack_size << std::endl;
	std::cout << "vec.size(): " << vec.size() << std::endl;
	for (auto it = vec.begin(); it < vec.end(); it += 2 * pack_size)
	{
		auto left = it;
		auto right = it + pack_size;

		if (*left > *right)
		{
			for (int i = 0; i < pack_size && right != vec.end(); i++)
			{
				std::cout << "swapping " << *left << " and " << *right << " to ";
				std::swap(*left, *right);
				std::cout << *left << " and " << *right << " with size " << pack_size << std::endl;
				left++;
				right++;
			}
		}
	}
	if (pack_size * (unsigned long)2 <= vec.size())
		preSort(vec, pack_size * 2);
}

std::vector<int>::iterator binarySearch(std::vector<int>& result, int num)
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

std::vector<int> PmergeMe::fordJohnsonSort(std::vector<int> &vec)
{
	std::vector<int> result;
	bool straggler = false;
	// if (vec.size() <= 1)
	// 	return vec;

	// std::vector<int> left(vec.begin(), vec.begin() + vec.size() / 2);
	// std::vector<int> right(vec.begin() + vec.size() / 2, vec.end());
	
	// left = fordJohnsonSort(left);
	// right = fordJohnsonSort(right);

	// return merge(left, right);

	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	if (vec.size() % 2 != 0)
	{
		result.push_back(vec.back());
		vec.pop_back();
		straggler = true;
	}

	preSort(vec, 1);
	for (auto it = vec.begin(); it != vec.end(); it++)
		result.insert(binarySearch(result, *it), *it);

	if (straggler)
		result.pop_back();
	for (auto it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
	return result;
}

// https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort