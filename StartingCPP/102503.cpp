#include <iostream>

class C {
public:
	int x;
};

int i = 1;

template<typename T> void f(T) {
	std::cout << "T ÀÇ Å¸ÀÔ : " << typeid(T).name() << std::endl;
}

template<typename T>
void swap(T& a, T& b) {
	std::cout << "Chaninge.... " << typeid(T).name() << std::endl;

	T c = a;
	a = b;
	b = c;
}

int main() {
	C a = { 0 };
	const C b = { 0 };
	C& c = a;
	const C d = b;

	f(a); f(&a); f(b); f(&b); f(c); f(d); f(C{ 10 });

	int aa = 10;
	int bb = 20;
	swap<int>(aa, bb);
	std::cout << aa << ", " << bb << std::endl;
}