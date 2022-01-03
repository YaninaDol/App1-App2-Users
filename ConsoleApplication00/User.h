#include <iostream>
#include <string>
using namespace std;

class User
{
private:
	string name;
	string fname;
	int age;
	long id;
public:
	User()
	{
		this->name = ' ';
		this->fname = ' ';
		this->age = 0;
		this->id = 0;
	}
	User(string str1, string str2, int age, long ID)
	{
		this->name = str1;
		this->fname = str2;
		this->age = age;
		this->id = ID;
	}
	string getName()
	{
		return this->name;
	}
	string getFname()
	{
		return this->fname;
	}
	int getAge()
	{
		return this->age;
	}
	long getId()
	{
		return this->id;
	}

	void setName(string str1)
	{
		this->name = str1;
	}
	void setFname(string str2)
	{
		this->fname = str2;
	}

	void setAge(int age)
	{
		this->age = age;
	}

	friend std::ostream& operator<<(std::ostream& out, const User us)
	{
		out << "User name : " << us.name << "\t User fname : " << us.fname << "\t Age : " << us.age << " \t Id: " << us.id;
	}

};

