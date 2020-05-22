#include <iostream>
#include "Option.h"
#include "Heading.h"

Option::Option(){}
Option::~Option(){}

void Option::pause()
{
	system("Pause");
	system("cls");
}

int Option::selectOption(int start, int end, Passenger &pass, void(Passenger::*functionToCall)(void), std::string str = "-")
{
	int select;
	while (true)
	{
		Heading heading;
		heading.displayHeading("UMF Car Tranport System");

		std::cout << str << std::endl;
		for (int i = 0; i < static_cast<int> (str.length()); ++i)
			std::cout << "_";

		std::cout << "\n";
		(pass.*functionToCall)();
		std::cin >> select;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cerr << "\nInvalid Data Entered.";
			std::cout << '\a' << "\n";
			pause();
		}
		else
		{
			std::cin.ignore(32767, '\n');

			if (select >= start && select <= end)
			{
				std::cout << "\n";
				pause();
				return select;
			}
			else
			{
				std::cerr << "\nInvalid Index.\n";
				pause();
			}
		}
	}
}
int Option::selectOption(int start, int end, std::string str = "-")
{
	int select;
	while (true)
	{
		Heading heading;
		heading.displayHeading("UMF Car Tranport System");

		std::cout << str << std::endl;
		std::cin >> select;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cerr << "\nInvalid Data Entered.";
			std::cout << '\a' << "\n";
			pause();
		}
		else
		{
			std::cin.ignore(32767, '\n');

			if (select >= start && select <= end)
			{
				std::cout << "\n";
				pause();
				return select;
			}
			else
			{
				std::cerr << "\nInvalid Index.\n";
				pause();
			}
		}
	}
}
int Option::selectOption(int &num, std::string str = "-")
{
	while (true)
	{
		Heading heading;
		heading.displayHeading("UMF Car Tranport System");

		std::cout << str << std::endl;
		std::cin >> num;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cerr << "\nInvalid Data Entered.";
			std::cout << '\a' << "\n";
			pause();
		}
		else
		{
			std::cin.ignore(32767, '\n');

			if (num > 0)
			{
				std::cout << "\n";
				pause();
				return num;
			}
			else
			{
				std::cerr << "\nInvalid Value Entered.\n";
				pause();
			}
		}
	}
}
int Option::selectOption(std::string &name, std::string str = "-")
{
	Heading heading;
	heading.displayHeading("UMF Car Tranport System");

	std::cout << str << std::endl;
	std::getline(std::cin, name);
	pause();
	return true;
}