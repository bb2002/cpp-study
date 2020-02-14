#include <iostream>

class Base {
	int state;

public:
	Base() : state(0) {

	}

	Base(int a) : state(a) {

	}

	virtual int dummy() {
		std::cout << "Base dummy() called" << std::endl;
		return state;
	}
};

class Derived : public Base {
public:
	Derived(int i) : Base(i) {

	}

	void setNumber(int a) {
		number = a;
	}

	int number;
};

int main() {
	Base base;
	Base& base2 = base;

	try {
		Derived& d = dynamic_cast<Derived&>(base2);
		d.dummy();
	}
	catch (std::bad_cast& e) {
		std::cout << e.what() << std::endl;
	}
}