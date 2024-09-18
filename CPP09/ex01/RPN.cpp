#include "RPN.hpp"
#include <algorithm>
#include <exception>
#include <iostream>
#include <string>

RPN::RPN(std::string polish)
{
	for (char c : polish)
	{
		if (std::isspace(c) || std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
			continue;
		throw std::runtime_error("Error: Invalid character in polish notation");
	}

	while (polish.find(' ') != std::string::npos)
	{
		stack.push_back(polish.substr(0, polish.find(' ')));
		polish = polish.substr(polish.find(' ') + 1);
	}
	stack.push_back(polish);

	auto it = stack.begin();
	int numbers = 0;
	int operators = 0;
	while (it != stack.end())
	{
		std::string line = *it;
		try
		{
			std::stoi(line);
			numbers++;
		}
		catch (std::exception &e) {
			(void)e;
			operators++;
		}
		it++;
	}

	std::cout << "numbers: " << numbers << std::endl;
	std::cout << "operators: " << operators << std::endl;
 
	if (numbers != operators + 1)
		throw std::runtime_error("Error: Operators and numbers don't match");

}

RPN::~RPN()
{
}

std::vector<std::string>::const_iterator RPN::getFirstOperator() const
{
	auto it = stack.begin();
	while (it != stack.end())
	{
		std::string line = *it;
		if (line == "+" || line == "-" || line == "*" || line == "/" || line == "%")
			return it;
		it++;
	}
	return stack.end();
}

void RPN::calculate()
{
	int result = 0;

	while (stack.size() > 1)
	{
		auto op = getFirstOperator();
		if (op == stack.end())
			break;
		int a = std::stoi(*(op - 2));
		int b = std::stoi(*(op - 1));

		if (*op == "+") result = a + b;
		else if (*op == "-") result = a - b;
		else if (*op == "*") result = a * b;
		else if (*op == "/") result = a / b;
		else if (*op == "%") result = a % b;
		else 
		{
			std::cout << "non op found" << std::endl;
		}
		std::cout << a << " " + *op + " " << b <<" = " << result << std::endl;
		stack.erase(op -2, op + 1);
		stack.insert(op - 2, std::to_string(result));
	}

	std::cout << "Result => " << result << std::endl;
}
