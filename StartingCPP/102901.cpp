#include <iostream>

int global = 120;

// xvalue
int&& add(int a, int b) {
	return std::move(a + b);
}

int& getGlobal() {
	return global;
}

int main() {
	int* gPtr = &global;

	int&& r = add(1, 2);
	std::cout << r << std::endl;
}