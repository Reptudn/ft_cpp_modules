#include "Array.hpp"
#include <cstddef>
#include <exception>
#include <string>
// #include <iostream>

int main()
{
	{
		Array<int> a(5);

		for (unsigned int i = 0; i < a.size(); i++)
			a[i] = i;

		a[0] = 128;

		for (unsigned int i = 0; i < a.size(); i++)
			std::cout << "Array at " << i << ":\t" << a[i] << std::endl;

		try
		{
			a[12] = 42;
		}
		catch (std::exception &e)
		{
			std::cerr << "Ooops! " << e.what() << std::endl;
		}
	}
	
	{
		Array<std::string> strs(10);

		// TODO: is auto allowed?
		// auto means automatic type deduction
		for (auto &elem : strs)
			elem = "Hello";

		for (std::size_t i = 0; i < strs.size(); i++)
			std::cout << "Array at " << i << ":\t" << strs[i] << std::endl;

		try
		{
			strs[-2] = "Banana";
		}
		catch (std::exception &e)
		{
			std::cerr << "Ooops! " << e.what() << std::endl;
		}

	}

	return 0;
}