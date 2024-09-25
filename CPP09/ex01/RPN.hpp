#include <stack>
#include <iostream>
#include <stack>


class RPN
{
	private:
		std::stack<std::string> input;
		std::stack<std::string> stack;

	public:
		RPN(std::string polish);
		RPN(const RPN &rpn);
		RPN &operator=(const RPN &rpn);
		~RPN();
		void calculate();
};