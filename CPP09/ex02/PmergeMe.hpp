#pragma once

#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::list<int> list;
		std::vector<int> fordJohnsonSort(std::vector<int> &vec);
		std::vector<int>::iterator binarySearch(std::vector<int>& result, int num);
		void jacobthalInsert(std::vector<int> &S, std::vector<int> &pend);
		int jacobthal(int n);
		std::vector<std::pair<int, int>> createPairs(std::vector<int> &vec);
		std::vector<std::pair<int, int>> sortPairs(std::vector<std::pair<int, int>> &pairs);
		std::vector<std::pair<int, int>> mergePairs(std::vector<std::pair<int, int>> &left, std::vector<std::pair<int, int>> &right);
	public:
		PmergeMe(char **argv, int argc);
		~PmergeMe();
		int showSortResults();
};