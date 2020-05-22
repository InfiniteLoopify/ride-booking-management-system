#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include "Person.h"
#include "Detail.h"

class Passenger : public Person
{
public:
	Passenger();
	Passenger(std::string name, int age, int id);
	~Passenger();

	bool singleDriveLoop();
	void displayUserData();

private:
	void bookRide(int tempTime, std::string str);
	void pause(std::string str);
	
	void displayCarList();
	void displayLocationList();

private:
	int m_id;
	Detail m_detail;
};

#endif // PASSENGER_H