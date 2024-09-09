#pragma once

#include <iostream>

template <typename T>
T &easyfind(T &container, int value)
{
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == value)
			return *it;
	}
	throw std::exception();
}