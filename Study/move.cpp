#include "bits/stdc++.h"

using namespace std;

class Person
{
public:
	Person(string name, int age) : name(name), age(age) 
	{
		cout << "������ ȣ��!" << endl;
	}
	
	// ���� ������
	Person(const Person& p) : name(p.name), age(p.age)
	{
		cout << "���� ������ ȣ��!" << endl;
	}

	// �̵� ������
	Person(Person&& p)
	{
		name = move(p.name);
		age = p.age;
		cout << "�̵� ������ ȣ��!" << endl;
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

	// p1�� Move�� p3�� �����ؼ� p1.name�� �� ���ڿ��� �Ǿ���
	// cout << "name : " << p1.name << endl;

	Print(p2);
	Print(Person("Kim",25));
	// PrintRvalueRef(p3);

	return 0;
}