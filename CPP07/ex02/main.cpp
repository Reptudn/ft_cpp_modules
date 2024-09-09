#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int> a(5);

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;

	a[0] = 128;

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << "Array at " << i << ":\t\t" << a[i] << std::endl;

	try
	{
		a[12] = 42;
	}
	catch (std::exception &e)
	{
		std::cerr << "Ooops! " << e.what() << std::endl;
	}
	return 0;
}