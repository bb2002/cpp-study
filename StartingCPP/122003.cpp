#include <iostream>

class Complex {
private:
	float a, b;

public:
	explicit Complex(double a) : a(a) {
		std::cout << "Complex(double a) : " << a << std::endl;
	}

	explicit Complex(double a, double b) : a(a), b(b) {
		std::cout << "Complex(double a, double b) : " << a << ", " << b << std::endl;
	}
};

int main() {
	//Complex c1 = 1;
	Complex c2(2);
	Complex c3{4, 5};
	//Complex c4 = { 6, 7 };
	Complex c5 = (Complex)8;
	Complex* c6 = new Complex(9, 0);
}