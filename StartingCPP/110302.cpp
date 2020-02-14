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
	Derived *pd;
	Base *pba = new Derived(23);	// UP CAST
	
	pd = dynamic_cast<Derived*>(pba);	// OK.
	if (pd == nullptr) {
		std::cout << "pba cast failed." << std::endl;
	}

	pd->setNumber(10);
	std::cout << pd->number << std::endl;
	std::cout << pd->dummy() << std::endl;
	delete pba;

	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;

	Base *pbb = new Base(2556);
	pd = dynamic_cast<Derived*>(pbb);
	if (pd == nullptr) {
		std::cout << "pbb cast failed" << std::endl;
	}
	pd->setNumber(110);
	std::cout << pd->number << std::endl;
	std::cout << pd->dummy() << std::endl;

}