#include <iostream>

int main() {
	int m = 0;
	int n = 0;

	[&, n](int a) {
		m = n + a;
	}(4);

	std::cout << "n = " << n << "m = " << m << std::endl;

	int a = 1, b = 1, c = 1;
	[a, &b, &c]() mutable {
		a = 3; b = 3; c = 3;
	}();

	std::cout << "a=" << a << "b=" << b << "c=" << c << std::endl;

	// C++ 2017
	//auto ID = [](const int a) constexpr { return a; };
	//constexpr int a = ID(3);


	auto h = []() throw() {
		return rand();
	};
	std::cout << h() << std::endl;
	try {
		[]() {
			throw 5;
		}();
	}
	catch (int e) {
		std::cout << e << std::endl;
	}
}