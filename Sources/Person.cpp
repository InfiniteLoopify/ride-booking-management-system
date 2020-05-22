#include "Person.h"
#include <string>
#include <iostream>

Person::Person(std::string name, int age)
	:m_name(name), m_age(age){}
Person::Person(){}
Person::~Person(){}

void Person::displayUserData()
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Age: " << m_age << std::endl;
}
