#include <bits/stdc++.h>

using namespace std;

class Person
{
public:
	Person(int InAge) { age = InAge; }

	void Print() { cout << age << '\n'; }
private:
	int age;
};

int main()
{
	Person jaehoon = 26;	// �Ϲ��� ����ȯ
	jaehoon.Print();
}