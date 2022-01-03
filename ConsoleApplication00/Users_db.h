#pragma once
#include "User.h"
#include <conio.h>
#include <fstream>
using namespace std;

class Users_db
{
private:
	User* mas = new User[0];
	int size = 0;
public:
	Users_db()
	{
		mas = nullptr;
		size = 0;
	}
	
	void Add(User tmp)
	{

		User* new_id = new User[size + 1];
		for (int i = 0; i < size; i++)
		{
			new_id[i] = mas[i];
		}
		new_id[size] = tmp;
		delete[](mas);
		mas = new_id;
		size++;
	}

	void Save()
	{
		string path = "Data1.txt";
		ofstream fout;
		fout.open(path, ofstream::app);
		if (!fout.is_open())
		{
			cout << " Error!";
		}
		else
		{
			for (int i = 0; i < size; i++)
			{

				fout << this->mas[i].getName() << "\t" << this->mas[i].getFname() << "\t"
					<< this->mas[i].getAge() << "\t" << this->mas[i].getId();
				if (i != size - 1)
				{
					fout << endl;
				}
				else { break; };
			}
			cout << " Запись произведена! \n";
		}
		fout.close();
	}

	~Users_db()
	{
		delete[](mas);
	}
};

