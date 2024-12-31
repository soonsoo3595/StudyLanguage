#include "bits/stdc++.h"
using namespace std;

#pragma region ParamType�� ���� �Ǵ� ������ ���������� ���� ������ �ƴ� ���
template<typename T>
void f1_ref(T& param)
{
	// param = 5; -> �̷��� �ϸ� const �����δ� ȣ���� �Ұ�
}

template<typename T>
void f1_constref(const T& param)
{
	// ��� ��쿡 ParamType�� const T&�̹Ƿ� param ���� �Ұ�
}

template<typename T>
void f1_pointer(T* param)
{

}
#pragma endregion

#pragma region ParamType�� ���� ������
template<typename T>
void f2(T&& param)
{
}
#pragma endregion

#pragma region ParamType�� �����͵� �ƴϰ� ������ �ƴ� ���
template<typename T>
void f3(T param)
{
}

template<typename T>
void f3_ref(T& param)
{

}
#pragma endregion

int main()
{
	int x1 = 27;
	const int cx1 = x1;
	const int& rcx1 = x1;
	const int* px1 = &x1;

	f1_ref(x1);		// T�� int, ParamType�� int&
	f1_ref(cx1);	// T�� const int, ParamType�� const int&
	f1_ref(rcx1);	// T�� const int, ParamType�� const int&

	f1_constref(x1);	// T�� int, ParamType�� const int&
	f1_constref(cx1);	// T�� int, ParamType�� const int&
	f1_constref(rcx1);	// T�� int, ParamType�� const int&

	f1_pointer(&x1);	// T�� int, ParamType�� int*
	f1_pointer(px1);	// T�� const int, ParamType�� const int*

	f2(x1);				// x1�� �ް� -> T�� int&, ParamType�� int&
	f2(cx1);			// x1�� �ް� -> T�� const int&, ParamType�� const int&
	f2(rcx1);			// x1�� �ް� -> T�� const int&, ParamType�� const int&
	f2(27);				// x1�� ������ -> T�� int, ParamType�� int&&

	f3(x1);				// T�� ParamType�� ��� int
	f3(cx1);			// T�� ParamType�� ��� int
	f3(rcx1);			// T�� ParamType�� ��� int

	const char* const ptr = "Hello\n";
	const char name[] = "CHO";

	f3(ptr);			// T�� ParamType�� ��� const char*
	f3(name);			// T�� ParamType�� ��� const char*
	f3_ref(name);		// T�� const char[3], ParamType�� const char (&)[3]

	return 0;
}