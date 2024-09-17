#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <polish notation>" << std::endl;
		return 1;
	}
	
	try
	{
		RPN rpn(argv[1]);
		rpn.calculate();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}