#include <iostream>

int main() {
	char *c = new char[1000];
	c[0] = 'a';
	std::cout << c[0] << std::endl;

	delete[] c;

	std::cout << c[0] << std::endl;
}