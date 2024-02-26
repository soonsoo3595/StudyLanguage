#include "bits/stdc++.h"
using namespace std;

void f(int param[3])
{
	cout << "param size : " << sizeof(param) << endl;
}

void g(int(&param)[3])
{
	cout << "&param size : " << sizeof(param) << endl;
}

int main()
{
	int arr[] = {1, 2, 3};
	cout << "arr size : " << sizeof(arr) << endl;

	int num = 3;
	int* pnum = &num;
	cout << "pnum size : " << sizeof(pnum) << endl;

	auto auto_arr = arr;
	cout << "auto arr size : " << sizeof(auto_arr) << endl;

	f(arr);
	g(arr);

	return 0;
}