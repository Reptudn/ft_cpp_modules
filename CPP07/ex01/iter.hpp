#pragma once

template <typename T>
void magic(T &t)
{
	t += 5;
}

template <typename T>
void iter(T *arr, unsigned int len, void (* function)(T *element))
{
	for (int i = 0; i < len; i++)
		func(arr[i]);
}