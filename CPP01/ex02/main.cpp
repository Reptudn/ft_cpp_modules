#include <string>
#include <iostream>

// Pointer: a variable that stores the memory address of another variable
//      -> can change value by dereferencing
// Reference: a variable that is an alias for another variable (same mem but different name)
//      -> can change value of the original variable without dereference

// TODO: check if this is correct
int main()
{
	std::string variable = "HI THIS IS BRAIN";
	std::string* ptr = &variable;
	std::string& ref = variable;

	std::cout << "variable addr:\t" << &variable << std::endl;
	std::cout << "ptr:\t\t" << ptr << std::endl;
	std::cout << "ref:\t\t" << &ref << std::endl;

	// ref = "HI THIS IS REF";

	std::cout << "variable value:\t" << variable << std::endl;
	std::cout << "ptr value:\t" << *ptr << std::endl;
	std::cout << "ref value:\t" << ref << std::endl;

	return 0;
}