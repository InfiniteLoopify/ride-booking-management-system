#include <iostream>
#include <time.h>
#include "Timer.h"

Time::Time() {}
Time::~Time() {}

int Time::getCarArivalTime() const { return m_carArivalTime; }
int Time::getFixed() const { return m_fixed; }
int Time::getFactor() const { return m_factor; }
int Time::getEstimated() const { return m_estimated; }

void Time::setCarArivalTime(int time) { m_carArivalTime = time; }
void Time::setFixed(int time) { m_fixed = time; }
void Time::setEstimated() { m_estimated = m_fixed + m_factor; }
void Time::setRandomFactor()
{
	srand(static_cast <unsigned int> (time(0)));
	const double randomCreatorFloat = 0.4;
	int randomBetween = static_cast <int> (m_fixed * randomCreatorFloat);

	if (!randomBetween)
		randomBetween = 1;

	m_factor = rand() % randomBetween;
}

std::ostream& operator << (std::ostream& out, const Time &obj)
{
	std::cout << "Time Details: " << std::endl;
	std::cout << "_____________ " << std::endl;

	std::cout << "Estimated: " << obj.m_fixed << std::endl;
	std::cout << "Taffic Delay: " << obj.m_factor << std::endl;
	std::cout << "Time Taken: " << obj.m_estimated << std::endl;
	return out;
}
