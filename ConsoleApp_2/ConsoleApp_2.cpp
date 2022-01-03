#include <string>
#include <ctype.h>
#include <iostream>
#include "Users_db.h"
using namespace std;

User Enter()
{
	cin.ignore();
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

	User tmp(str, str1, age, ID);
	return tmp;

}

int main()
{
	setlocale(LC_ALL, "rus");
	Users_db one;
	one.load();
	
	int ID;
	cout << " Enter ID to show : ";
	cin >> ID;

	one.Show(one.getById(ID));

	int ID2;
	cout << " Enter ID to delete : ";
	cin >> ID2;
	one.Remove(ID2);

	User tmp = Enter();
	one.Remove(tmp);

	one.print();

}
