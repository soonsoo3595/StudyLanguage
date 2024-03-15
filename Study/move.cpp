#include "bits/stdc++.h"

using namespace std;

class Person
{
public:
	Person(string name, int age) : name(name), age(age) 
	{
		cout << "생성자 호출!" << endl;
	}
	
	// 복사 생성자
	Person(const Person& p) : name(p.name), age(p.age)
	{
		cout << "복사 생성자 호출!" << endl;
	}

	// 이동 생성자
	Person(Person&& p)
	{
		name = move(p.name);
		age = p.age;
		cout << "이동 생성자 호출!" << endl;
	}

	string name;
	int age;
};

void Print(const Person& p)
{
	cout << "Lvalue Ref" << p.name << " " << p.age << endl;
}

void Print(Person&& p)
{
	cout << "Rvalue Ref" << p.name << " " << p.age << endl;
}

void PrintRvalueRef(Person&& p)
{
	cout << "Rvalue Ref" << p.name << " " << p.age << endl;
}
int main()
{
	Person p1("CHO", 26);
	cout << "-------------------" << endl;
	Person p2(p1);
	cout << "-------------------" << endl;
	Person p3(move(p1));
	cout << "-------------------" << endl;

	// p1을 Move해 p3를 생성해서 p1.name은 빈 문자열이 되었음
	// cout << "name : " << p1.name << endl;

	Print(p2);
	Print(Person("Kim",25));
	// PrintRvalueRef(p3);

	return 0;
}