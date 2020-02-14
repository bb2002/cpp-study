#include <iostream>

int func() {
	return 12;
}

void MyFun() {
	std::cout << "FUNFUNFUN" << std::endl;
}

template<typename T>
void funcCaller(T(&fun)()) {
	fun();
}

template<typename T>
void funcCallPointer(T(*fun)()) {
	fun();
}

int main() {
	int orig = 5;
	int& ref = orig;
	int *pos = &ref;

	std::cout << "ref = " << ref << "*pos = " << *pos << std::endl;

	int(&xFunc)() = func;
	int x = xFunc();
	std::cout << "x = " << x << std::endl;

	funcCaller<void>(MyFun);
	funcCallPointer<void>(MyFun);
}