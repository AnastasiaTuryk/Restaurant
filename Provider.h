#ifndef PROVIDER_H
#define PROVIDER_H
#include"Person.h"
#include<string>
#include<iostream>
using namespace std;

class Provider :public Person
{
protected:
	string country;

public:
	int rate;
	Provider(string = "", int = 0, string = "");
	void Write() override;
	int getrating();
	string getcountry();
};
#endif
