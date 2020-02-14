#include <iostream>
#include <string>

class Complex {
private:
	double real;
	double imaginary;

public:
	constexpr Complex(double real) : real(real), imaginary(0) {

	}
	constexpr Complex(double real, double imaginary) : real(real), imaginary(imaginary) {

	}

	// 단항 연산자 오버로딩
	Complex operator+() {
		return Complex(this->real, this->imaginary);
	}
	Complex operator-() {

		return Complex(-this->real, -this->imaginary);
	}

	Complex operator++() {
		++this->real;
		++this->imaginary;
		return *this;
	}
	Complex operator++(int) {
		Complex tmp(this->real, this->imaginary);
		++this->real;
		++this->imaginary;
		return tmp;
	}
	Complex operator--() {
		--this->real;
		--this->imaginary;
		return *this;
	}
	Complex operator--(int) {
		Complex tmp(this->real, this->imaginary);
		--this->real;
		--this->imaginary;
		return tmp;
	}

	// 산술 연산자
	constexpr Complex operator+(const Complex& other) {
		return Complex(this->real + other.real, this->imaginary + other.imaginary);
	}
	constexpr Complex operator-(const Complex& other) {

		return Complex(this->real - other.real, this->imaginary - other.imaginary);
	}
	constexpr Complex operator*(const Complex& other) {

		return Complex(this->real * other.real, this->imaginary * other.imaginary);
	}
	constexpr Complex operator/(const Complex& other) {

		return Complex(this->real / other.real, this->imaginary / other.imaginary);
	}

	// 대입연산자
	Complex& operator=(const Complex& other) {
		this->real = other.real;
		this->imaginary = other.imaginary;
		return *this;
	}
	Complex& operator+=(const Complex& other) {
		this->real += other.real;
		this->imaginary += other.imaginary;
		return *this;
	}
	Complex& operator-=(const Complex& other) {
		this->real -= other.real;
		this->imaginary -= other.imaginary;
		return *this;
	}

	// 비교 연산자
	bool operator==(const Complex& other) {
		return this->real == other.real && this->imaginary == other.imaginary;
	}
	bool operator!=(const Complex& other) {
		return !operator==(other);
	}

	operator char*() const {
		char* buf = new char[20];
		snprintf(buf, 20, "(%.2f + %.2f)", real, imaginary);
		return buf;
	}

	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	friend Complex operator+(const Complex& left, const Complex& right);

	double GetReal() const {
		return this->real;
	}

	double GetImaginary() const {
		return this->imaginary;
	}
};

inline Complex operator+(const Complex& left, const Complex& right) {
	return Complex(left.real + right.real, left.imaginary + right.imaginary);
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
	os << c.real << ", " << c.imaginary;
	return os;
}


int main() {
	Complex a(10, 15);
	Complex b(20, 30);
	Complex c(40, 50);

	std::cout << +a << std::endl;
	std::cout << -b << std::endl;
	std::cout << "=-=-=-=-=-=-=-=-=-=" << std::endl;

	std::cout << ++a << std::endl;
	std::cout << --b << std::endl;
	std::cout << a++ << std::endl;
	std::cout << b-- << std::endl;
	std::cout << "++, --" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "=-=-=-=-=-=-=-=-=-=" << std::endl;

	std::cout << (a*b) << std::endl;
	std::cout << (a + b) << std::endl;
	std::cout << "=-=-=-=-=-=-=-=-=-=" << std::endl;

	a = b;
	std::cout << a << " / " << b << std::endl;
	std::cout << std::boolalpha << (a == b) << std::endl;
	std::cout << std::boolalpha << (a != b) << std::endl;

	c += a;
	std::cout << c << std::endl;
	c -= b;
	std::cout << c << std::endl;
}