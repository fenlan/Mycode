# include <iostream>
# include "Customer.h"
using namespace std;

Customer::Customer(string name, int age)
{
	m_strName = name;
	m_iAge = age;
}

void Customer::printInfo() const
{
	cout << "ÐÕÃû" << m_strName << endl;
	cout << "ÄêÁä" << m_iAge << endl;
}