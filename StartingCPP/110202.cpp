#include<iostream>

class Base {
public:
	virtual void echo() {
		std::cout << "Base::echo() called" << std::endl;
	}
};

class Extend : public Base {
public:
	void setNumber(int a) {
		this->a = a;
	}

private:
	int a = -1;
};

int main() {
	Extend e;
	Base& br = e;		// up-cast

	//Extend& ex = (Extend&)br;
	Extend& ex = static_cast<Extend&>(br);
	printf("e = %p, br = %p, ex = %p", &e, &br, &ex);
}