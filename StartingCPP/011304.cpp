#include <iostream>
#include <functional>

void print(int a) {
	std::cout << a << std::endl;
}

int main() {
	int i = 10;
	std::reference_wrapper<int> y(i);

	auto f1 = std::bind(&print, i);
	auto f2 = std::bind(&print, y);
	auto f3 = std::bind(&print, std::ref(i));

	f1();
	i = 20;
	f2();
	i = 30;
	f3();
}