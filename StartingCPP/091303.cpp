#include <iostream>

class Complex {
public:
	constexpr Complex(int a, int b) : a(a), b(b) {

	}

private:
	int a;
	int b;
};

int main() {
	constexpr Complex Comp(10, 20);	// OK.

	int d = 100;
	//constexpr Complex Comp2(d, 20); // NO

	Complex Comp3(100, 200);		// OK.

	const Complex Comp4(10, 20);
}