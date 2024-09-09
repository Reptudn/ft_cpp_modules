#pragma once

#include <iostream>

template <typename T>
void increment(T &element)
{
	element++;
}

template <typename T>
void decrement(T &element)
{
	element--;
}

template <typename T>
void print(T &element)
{
	std::cout << element << std::endl;
}

template <typename T>
void iter(T *arr, unsigned int len, void (* function)(T &element))
{
	for (unsigned int i = 0; i < len; i++)
		function(arr[i]);
}