#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
	int i = rand() % 3;
	if (i == 0)
	{
		std::cout << "Class A generated" << std::endl;
		return new A;
	}
	else if (i == 1)
	{
		std::cout << "Class B generated" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "Class C generated" << std::endl;
		return new C;
	}
}

void identify(Base *p)
{
	// dynamic cast tries to convert the pointer at runtime to the given pointer and if that doesnt work it returns a nullptr
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "None of the classes" << std::endl;
}

void identify(Base &b)
{
	Base base;
	try
	{
		base = dynamic_cast<A &>(b);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e) { }

	try
	{
		base = dynamic_cast<B &>(b);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e) { }

	try
	{
		base = dynamic_cast<C &>(b);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e) { }

}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		Base *random = generate();
		if (!random) continue;

		std::cout << "Identifying by pointer" << std::endl;
		identify(random);

		std::cout << "identifying by reference" << std::endl;
		identify(*random);

		delete random;
		std::cout << "---------------" << std::endl;
	}
}