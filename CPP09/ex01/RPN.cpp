#include "RPN.hpp"
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
		input.push(polish.substr(0, polish.find(' ')));
		polish = polish.substr(polish.find(' ') + 1);
	}
	input.push(polish);

	int numbers = 0;
	int operators = 0;
	while (input.size())
	{
		std::string line = input.top();
		input.pop();
		stack.push(line);
		try
		{
			std::stoi(line);
			numbers++;
		}
		catch (std::exception &e) {
			(void)e;
			operators++;
		}
	}
 
	if (numbers != operators + 1)
		throw std::runtime_error("Error: Operators and numbers don't match");

}

RPN::~RPN()
{
}

void RPN::calculate()
{

	std::stack<int> nums;

	while (stack.size() > 1)
	{

		try
		{
			int result = 0;
			while (true)
			{
				try
				{
					int num = std::stoi(stack.top());
					stack.pop();
					nums.push(num);
				}
				catch (std::exception &e)
				{
					(void)e;
					break;
				}
			}
			int b = nums.top(); nums.pop();
			int a = nums.top(); nums.pop();
			std::string op = stack.top(); stack.pop();

			std::cout << a << " " << op << " " << b << " = ";

			if (op == "+") result = a + b;
			else if (op == "-") result = a - b;
			else if (op == "*") result = a * b;
			else if (op == "/") result = a / b;
			else if (op == "%") result = a % b;
			else
				throw std::runtime_error("Invalid character in polish notation");
			stack.push(std::to_string(result));

			std::cout << result << std::endl;

		}
		catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return;
		}
	}

	std::cout << "Result => " << stack.top() << std::endl;
}
