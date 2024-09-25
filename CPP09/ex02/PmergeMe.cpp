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

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other) return *this;

	this->vec = std::vector<int>(other.vec);
	this->list = std::list<int>(other.list);
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	this->vec = std::vector<int>(other.vec);
	this->list = std::list<int>(other.list);
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor" << std::endl;
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
	std::cout << "\nAfter:\t";
	std::list<int> sorted(this->list);
	sorted.sort();
	for (auto it = sorted.begin(); it != sorted.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	{
		auto start = std::chrono::high_resolution_clock::now();
		list = fordJohnsonSortLst(list);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		std::cout << "Time to process a range of " << list.size() << " elements with std::list : " << std::showpoint << duration.count() << " nanoseconds" << std::endl;
	}
	{
		auto start = std::chrono::high_resolution_clock::now();
		vec = fordJohnsonSortVec(vec);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

		std::cout << "Time to process a range of " << vec.size() << " elements with std::vect : " << std::showpoint << duration.count() << " nanoseconds" << std::endl;
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

std::vector<int>::iterator PmergeMe::binarySearchVec(std::vector<int>& result, int num)
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

void PmergeMe::jacobthalInsertVec(std::vector<int> &S, std::vector<int> &pend)
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
		S.insert(binarySearchVec(S, val), val);
	}
}

std::vector<std::pair<int, int>> PmergeMe::mergePairsVec(std::vector<std::pair<int, int>> &left, std::vector<std::pair<int, int>> &right)
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

std::vector<std::pair<int, int>> PmergeMe::sortPairsVec(std::vector<std::pair<int, int>> &pairs)
{
	if (pairs.size() <= 1) return pairs;

	std::vector<std::pair<int, int>> left(pairs.begin(), pairs.begin() + pairs.size() / 2);
	std::vector<std::pair<int, int>> right(pairs.begin() + pairs.size() / 2, pairs.end());

	left = sortPairsVec(left);
	right = sortPairsVec(right);

	return mergePairsVec(left, right);
}

std::vector<std::pair<int, int>> PmergeMe::createPairsVec(std::vector<int> &vec)
{
	std::vector<std::pair<int, int>> pairs;
	for (auto it = vec.begin(); it < vec.end(); it += 2)
	{
		if (*it > *(it + 1))
			pairs.push_back(std::make_pair(*(it + 1), *it));
		else
			pairs.push_back(std::make_pair(*it, *(it + 1)));
	}
	return pairs;
}

std::vector<int> PmergeMe::fordJohnsonSortVec(std::vector<int> &vec)
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

	pairs = createPairsVec(vec);
	pairs = sortPairsVec(pairs);

	for (auto it = pairs.begin(); it < pairs.end(); it++)
	{
		pend.push_back(it->first);
		S.push_back(it->second);
	}

	jacobthalInsertVec(S, pend);

	if (straggler)
		S.insert(binarySearchVec(S, straggler_val), straggler_val);

	// std::cout << "Sorted vect: ";
	// for (auto it = S.begin(); it != S.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

	return S;
}

std::list<int>::iterator PmergeMe::binarySearchLst(std::list<int>& result, int num)
{
	auto it = result.begin();
	auto end = result.end();
	while (it != end)
	{
		auto mid = it;
		std::advance(mid, std::distance(it, end) / 2);
		if (*mid == num)
			return mid;
		if (*mid < num)
		{
			if (std::distance(it, mid) == 0)
				it++;
			else
				it = mid;
		}
		else
			end = mid;
	}
	return it;
}

// XXX: no clue if this is correct now
void PmergeMe::jacobthalInsertLst(std::list<int> &S, std::list<int> &pend)
{
	int val = pend.front();
	pend.pop_front();
	S.push_front(val);

	std::list<int> insertion_sequence;
	std::list<int> jacobsthal_sequence;


	size_t index = -1;
	while (++index < pend.size())
		jacobsthal_sequence.push_back(jacobthal(index));

	for (int idx : jacobsthal_sequence)
		insertion_sequence.push_back(idx);

	for (size_t i = 0; i < pend.size(); i++)
	{
		if (std::find(jacobsthal_sequence.begin(), jacobsthal_sequence.end(), i) == jacobsthal_sequence.end())
			insertion_sequence.push_back(i);
	}

	for (int idx : insertion_sequence)
	{
		auto it = pend.begin();
		std::advance(it, idx);
		if (it == pend.end())
			continue;
		int val = *it;
		pend.erase(it);
		S.insert(binarySearchLst(S, val), val);
	}

	return;

	std::list<int>::iterator it;
	index = -1;
	while (!pend.empty())
	{
		size_t jacob = 0;
		while ((size_t)jacobthal(jacob) < pend.size())
			jacob++;

		if (jacob == 0)
		{
			while (!pend.empty())
			{
				val = pend.front();
				pend.pop_front();
				S.insert(binarySearchLst(S, val), val);
			}
			break;
		}

		index = jacobthal(jacob - 1);
		it = pend.begin();
		std::advance(it, index);
		val = *it;
		pend.erase(it);
		S.insert(binarySearchLst(S, val), val);
	}
}

std::list<std::pair<int, int>> PmergeMe::mergePairsLst(std::list<std::pair<int, int>> &left, std::list<std::pair<int, int>> &right)
{
	std::list<std::pair<int, int>> res;

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

std::list<std::pair<int, int>> PmergeMe::sortPairsLst(std::list<std::pair<int, int>> &pairs)
{
	if (pairs.size() <= 1) return pairs;

	auto middle = pairs.begin();
	std::advance(middle, pairs.size() / 2);

	std::list<std::pair<int, int>> left(pairs.begin(), middle);
	std::list<std::pair<int, int>> right(middle, pairs.end());

	left = sortPairsLst(left);
	right = sortPairsLst(right);

	return mergePairsLst(left, right);
}

std::list<std::pair<int, int>> PmergeMe::createPairsLst(std::list<int> &list)
{
	std::list<std::pair<int, int>> pairs;

	auto it = list.begin();
	while (it != list.end())
	{
		int first = *it;
		++it;
		int second = *it;

		if (first > second)
			pairs.push_back(std::make_pair(second, first));
		else
			pairs.push_back(std::make_pair(first, second));
		++it;
	}
	return pairs;
}

std::list<int> PmergeMe::fordJohnsonSortLst(std::list<int> &list)
{
	if (list.size() <= 1)
		return list;

	bool straggler = false;
	int straggler_val = 0;

	std::list<std::pair<int, int>> pairs;
	std::list<int> S;
	std::list<int> pend;

	if (list.size() % 2 != 0)
	{
		straggler_val = list.back();
		list.pop_back();
		straggler = true;
	}

	pairs = createPairsLst(list);
	pairs = sortPairsLst(pairs);


	S.clear();
	pend.clear();

	for (auto it = pairs.begin(); it != pairs.end(); it++)
	{
		pend.push_back(it->first);
		S.push_back(it->second);
	}

	jacobthalInsertLst(S, pend);

	if (straggler)
		S.insert(binarySearchLst(S, straggler_val), straggler_val);

	// std::cout << "Sorted list: ";
	// for (auto it = S.begin(); it != S.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;

	return S;
}

// https://github.com/PunkChameleon/ford-johnson-merge-insertion-sort
