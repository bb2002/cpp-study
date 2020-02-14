#include <iostream>


constexpr int data(int a) {
	switch (a) {
		case 0:		return 100;
		case 10:	return 1000;
		default:	return -1;
	}
}

constexpr float x = 3.141592;
constexpr float b = data(10);

int main() {
	std::cout << b << std::endl;
}