#include<iostream>
#include<fstream>
using namespace std;

#include"Repository.h"
#include"ClientRepository.h"

ClientRepository::ClientRepository(bool sync) : Repository(sync)
{
	ReadFromStorage();
}

bool ClientRepository::Add(Client& client)
{
	return Repository::Add(&client);
}

void ClientRepository::ReadFromStorage()
{
	ifstream fin("C:\\Users\\User\\Desktop\\�++ 2 ����\\repository,restaurant\\Client.txt");
	string name;string surname;int discount;
	if (!fin.is_open())
	{
		cout << "your file is not open!" << endl;
	}
	while (fin)
	{
		if (fin >> name >> surname >> discount)
		{
			Client* c = new Client(name, surname, discount);
			Add(*c);
		}
	}
	fin.close();
}

void ClientRepository::WriteToStorage()
{
	ofstream fout("C:\\Users\\User\\Desktop\\�++ 2 ����\\repository,restaurant\\Client.txt", ios::out);
	for (int i = 0;i < vEntity.size();i++)
	{
		fout << ((Client*)vEntity[i])->getname() << " " << ((Client*)vEntity[i])->getsurname()
			<< " " << ((Client*)vEntity[i])->getdiscount() << endl;
	}
	fout.close();
}

