#include <iostream>
#include <fstream>
#include "Map.h"

Map::Map() : m_id(0), m_totalLocations(getTotalLocs())
{
	m_distance.resize(m_totalLocations);
	m_time.resize(m_totalLocations);
}
Map::~Map() {}

void Map::readFile(int code)
{
	std::ifstream inf;
	inf.open("MapList.txt", std::ios::in);

	bool loopBreak{ false };
	while (!inf.eof())
	{
		inf >> m_id;
		if (m_id == code)
		{
			getline(inf, m_name);
			for (int i = 0; i < m_totalLocations; ++i)
			{
				inf >> m_distance[i];
			}
			for (int i = 0; i < m_totalLocations; ++i)
			{
				inf >> m_time[i];
			}
			m_distance.resize(m_totalLocations);
			m_time.resize(m_totalLocations);

			loopBreak = true;
			break;
		}
		else
		{
			std::string discardLine;
			const int timesDiscarded = 3;
			for (int i = 0; i < timesDiscarded; ++i)
				getline(inf, discardLine);
		}
	}

	try
	{
		if (!loopBreak)
		{
			throw code;
		}
	}
	catch (int code)
	{
		std::cerr << "\nMap::readFile-> Invalid Map Id: " << code << std::endl;
	}
}
void Map::writeFile(int id, const std::string &name, const std::initializer_list<double> &dis, const std::initializer_list<int> &tim)
{
	m_id = id;
	m_name = name;

	m_distance.clear();
	m_time.clear();

	for (auto &element : dis)
	{
		m_distance.push_back(element);
	}
	for (auto &element : tim)
	{
		m_time.push_back(element);
	}

	std::ofstream outf;
	outf.open("MapList.txt", std::ios::app | std::ios::out);

	outf << m_id << "";
	outf << m_name << " " << std::endl;

	for (int i = 0; i < m_totalLocations; ++i)
	{
		outf << m_distance[i] << " ";
	}
	outf << std::endl;
	for (int i = 0; i < m_totalLocations; ++i)
	{
		outf << m_time[i] << " ";
	}
	outf << std::endl;

	outf.close();
}
void Map::deleteFile()
{
	remove("MapList.txt");

	std::ofstream outf("MapCount.txt", std::ios::out);
	outf << 0;

	m_totalLocations = 0;
	m_id = 0;
	m_distance.clear();
	m_time.clear();
	m_name = "-";
}

void Map::setTotalLocs(int loc)
{
	std::ofstream outf("MapCount.txt");
	m_totalLocations = loc;
	outf << m_totalLocations;
}
int Map::getTotalLocs()
{
	std::ifstream inf("MapCount.txt");
	inf >> m_totalLocations;
	return m_totalLocations;
}

std::string Map::getName(int id) const
{
	if (m_id == id)
		return m_name;

	else if (id < m_totalLocations && id >= 0)
	{
		std::ifstream inf;
		inf.open("MapList.txt", std::ios::in);

		while (!inf.eof())
		{
			int newId;
			inf >> newId;
			if (id == newId)
			{
				std::string desName;
				getline(inf, desName);
				return desName;
			}
			else
			{
				std::string discardLine;
				const int timesDiscarded = 3;
				for (int i = 0; i < timesDiscarded; ++i)
					getline(inf, discardLine);
			}
		}
	}

	try
	{
		throw id;
	}
	catch (int id)
	{
		std::cerr << "Map::getName-> No Name found for Id: " << id << std::endl;
		return "-";
	}
}
double Map::getDistance(int id) const
{
	if (id < m_totalLocations && id >= 0)
		return m_distance[id];
	
	try
	{
		throw id;
	}
	catch (int id)
	{
		std::cerr << "Map::getDistance-> Invalid 'Map.txt' Id: " << id << std::endl;
		return -34404;
	}
}
int Map::getTime(int id) const
{
	if (id < m_totalLocations && id >= 0)
		return m_time[id];
	try
	{
		throw id;
	}
	catch (int id)
	{
		std::cerr << "Map::getTime-> Invalid 'Map.txt' Id: " << id << std::endl;
		return -34404;
	}
}

std::ostream& operator << (std::ostream& out, const Map &obj)
{
	std::cout << "\n_________________________________________Map Class\n";
	std::cout << "Location ID: " << obj.m_id << std::endl;
	std::cout << "Location Name: " << obj.m_name << std::endl;

	std::cout << "Distance List: ";
	for (const auto &value : obj.m_distance)
	{
		std::cout << value << " ";
	}
	std::cout << "\nTime List: ";
	for (const auto &value : obj.m_time)
	{
		std::cout << value << " ";
	}

	return out;
}
