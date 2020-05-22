#include <iostream>
#include <fstream>
#include <time.h>
#include "Car.h"

int Car::s_totalRecords = 0;

Car::Car() {}
Car::~Car() {}

void Car::readRecord(int carId)
{
	std::ifstream inf;
	inf.open("CarList.txt", std::ios::in);

	while (!inf.eof())
	{
		int currentId{};
		inf >> currentId;

		if (currentId == carId)
		{
			std::string tempCarName;
			getline(inf, tempCarName);
			m_carList.push_back(tempCarName);

			return;
		}
		else
		{
			std::string discardLine;
			getline(inf, discardLine);
		}
	}
	
	throw carId;
}
void Car::enterRecord(std::string carName)
{
	std::ofstream outf;
	outf.open("CarList.txt", std::ios::app | std::ios::out);

	outf << s_totalRecords << "";
	outf << carName << std::endl;

	++s_totalRecords;
}

void Car::showAvailableCars() const
{
	int i = 0;
	for (const auto &element : m_carList)
	{
		std::cout << i + 1 << ". ";
		std::cout << element << " (" << m_time[i] << " min)\n";
		++i;
	}
}
void Car::availableCarGenerator()
{
	std::ifstream inf("CarCount.txt");
	inf >> s_totalRecords;
	inf.close();

	srand(static_cast <unsigned int> (time(0)));
	const int k_maxCarCount = 10;
	m_randomCarCount = rand() % k_maxCarCount + 1;

	for (int i = 0; i < m_randomCarCount; ++i)
	{
		int randomCarSelect = rand() % s_totalRecords;
		
		try
		{
			readRecord(randomCarSelect);
		}
		catch (int id)
		{
			std::cerr << "\nCar::readRecord-> Incorrect Car Id: " << id << std::endl;
		}

		const int k_maxCarTime = 15;
		m_time.push_back(rand() % k_maxCarTime + 1);
	}
}
void Car::removeAllRecords()
{
	s_totalRecords = 0;
	remove("CarList.txt");
	m_randomCarCount = 0;
	m_carList.clear();
	m_time.clear();
}

std::string Car::getCarName(int id) const { return m_carList[id]; }
int Car::getTime(int id) const { return m_time[id]; }
int Car::getTotalRecords() const { return s_totalRecords; }
int Car::getRandomCarCount() const { return m_randomCarCount; }

std::ostream& operator << (std::ostream& out, const Car &obj)
{
	std::cout << "\n_________________________________________Car Class\n";

	std::cout << "Total Car Records: " << Car::s_totalRecords << std::endl;
	std::cout << "Cars Available: " << obj.m_randomCarCount << std::endl;

	std::cout << "Car Names: ";
	for (const auto &element : obj.m_carList)
	{
		std::cout << element << " ";
	}

	std::cout << "\nCar Times: ";
	for (const auto &element : obj.m_time)
	{
		std::cout << element << " ";
	}

	return out;
}