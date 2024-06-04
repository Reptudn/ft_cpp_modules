#include <string>
#include <iostream>

int main()
{
	std::string variable = "HI THIS IS BRAIN";
	std::string* strptr = &variable;
	std::string& strref = variable;

	std::cout << "variable addr: " << &variable << std::endl;
	std::cout << "strptr: " << *strptr << std::endl;
	std::cout << "strref: " << strref << std::endl;

	std::cout << "variable value: " << variable << std::endl;
	std::cout << "strptr value: " << *strptr << std::endl;
	std::cout << "strref value: " << strref << std::endl;

	return 0;
}