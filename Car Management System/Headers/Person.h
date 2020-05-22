#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
public:
	Person(std::string name, int age);
	Person();
	~Person();
	virtual void displayUserData();

private:
	std::string m_name;
	int m_age;
};

#endif // PERSON_H