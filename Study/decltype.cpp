#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a = 3;
	decltype(a) a1 = 5;		// int a1

	int& r_a = a;
	decltype(r_a) r_a1 = a1;  // int& r_a1

	int&& rr_a = 3;
	decltype(rr_a) rr_a1 = 7;  // int&& rr_a1
	
	int c = 3, d = 4;
	decltype(c + d) cd;
	decltype((a));

}