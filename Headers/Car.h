#ifndef CAR_H
#define CAR_H

#include <string>
#include <vector>

class Car
{
public:
	Car();
	~Car();

	void enterRecord(std::string carName);
	void removeAllRecords();

	void availableCarGenerator();
	void showAvailableCars() const;

	int getTime(int id) const;
	std::string getCarName(int id) const;
	int getTotalRecords() const;
	int getRandomCarCount() const;

	friend std::ostream& operator << (std::ostream& out, const Car &obj);

private:
	void readRecord(int carId);

private:
	static int s_totalRecords;
	int m_randomCarCount;
	std::vector <int> m_time;
	std::vector <std::string> m_carList;
};

#endif // CAR_H
