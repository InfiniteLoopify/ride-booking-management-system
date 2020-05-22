#include <iostream>
#include "Passenger.h"
#include "Heading.h"
#include "Option.h"

int main()
{
	system("COLOR f0");
	system("UMF Car System");

	Option opt;
	
	std::string name;
	int age;
	int id;

	int runProgram = true;
	while (runProgram)
	{
		opt.selectOption(name, "Enter Your Name: ");
		opt.selectOption(age, "Enter Your Age: ");
		opt.selectOption(id, "Enter Your User ID: ");
		
		int driveYes = true;
		while (driveYes)
		{
			Heading heading;
			heading.displayHeading("UMF Car Tranport System");

			Passenger passenger(name, age, id);
			passenger.displayUserData();
			opt.pause();

			driveYes = passenger.singleDriveLoop();
		}
		runProgram = opt.selectOption(0, 1, "Do you want to Book another Ride?\n1. Yes\n0. No");
	}
}
