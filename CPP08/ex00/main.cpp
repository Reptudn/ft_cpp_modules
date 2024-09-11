#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> cont;

	cont.push_back(10);
	cont.push_back(30);
	cont.push_back(12);

	try
	{
		int num = *::easyfind(cont, 30);
		std::cout << "num was fond: " << num << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		::easyfind(cont, 15);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}