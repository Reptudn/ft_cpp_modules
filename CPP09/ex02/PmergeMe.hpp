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
		std::vector<int> newFordJohnsonSort(std::vector<int> &vec);
		int jacobthal(int n);
	public:
		PmergeMe(char **argv);
		~PmergeMe();
		void showSortResults();
};