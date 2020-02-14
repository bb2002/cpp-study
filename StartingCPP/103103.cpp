#include <iostream>

class W {
public:
	W(int&, int&) {
		std::cout << "W(int&, int&)" << std::endl;
	}
};

class X {
public:
	X(const int&, int&) {
		std::cout << "X(const int&, int&)" << std::endl;
	}
};

class Y {
public:
	Y(int&, const int&) {
		std::cout << "Y(int&, const int&)" << std::endl;
	}
};

class Z {
public:
	Z(const int&, const int&) {
		std::cout << "Z(const int&, const int&)" << std::endl;
	}
};

template<typename T, typename A1, typename A2>
T* factory(A1&& a1, A2&& a2) {
	return new T(a1, a2);
}

int main() {
	int a = 4, b = 5;
	W* pw = factory<W>(a, b);
	X* px = factory<X>(2, b);
	Y* py = factory<Y>(a, 2);
	Z* pz = factory<Z>(2, 3);

	char* str = new char[30];
	char str2[30];

	char& a = str2[5];
	char*& b = str;

}