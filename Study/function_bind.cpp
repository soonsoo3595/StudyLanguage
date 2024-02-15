#include "bits/stdc++.h"
#include <functional>
using namespace std;

class Game
{
public:
	Game(int InLevel) : level(InLevel) {}
	void operator()(int a, int b) { cout << "a = " << a << endl; cout << "b = " << b << endl; }
	void Print() { cout << level << endl; }

private:
	int level;
};

void Add(int a, int b) { cout << "a + b = " << a + b << '\n'; }

void Minus(int a, int b) { cout << "a - b = " << a - b << '\n'; }

int main()
{
	Game game(5);
	// game(10, 20);

	// auto f = [](int a, int b) { cout << "a = " << a << endl; cout << "b = " << b << endl; };
	// f(10, 20);
	// 
	// function<void (int, int)> f1 = Add;
	// function<void(int, int)> f2 = game;		// game을 호출 가능한 객체(펑터)로 처리하고 f2가 초기화됨
	// function<void()> f3 = []() { cout << "std::function<void()>" << endl; };
	// 
	// f1(10, 20);
	// f2(20, 40);
	// f3();

	// function<void()> f4 = game.Print;
	// function<void(Game&)> f4 = &Game::Print;
	// f4(game);

	function<void(int)> func_add = bind(Add, placeholders::_1, 10);
	auto func_minus = bind(Minus, placeholders::_1, 15);

	func_add(15);
	func_minus(20);
	 
	return 0;
}