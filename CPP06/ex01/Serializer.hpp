#pragma once

#include <iostream>

struct Data;

class Serializer
{
	private:
		Serializer();
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

typedef struct Data
{
	std::string one_string;
	int			one_int;
	std::string two_string;
	double		one_double;
} Data;