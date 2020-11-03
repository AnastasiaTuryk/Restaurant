#include<iostream>
#include<fstream>
using namespace std;
#include"Repository.h"
#include"ProviderRepository.h"

ProviderRepository::ProviderRepository(bool sync) : Repository(sync)
{
	ReadFromStorage();
}

bool ProviderRepository::Add(Provider& provider)
{
	return Repository::Add(&provider);
}

void ProviderRepository::ReadFromStorage()
{
	
	ifstream fin("C:\\Users\\User\\Desktop\\с++ 2 курс\\repository,restaurant\\Provider.txt");
	string name;
	int rate;
	string country;
	if (!fin.is_open())
	{
		cout << "your file is not open!" << endl;
	}
	while (fin)
	{
		if (fin >> name >> rate >> country)
		{
			Provider* pr = new Provider(name, rate, country);
			Add(*pr);
		}
	}
	fin.close();
}

void ProviderRepository::WriteToStorage()
{
	ofstream fout("C:\\Users\\User\Desktop\\с++ 2 курс\\repository,restaurant\\Provider.txt", ios::out);
	for (int i = 0;i < vEntity.size();i++)
	{
		fout << ((Provider*)vEntity[i])->getname() << " "
			<< ((Provider*)vEntity[i])->getrating() <<
			" " << ((Provider*)vEntity[i])->getcountry() << endl;
	}
	fout.close();
}