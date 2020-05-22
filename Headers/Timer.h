#ifndef TIME_H
#define TIME_H

class Time
{
public:
	Time();
	~Time();

	int getCarArivalTime() const;
	int getFixed() const;
	int getFactor() const;
	int getEstimated() const;

	void setCarArivalTime(int time);
	void setFixed(int time);
	void setRandomFactor();
	void setEstimated();

	friend std::ostream& operator << (std::ostream& out, const Time &obj);

private:
	int m_carArivalTime;
	int m_fixed;
	int m_factor;
	int m_estimated;
};

#endif // TIME_H
