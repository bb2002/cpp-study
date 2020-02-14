#include <iostream>

class Person {

};

using var = Person&;

typedef int& lref;
typedef int&& rlef;

void changeValue(std::string data, int a) {
	data = "You GO!";
	a = 314145;
}

void swap(int * const a, int* const b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swapRef(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	//int a = 10;
	//int b = 20;
	//int& ra = a;
	//ra = b;

	//std::cout << ra << std::endl;

	//const int& ref02 = 15;

	//std::string data = "Helo world!";
	//int a = 132;
	//changeValue(data, a);

	//std::cout << data.data() << ", " << a << std::endl;

	int a = 10, b = 20;
	swap(&a, &b);
	std::cout << a << ", " << b << std::endl;

	swapRef(a, b);
	std::cout << a << ", " << b << std::endl;
}