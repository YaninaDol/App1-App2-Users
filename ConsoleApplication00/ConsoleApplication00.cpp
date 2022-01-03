#include <string>
#include <ctype.h>
#include <iostream>
#include "Users_db.h"
using namespace std;

User Enter()
{
	cout << " Enter Name : ";
	string str;
	getline(cin, str);

	cout << " Enter Father Name : ";
	string str1;
	getline(cin, str1);

	cout << " Enter age : ";
	int age;
	cin >> age;

	cout << " Enter id : ";
	long ID;
	cin >> ID;
	cin.ignore();
	User tmp(str, str1, age, ID);
	return tmp;

}

int main()
{

	setlocale(LC_ALL, "rus");
	Users_db one;
	User tmp = Enter();
	User tmp2 = Enter();

	one.Add(tmp);
	one.Add(tmp2);
	one.Save();

}
