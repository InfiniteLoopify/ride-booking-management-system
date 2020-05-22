#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

class Map
{
public:
	Map();
	~Map();

	void readFile(int code);
	void writeFile(int id, const std::string &name, const std::initializer_list<double> &dis, const std::initializer_list<int> &tim);
	void deleteFile();

	void setTotalLocs(int loc);
	int getTotalLocs();

	std::string getName(int id) const;
	double getDistance(int id) const;
	int getTime(int id) const;

	friend std::ostream& operator << (std::ostream& out, const Map &obj);

private:
	int m_totalLocations;
	int m_id;
	std::string m_name;
	std::vector<double> m_distance;
	std::vector<int> m_time;
};

#endif // MAP_H