#include <iostream>

class MyClass {

};

int main() {
	MyClass *p = nullptr;

	try {
		std::cout << typeid(*p).name() << "\n";
	}
	catch (const std::bad_typeid& e) {
		std::cout << e.what() << std::endl;
	}
}