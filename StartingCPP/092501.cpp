#include <iostream>

template<typename T1, typename T2, int I>
class A {
private:
	T1 a;
	T2 b;

public:
	A() {
		std::cout << I << std::endl;
	}
};
template<> class A<int, double, 10> {
private:
	int a;
	double b;

public:
	A() {
		std::cout << "¸í½ÃÀû" << std::endl;
	}
};

int main() {
	auto a = A<int, double, 10>();
}