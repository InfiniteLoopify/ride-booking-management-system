#ifndef LOCATION_H
#define LOCATION_H

#include <string>

class Location
{
public:
	Location();
	~Location();

	void setData(int locStart, int locEnd);
	
	std::string getCurrentLoc() const;
	std::string getNextLoc() const;
	double getDistance() const;
	int getTime() const;

	friend std::ostream& operator << (std::ostream& out, const Location &obj);

private:
	std::string m_current;
	std::string m_destinaton;
	double m_distance;
	int m_time;
};

#endif // LOCATION_H
