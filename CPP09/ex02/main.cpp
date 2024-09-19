#include <exception>
#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " [any amount of positive integers]" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pmm(argv);
		pmm.showSortResults();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 2;
	}

	return 0;	
}