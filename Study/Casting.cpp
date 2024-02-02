#include <bits/stdc++.h>

using namespace std;

class Base
{
public:
	int getA() { return a; }
	double getB() { return b; }
	void Print()
	{
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
	}

	virtual ~Base() = default;
protected:
	int a = 10;
	double b = 20.5;
};

class Derived : public Base
{
public:
	int getC() { return c; }
	double getD() { return d; }
	void Print()
	{
		Base::Print();
		cout << "c = " << c << endl;
		cout << "d = " << d << endl;
	}

	virtual ~Derived() = default;
protected:
	int c = 30;
	double d = 40.5;
};

int main()
{
	int num1 = 20;
	double num2 = 30.5;
	int num3;
	double num4;

	num3 = static_cast<int>(num2);
	num4 = static_cast<double>(num1);

	cout << "num3 = " << num3 << endl;
	cout << "num4 = " << num4 << endl;

	int* p1 = &num1;
	double* p2 = &num2;
	int* p3;
	double* p4;

	// p3 = static_cast<int*>(p2); -> 컴파일 에러
	// p3 = (int*)p2; -> 쓰레기 값
	// p4 = static_cast<double*>(p1);
	// p4 = (double*)p1;

	// cout << "p3 = " << *p3 << endl;
	// cout << "p4 = " << *p4 << endl;

	// Base* b;
	// Derived* d = new Derived();
	// 
	// b = static_cast<Base*>(d);	// 업캐스팅
	// b->Print();

	// Base* b = new Base();
	// Derived* d;
	// 
	// d = static_cast<Derived*>(b);	// 다운캐스팅
	// d->Print();	// 쓰레기값

	// const int cnum = 10;
	// const int* ptrcnum = &cnum;
	// int* cnum2 = const_cast<int*>(ptrcnum);

	// double d = 3.14;
	// char p = reinterpret_cast<char>(&d);

	Base* b;
	Derived* d = new Derived();
	b = d;
	d = dynamic_cast<Derived*>(b);	// 클래스에 가상 함수가 없을 때는 컴파일 에러
}