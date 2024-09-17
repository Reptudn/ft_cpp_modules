#include <vector>
#include <iostream>


class RPN
{
	private:
		std::vector<std::string> stack;

		std::vector<std::string>::const_iterator getFirstOperator() const;
	public:
		RPN(std::string polish);
		~RPN();
		void calculate();
};