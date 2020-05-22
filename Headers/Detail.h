#ifndef DETAIL_H
#define DETAIL_H

#include "Timer.h"
#include "Fare.h"
#include "Location.h"
#include "Car.h"

class Detail
{
public:
	Detail();
	~Detail();

	void setFare();
	void displayFare();

	void setTime(int id);
	void displayTime();
	int getArrivalTime();
	int getEstimatedTime();

	void setLocation(int start, int end);
	void displayLocation(int start, int end) const;

	void generateRandomCars();
	int getTotalCars() const;
	void displayCar(int id) const;
	void displayCarList() const;

	void displayBeforeRide(int carId); 
	void displayDuringRide();
	void displayAfterRide();

private:
	Time m_time;
	Fare m_fare;
	Location m_location;
	Car m_car;
};

#endif // DETAIL_H
