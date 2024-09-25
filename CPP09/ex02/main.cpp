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

	int return_val = 0;

	try
	{
		PmergeMe pmm(argv, argc);
		return_val = pmm.showSortResults();
		std::cout << "std::list is usually slower then std::vector because list is a doubly linked list and vector is a dynamic array.\nVectors dont need next and prev pointers. Vectors are faster when it comes to direct accessing elements!" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 2;
	}

	return return_val;	
}