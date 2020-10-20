#ifndef CLIENT_H
#define CLIENT_H

#include"Person.h"
#include<string>
#include<iostream>
using namespace std;
class Client:public Person
{
protected:
	int phone;
	int discount;
	string surname;
public:
	
	Client(string name="",string surname="",int discount=0);

	
	void Write() override;
	
	string getname();
	string getsurname();
	void setdiscount(int);
	int getdiscount();

};
#endif // !CLIENT_H
