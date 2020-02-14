#include <iostream>

class Test {
public:
	int a;

	Test(int a) : a(a) {}
};

class SafePointer {
	Test* data;

public:
	SafePointer(Test* a) : data(a) {

	}

	Test* operator->() const {
		return data;
	}

	~SafePointer() {
		std::cout << "test dell" << std::endl;
		delete data;
	}
};

int main() {
	Test* test = new Test(10);

	{
		SafePointer ptr(test);
		std::cout << "a data ; " << (ptr->a) << std::endl;
	}

	std::cout << "end :: " << (test->a) << std::endl;
}