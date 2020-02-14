#include <iostream>

class Complex {
private:
	int a;
	int b;

public:
	Complex(int a, int b) : a(a), b(b) {
		
	}

	bool operator==(const Complex& other) {
		return other.a == a && other.b == b;
	}

	friend std::ostream& operator<<(std::ostream&, const Complex&);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
	os << c.a << ", " << c.b;
	return os;
}

int main() {
	Complex num1(2, 3);
	Complex* num2 = new Complex(3, 4);

	std::cout << "첫번째 : " << num1 << std::endl;
	std::cout << "두번째 : " << *num2 << std::endl;

	std::cout << (num1 == (num1)) << std::endl;
}