#include "bits/stdc++.h"
using namespace std;

#pragma region ParamType이 참조 또는 포인터 형식이지만 보편 참조가 아닌 경우
template<typename T>
void f1_ref(T& param)
{
	// param = 5; -> 이렇게 하면 const 변수로는 호출이 불가
}

template<typename T>
void f1_constref(const T& param)
{
	// 모든 경우에 ParamType이 const T&이므로 param 수정 불가
}

template<typename T>
void f1_pointer(T* param)
{

}
#pragma endregion

#pragma region ParamType이 보편 참조임
template<typename T>
void f2(T&& param)
{
}
#pragma endregion

#pragma region ParamType이 포인터도 아니고 참조도 아닌 경우
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

	f1_ref(x1);		// T는 int, ParamType은 int&
	f1_ref(cx1);	// T는 const int, ParamType은 const int&
	f1_ref(rcx1);	// T는 const int, ParamType은 const int&

	f1_constref(x1);	// T는 int, ParamType은 const int&
	f1_constref(cx1);	// T는 int, ParamType은 const int&
	f1_constref(rcx1);	// T는 int, ParamType은 const int&

	f1_pointer(&x1);	// T는 int, ParamType은 int*
	f1_pointer(px1);	// T는 const int, ParamType은 const int*

	f2(x1);				// x1는 왼값 -> T는 int&, ParamType은 int&
	f2(cx1);			// x1는 왼값 -> T는 const int&, ParamType은 const int&
	f2(rcx1);			// x1는 왼값 -> T는 const int&, ParamType은 const int&
	f2(27);				// x1는 오른값 -> T는 int, ParamType은 int&&

	f3(x1);				// T와 ParamType이 모두 int
	f3(cx1);			// T와 ParamType이 모두 int
	f3(rcx1);			// T와 ParamType이 모두 int

	const char* const ptr = "Hello\n";
	const char name[] = "CHO";

	f3(ptr);			// T와 ParamType이 모두 const char*
	f3(name);			// T와 ParamType이 모두 const char*
	f3_ref(name);		// T는 const char[3], ParamType은 const char (&)[3]

	return 0;
}