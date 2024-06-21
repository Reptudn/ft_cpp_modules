#include <iostream>
#include <string>

#ifndef HARL_H
#define HARL_H

class Harl
{
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		void complain(std::string level);
		Harl();
		~Harl();
};

typedef void (Harl::*HarlFuncPtr)(void);

#endif