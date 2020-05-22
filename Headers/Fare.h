#ifndef FARE_H
#define FARE_H

class Fare
{
public:
	Fare();
	~Fare();

	int getFixed() const;
	double getFactor() const;
	int getEstimated() const;

	void setFixed(double distance);
	void setRandomFactor();
	void setEstimated();

	friend std::ostream& operator << (std::ostream& out, const Fare &obj);

private:
	const int k_ratePerKilometer = 25;
	int m_fixed;
	double m_factor;
	int m_estimated;
};

#endif // FARE_H
