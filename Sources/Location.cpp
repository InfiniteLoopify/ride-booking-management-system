#include <string>
#include <iostream>
#include "Location.h"
#include "Map.h"

Location::Location() {}
Location::~Location() {}

void Location::setData(int locStart, int locEnd)
{
	Map map;
	map.readFile(locStart);

	m_current = map.getName(locStart);
	m_destinaton = map.getName(locEnd);
	m_distance = map.getDistance(locEnd);
	m_time = map.getTime(locEnd);
}

std::string Location::getCurrentLoc() const { return m_current; };
std::string Location::getNextLoc() const { return m_destinaton; };
double Location::getDistance() const { return m_distance; };
int Location::getTime() const { return m_time; }

std::ostream& operator << (std::ostream& out, const Location &obj)
{
	std::cout << "\n_________________________________________Location Class\n";
	std::cout << "Current Location: " << obj.m_current << std::endl;
	std::cout << "Destination: " << obj.m_destinaton << std::endl;
	std::cout << "Distance: " << obj.m_distance << std::endl;
	std::cout << "Time: " << obj.m_time;
	return out;
}
