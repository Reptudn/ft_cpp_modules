#include <iostream>
#include "iter.hpp"

int main()
{
	{
		char c[] = { 'a', 'b', 'c' };

		::iter(c, 3, ::print);

		std::cout << std::endl;
		::iter(c, 3, ::increment);
		::iter(c, 3, ::print);

		std::cout << std::endl;
		::iter(c, 3, ::decrement);
		::iter(c, 3, ::print);
	}

	std::cout << std::endl;

	{
		int i[] = { 1, 2, 3 };

		::iter(i, 3, ::print);

		std::cout << std::endl;
		::iter(i, 3, ::increment);
		::iter(i, 3, ::print);

		std::cout << std::endl;
		::iter(i, 3, ::decrement);
		::iter(i, 3, ::print);
	}

	std::cout << std::endl;

	{
		float f[] = { 1.1f, 2.2f, 3.3f };

		::iter(f, 3, ::print);

		std::cout << std::endl;
		::iter(f, 3, ::increment);
		::iter(f, 3, ::print);

		std::cout << std::endl;
		::iter(f, 3, ::decrement);
		::iter(f, 3, ::print);
	}

	return 0;
}