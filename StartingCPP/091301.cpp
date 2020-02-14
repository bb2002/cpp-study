#include <iostream>

class MyClass {
public:
	MyClass(int a, int b) {
		this->a = a;
		this->b = b;
	}

	void show() {
		std::cout << "field val : " << a << ", " << b << ", " << c << std::endl;
	}

	inline void end() {
		std::cout << "end" << std::endl;
	}

private:
	int a;
	int b;
	static int c;
};

int MyClass::c = 100;

int main() {
	MyClass ms1(10, 20);
	MyClass ms2(20, 30);
	ms1.show();
	ms1.end();

	ms2.show();
	ms2.end();
}