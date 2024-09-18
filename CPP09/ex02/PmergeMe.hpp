#pragma once

#include <list>
#include <algorithm>
#include <chrono>

class PmergeMe
{
	private:
		int *arr;
		std::list<int> list;
		void containerSort();
		void cringeSort();
	public:
		PmergeMe(char **argv, int argc);
		~PmergeMe();
		void showSortResults();
};