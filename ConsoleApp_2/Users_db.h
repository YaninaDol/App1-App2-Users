#pragma once
#include "User.h"
#include <fstream>

class Users_db
{

private:
	User* mas;
	int size;
public:
	Users_db()
	{
		this->size = 0;
		this->mas = new User[this->size];
	}
	User& operator[](const int index)
	{
		if (index < size)
		{
			return this->mas[index];
		}
		else return mas[1];
	}
	void Add(User& tmp)
	{

		User* new_id = new User[this->size + 1];
		for (int i = 0; i < this->size; i++)
		{
			new_id[i] = this->mas[i];
		}
		new_id[size] = tmp;
		delete[] this->mas;
		this->mas = new_id;
		this->size++;
	}
	void load()
	{
		string path = "Data1.txt";
		ifstream fin;
		fin.open(path);
		if (!fin.is_open())
		{
			cout << " Error!";
		}
		else
		{
			while (!fin.eof())
			{
				string str;
				string str1;
				int age;
				long ID;

				fin >> str >> str1 >> age >> ID;
				this->Add(*(new User(str, str1, age, ID)));
			}

			cout << " Чтение произведено! \n";
		}
		fin.close();
	}

	void Delete(int pos)
	{
		User* new_id = new User[this->size - 1];
		for (int j = 0; j < pos && j < size; j++)
		{
			new_id[j] = mas[j];
		}
		for (int j = pos + 1; j < size; j++)
		{
			new_id[j - 1] = mas[j];
		}
		size--;
		delete[](mas);
		mas = new_id;
		cout << " Абонент удален! \n";
	}
	void Remove(int ID)
	{
		int f = 0;
		int pos = -1;
		for (int i = 0; i < size; i++)
		{
			if (this->mas[i].getId() == ID)
			{
				pos = i;
				f = 1;
			}


		}
		if (f == 1)
		{
			this->Delete(pos);
		}
		else
		{
			cout << "Нет такого абонента! \n";

		}

	}
	void Remove(User tmp)
	{
		int f = 0;
		int pos = -1;
		for (int i = 0; i < size; i++)
		{
			if ((this->mas[i].getFname() == tmp.getFname())&& (this->mas[i].getName() == tmp.getName())&& (this->mas[i].getAge() == tmp.getAge()))
			{
				pos = i;
				f = 1;
			}


		}
		if (f == 1)
		{
			this->Delete(pos);
		}
		else
		{
			cout << "Нет такого абонента! \n";

		}

	}
	
	User getById(int ID)
	{
		int f = 0;
		for (int i = 0; i < size; i++)
		{
			if (this->mas[i].getId() == ID)
			{
				return mas[i];
				f = 1;

			}
		}
		if (f == 0)
		{
			cout << "Not foud";
		}

	}

	void Show(User tmp)
	{
		cout << " Name : " << tmp.getName() << "\t" << " Fname : " << tmp.getFname() << "\t"" Age : " << tmp.getAge() << "\t"" ID : " << tmp.getId() << "\n";
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << this->mas[i].getName() << "\t" << mas[i].getFname() << "\t" << mas[i].getAge() << "\t" << mas[i].getId() << "\n";
		}
	}
	~Users_db()
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


};

