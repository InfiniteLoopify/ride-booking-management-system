#include <iostream>
#include <time.h>
#include "Fare.h"

Fare::Fare() {}
Fare::~Fare() {}

int Fare::getFixed() const { return m_fixed; }
double Fare::getFactor() const { return m_factor; }
int Fare::getEstimated() const { return m_estimated; }

void Fare::setFixed(double distance) { m_fixed = static_cast<int>(distance * k_ratePerKilometer); }
void Fare::setRandomFactor()
{
	std::srand(static_cast<unsigned int>(time(0)));
	int tempIntFactor = rand() % 11;
	m_factor = static_cast<double>(tempIntFactor / 10.0);
	m_factor += 1;
}
void Fare::setEstimated() { m_estimated = static_cast<int> (m_fixed * m_factor); }

std::ostream& operator << (std::ostream& out, const Fare &obj)
{
	std::cout << "Fare Details: " << std::endl;
	std::cout << "_____________ " << std::endl;

	std::cout << "Fixed: " << obj.m_fixed << std::endl;
	std::cout << "Peak Factor: " << obj.m_factor << std::endl;
	std::cout << "Estimated: " << obj.m_estimated << std::endl;
	return out;
}
