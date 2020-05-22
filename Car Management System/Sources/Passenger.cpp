#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "Passenger.h"
#include "Heading.h"
#include "Option.h"


Passenger::Passenger(std::string name, int age, int id)
	: Person(name, age), m_id(id) {}
Passenger::Passenger() {}
Passenger::~Passenger() {}

bool Passenger::singleDriveLoop()
{
	Heading heading;
	Option opt;
	int loc = opt.selectOption(1, 10, *this, &Passenger::displayLocationList, "Pickup Location:");
	int dest = opt.selectOption(1, 10, *this, &Passenger::displayLocationList, "Destination:");
	if (loc == dest)
	{
		std::cerr << "Pickup and Destination can not be Same.\n";
		pause("Please re-Enter Locations . . . ");
		return true;
	}
		
	m_detail.generateRandomCars();
	int car = opt.selectOption(1, m_detail.getTotalCars(), *this, &Passenger::displayCarList, "Cars Available:");

	m_detail.setLocation(loc, dest);
	m_detail.setTime(car);
	m_detail.setFare();
		
	bool replayThisMenu = true;
	while (replayThisMenu)
	{
		int selectCase = opt.selectOption(0, 3, "Menu: \n_____ \n"
											"1. Book Ride.\n" 
											"2. Change Location.\n" 
											"3. Show Ride Details.\n\n"
											"0. Back to Main Menu.\n");
		switch (selectCase)
		{
		case 0:
			return false;
			break;
		case 1:
			bookRide(m_detail.getArrivalTime(), "Your Car will arrive in ");
			replayThisMenu = false;
			break;
		case 2:
			return true;
			break;
		case 3:
			replayThisMenu = true;
			heading.displayHeading("UMF Car Tranport System");
			m_detail.displayBeforeRide(car);
			std::cout << "\n";
			pause("Press any key to go Back to Menu . . . ");
			break;
		default:
			std::cerr << "\nPassneger::SingleDriveLoop - Invalid SelectionCase Entered.\n";
		}
	}

	heading.displayHeading("UMF Car Tranport System");
	m_detail.displayDuringRide();
	pause("Press any key to Start the Ride . . . ");

	bookRide(m_detail.getEstimatedTime(), "You will reach your Destination in ");
	
	heading.displayHeading("UMF Car Tranport System");
	m_detail.displayAfterRide();
	pause("Your Ride has Ended . . . ");

	return false;
}
void Passenger::displayUserData()
{
	std::cout << "User Details: \n";
	std::cout << "_____________ \n";

	Person::displayUserData();
	std::cout << "ID: " << m_id << std::endl;
}

void Passenger::bookRide(int tempTime, std::string str = "-")
{
	while (tempTime > 0)
	{
		Heading heading;
		heading.displayHeading("UMF Car Tranport System");

		std::cout << str << tempTime << " min";
		for (int i = 0; i < 3 - (tempTime % 3); ++i)
			std::cout << ".";
		std::cout << "\n";
		Sleep(500);
		system("cls");
		tempTime--;
	}
}
void Passenger::pause(std::string str = "Press any key to Continue . . . ")
{
	std::cout << str;
	_getch();
	system("cls");
}

void Passenger::displayLocationList()
{
	std::ifstream inf;
	inf.open("Checkpoints.txt");

	while (!inf.eof())
	{
		int index = 0;
		inf >> index;

		std::string pointName;
		getline(inf, pointName);

		std::cout << index << ".\t" << pointName << std::endl;
	}
}
void Passenger::displayCarList() { m_detail.displayCarList(); }