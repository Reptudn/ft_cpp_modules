#include "Array.hpp"
#include <exception>
#include <string>

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
	
	std::cout << "-------" << std::endl;

	{
		Array<std::string> strs(10);

		for (std::string &elem : strs)
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

	std::cout << "-------" << std::endl;

	{
		Array<int> ints(10);

		for (std::size_t i = 0; i < ints.size(); i++)
			ints[i] = i;

		Array<int> ints2(ints);

		for (int &i : ints)
			i = 1;

		for (int i : ints)
			std::cout << i << std::endl;
		std::cout << std::endl;

		for (int i : ints2)
			std::cout << i << std::endl;
	}

	return 0;
}