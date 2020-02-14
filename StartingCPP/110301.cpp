#include <iostream>

void print(int *ptr) {
	*ptr = *ptr + 10;
	std::cout << "int *ptr = " << *ptr << std::endl;
}

void print(const int *ptr) {
	std::cout << "const int *ptr = " << *ptr << std::endl;
}

void fun(const int& val) {
	print(&val);
	print(const_cast<int*>(&val));
}

int main() {
	const volatile int a = 3;
	const_cast<int&>(a) = 4;
	std::cout << "a = " << a << std::endl;

	const volatile int b = 5;
	int* bp = const_cast<int*>(&b);
	(*bp) = 10;
	std::cout << "b = " << b << std::endl;
	std::cout << "*b = " << &b << ", bp = " << bp << std::endl;

	const int c = 30;

	int d = 3141592;
	fun(d);
}