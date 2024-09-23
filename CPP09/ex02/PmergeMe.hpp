#pragma once

#include <vector>
#include <list>
#include <algorithm>
#include <chrono>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::list<int> list;
		std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right);
		std::vector<int> fordJohnsonSort(std::vector<int> &vec);
		std::vector<int>::iterator binarySearch(std::vector<int>& result, int num);
		void jacobthalInsert(std::vector<int> &vec);
		int jacobus(int n);
	public:
		PmergeMe(char **argv);
		~PmergeMe();
		void showSortResults();
};