#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.one_string = "Hello";
	data.one_int = 42;
	data.two_string = "World";
	data.one_double = 3.14;

	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "one_string: " << ptr->one_string << std::endl;
	std::cout << "one_int: " << ptr->one_int << std::endl;
	std::cout << "two_string: " << ptr->two_string << std::endl;
	std::cout << "one_double: " << ptr->one_double << std::endl;

	return 0;
}