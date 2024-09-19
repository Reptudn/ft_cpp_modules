#pragma once

#include <list>
#include <algorithm>
#include <chrono>

class PmergeMe
{
	private:
		std::list<int> arr;
		std::list<int> list;
		void binarySearchInsert(int num, std::list<int> &list);
		void johnson();
		void containerSort();
		void cringeSort();
	public:
		PmergeMe(char **argv, int argc);
		~PmergeMe();
		void showSortResults();
};