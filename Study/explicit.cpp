#include <bits/stdc++.h>

using namespace std;

class Person
{
public:
	explicit operator int const()	// ��ȯ ������
	{
		return age;
	}

	explicit Person(int InAge) { age = InAge; }	// ������

	void Print() { cout << age << '\n'; }
private:
	int age;
};

int main()
{
	// Person jaehoon = 26;  ������ ������ ����
	Person jaehoon(26);
	jaehoon.Print();

	// int person1 = jaehoon;	������ ����
	int person = static_cast<int>(jaehoon);
}