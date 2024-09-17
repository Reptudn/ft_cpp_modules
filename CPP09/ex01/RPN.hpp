#include <stack>
#include <iostream>


class RPN
{
	private:
		std::stack<std::string> _operator;
		std::stack<int> _stack;
	public:
		RPN(std::string polish);
		~RPN();
		void calculate();
};