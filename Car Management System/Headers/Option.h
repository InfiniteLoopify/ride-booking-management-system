#ifndef OPTION_H
#define OPTION_H

#include <string>
#include "Passenger.h"

class Option
{
public:
	Option();
	~Option();

	void pause();
	int selectOption(int start, int end, Passenger &pass, void(Passenger::*functionToCall)(void), std::string str);
	int selectOption(int start, int end, std::string str);
	int selectOption(int &num, std::string str);
	int selectOption(std::string &name, std::string str);
};

#endif // OPTION_H
