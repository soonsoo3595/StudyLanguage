#include "bits/stdc++.h"
using namespace std;

int sz = 10;
auto arraysize1 = sz;

// array<int, sz> arr1;		// sz�� ������ ������ �˷��� ���� �ƴϹǷ� ������ ����
constexpr auto arraysize2 = 5;		// ������ ������ �˷��� ���̹Ƿ� ������ ������ �߻����� ����
array<int, arraysize2> arr2;

constexpr int sum(int x, int y)
{
	return x + y;
}

int main()
{
	int size = 10;
	constexpr int csize = 20;
	// int arr[size];
	int arr2[csize];

	int a = 5;
	const int ca = a;
	// constexpr int cea = a;

	constexpr int sum1 = sum(1, 2);

	return 0;
}