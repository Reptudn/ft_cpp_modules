#include "RPN.hpp"

RPN::RPN(std::string polish)
{
	std::stack<std::string> parts;

	for (char c : polish)
	{
		if (std::isspace(c) || std::isdigit(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
			continue;
		throw std::runtime_error("Error: Invalid character in polish notation");
	}

	while (polish.find(' ') != std::string::npos)
	{
		parts.push(polish.substr(0, polish.find(' ')));
		polish = polish.substr(polish.find(' ') + 1);
	}
	parts.push(polish);

	while (parts.size() > 0)
	{
		std::string str = parts.top();
		parts.pop();
		if (str == "+" || str == "-" || str == "*" || str == "/" || str == "%")
			_operator.push(str);
		else
			_stack.push(std::stoi(str));
	}

	if (_stack.size() != _operator.size() + 1)
		throw std::runtime_error("Error: Operators and numbers don't match");

}

RPN::~RPN()
{
}

void RPN::calculate()
{
	int number;
	while (_operator.size() > 0)
	{
		std::string op = _operator.top();
		_operator.pop();

		int a = _stack.top();
		_stack.pop();
		int b = _stack.top();
		_stack.pop();

		if (op == "+")
			number = a + b;
		else if (op == "-")
			number = a - b;
		else if (op == "*")
			number = a * b;
		else if (op == "/")
			number = a / b;
		else if (op == "%")
			number = a % b;
		_stack.push(number);
	}
	std::cout << _stack.top() << std::endl;
}
