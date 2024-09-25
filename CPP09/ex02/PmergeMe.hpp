#pragma once

#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>

class PmergeMe
{
	private:
		int jacobthal(int n);

		std::list<int> list;
		std::list<int> fordJohnsonSortLst(std::list<int> &list);
		std::list<int>::iterator binarySearchLst(std::list<int>& result, int num);
		void jacobthalInsertLst(std::list<int> &S, std::list<int> &pend);
		std::list<std::pair<int, int>> createPairsLst(std::list<int> &list);
		std::list<std::pair<int, int>> sortPairsLst(std::list<std::pair<int, int>> &pairs);
		std::list<std::pair<int, int>> mergePairsLst(std::list<std::pair<int, int>> &left, std::list<std::pair<int, int>> &right);


		std::vector<int> vec;
		std::vector<int> fordJohnsonSortVec(std::vector<int> &vec);
		std::vector<int>::iterator binarySearchVec(std::vector<int>& result, int num);
		void jacobthalInsertVec(std::vector<int> &S, std::vector<int> &pend);
		std::vector<std::pair<int, int>> createPairsVec(std::vector<int> &vec);
		std::vector<std::pair<int, int>> sortPairsVec(std::vector<std::pair<int, int>> &pairs);
		std::vector<std::pair<int, int>> mergePairsVec(std::vector<std::pair<int, int>> &left, std::vector<std::pair<int, int>> &right);
	public:
		PmergeMe(char **argv, int argc);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();
		int showSortResults();
};