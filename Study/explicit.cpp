#include <bits/stdc++.h>

using namespace std;

class Person
{
public:
	explicit operator int const()	// 변환 연산자
	{
		return age;
	}

	explicit Person(int InAge) { age = InAge; }	// 생성자

	void Print() { cout << age << '\n'; }
private:
	int age;
};

int main()
{
	// Person jaehoon = 26;  컴파일 에러가 난다
	Person jaehoon(26);
	jaehoon.Print();

	// int person1 = jaehoon;	컴파일 에러
	int person = static_cast<int>(jaehoon);
}