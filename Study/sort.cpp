#include <bits/stdc++.h>

constexpr int n = 10;
int arr[n] = { 7, 5, 4, 2, 8, 6, 0, 9, 1, 3 };
using namespace std;

void Print(int (&list)[n])
{
	for (int i = 0; i < n; i++)
	{
		cout << list[i] << ' ';
	}
	cout << '\n';
}

void Bubble_Sort()
{
	int temp[10];
	memcpy(temp, arr, sizeof(temp));

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (temp[j] > temp[j + 1])
			{
				swap(temp[j], temp[j + 1]);
			}
		}
	}

	Print(temp);
}

void Selection_Sort()
{
	int temp[10];
	memcpy(temp, arr, sizeof(temp));

	for (int i = 0; i < n - 1; i++)
	{
		int min_index = i;

		for (int j = i + 1; j < n; j++)
		{
			if (temp[j] < temp[min_index])
			{
				min_index = j;
			}
		}

		if (min_index != i)
			swap(temp[i], temp[min_index]);
	}

	Print(temp);
}

void Insertion_Sort()
{
	int temp[10];
	memcpy(temp, arr, sizeof(temp));

	for (int i = 1; i < n; i++)
	{
		int value = temp[i];
		int j = i - 1;

		while (j >= 0 && temp[j] > value)
		{
			temp[j + 1] = temp[j];
			j--;
		}

		temp[j + 1] = value;
	}

	Print(temp);
}

int main()
{
	Bubble_Sort();
	Selection_Sort();
	Insertion_Sort();
}