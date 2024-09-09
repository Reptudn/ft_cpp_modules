#include "Serializer.hpp"

Serializer::Serializer() { }
Serializer::~Serializer() { }

// reinterpret_cast casts the pointer without checkign if it makes "sense"

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}