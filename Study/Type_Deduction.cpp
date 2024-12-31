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

template<typename T>
void f4(initializer_list<T> param)
{

}

auto f4_auto()
{
	// return { 1, 2, 3 };		������ ����
}

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

	auto ax1 = 27;		// ax1�� int
	auto ax2(27);		// ax2�� int
	auto ax3 = { 27 };	// ax3�� std::initializer_list<int>
	auto ax4{ 27 };		// ax4�� std::initializer_list<int>

	// auto ax5 = { 1, 2, 3.0 };	������ ����
	// f3({ 1, 2, 3 });				������ ���� -> ���ø����� �߰�ȣ �ʱ�ġ�� ó���� ������ ��Ģ�� ����
	f4({ 1, 2, 3 });
	
	int dx = 5;
	decltype(dx) dx1 = dx;			// dx1�� Ÿ���� int
	decltype((dx)) dx2 = dx;		// dx2�� Ÿ���� int&
	dx2 = 3;
	cout << dx << '\n';				// 3�� ��µȴ�

	
	return 0;
}