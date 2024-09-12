#include "Span.hpp"
#include <iostream>

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try {
		sp.addNumber(42);
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "Shortest:\t" << sp.shortestSpan() << std::endl;
	std::cout << "Longest:\t" << sp.longestSpan() << std::endl << std::endl;

	Span longSpan = Span(10);
	longSpan.addRange(-10, -3);
	try { longSpan.addMultiple(6, 42, 1, 5, 123); } catch (std::exception &e) { std::cout << e.what() << std::endl; }
	
	std::cout << "Shortest:\t" << longSpan.shortestSpan() << std::endl;
	std::cout << "Longest:\t" << longSpan.longestSpan() << std::endl << std::endl;

	Span lol = Span(3);

	lol.addNumber(2);
	// lol.addNumber(7);

	try {
		std::cout << "Shortest:\t" << lol.shortestSpan() << std::endl;
		std::cout << "Longest:\t" << lol.longestSpan() << std::endl << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}