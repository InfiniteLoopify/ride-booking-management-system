#include <iostream>
#include "Detail.h"

Detail::Detail() {}
Detail::~Detail() {}

void Detail::setFare()
{
	m_fare.setFixed(m_location.getDistance());
	m_fare.setRandomFactor();
	m_fare.setEstimated();
}
void Detail::displayFare() { std::cout << m_fare; }

void Detail::setTime(int carId)
{
	m_time.setCarArivalTime(m_car.getTime(carId - 1));
	m_time.setFixed(m_location.getTime());
	m_time.setRandomFactor();
	m_time.setEstimated();
}
void Detail::displayTime() { std::cout << m_time; }
int Detail::getArrivalTime() { return m_time.getCarArivalTime(); }
int Detail::getEstimatedTime() { return m_time.getEstimated(); }

void Detail::setLocation(int start, int end) { m_location.setData(start - 1, end - 1); }
void Detail::displayLocation(int start, int end) const
{
	std::cout << "Location Details: " << std::endl;
	std::cout << "_________________ " << std::endl;

	std::cout << "Current Location: " << m_location.getCurrentLoc() << std::endl;
	std::cout << "Destination: " << m_location.getNextLoc() << std::endl;
	std::cout << "Distance: " << m_location.getDistance() << std::endl;
	std::cout << "Time: " << m_location.getTime() << std::endl;
}

void Detail::generateRandomCars() { m_car.availableCarGenerator(); }
int Detail::getTotalCars() const { return m_car.getRandomCarCount(); }
void Detail::displayCar(int id) const
{
	std::cout << "Car Details: " << std::endl;
	std::cout << "____________ " << std::endl;

	std::cout << "Car Name: " << m_car.getCarName(id - 1) << std::endl;
	std::cout << "Car Arival Time: " << m_car.getTime(id - 1) << std::endl;
} 
void Detail::displayCarList() const { m_car.showAvailableCars(); }

void Detail::displayBeforeRide(int carId)
{
	std::cout << "Ride Details: \n";
	std::cout << "_____________ \n";

	std::cout << "From " << m_location.getCurrentLoc();
	std::cout << " To " << m_location.getNextLoc() << " (" << m_location.getDistance() << " km away)" << std::endl;

	std::cout << m_car.getCarName(carId - 1) << " will arrive in " << m_time.getCarArivalTime() << " min\n";

}
void Detail::displayDuringRide()
{
	std::cout << "Your Ride has arrived!\n\n";
	std::cout << "Ride Details: \n";
	std::cout << "_____________ \n";

	std::cout << "Fare (Fixed): " << m_fare.getFixed() << " Rs\n";
	std::cout << "Peak Factor: " << m_fare.getFactor() << "\n";
	std::cout << "Time (Estimated): " << m_time.getFixed() << " min\n\n";
}
void Detail::displayAfterRide()
{
	std::cout << "Ride Details: \n";
	std::cout << "_____________ \n";

	std::cout << "You have reached " << m_location.getNextLoc() << "\n\n";
	std::cout << "Peak Factor:\t\t" << m_fare.getFactor() << " Rs\n";
	std::cout << "Fare (Estimated):\t" << m_fare.getFixed() << " Rs\n";
	std::cout << "Fare (Calculated): \t" << m_fare.getEstimated() << " Rs\n\n";
	std::cout << "Time (Estimated):\t" << m_time.getFixed() << " min\n";
	std::cout << "Time (Calculated): \t" << m_time.getEstimated() << " min\n\n";

	std::cout << "Please pay " << m_fare.getEstimated() << " Rs.\n\n";
}
