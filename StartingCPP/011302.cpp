#include <iostream>

typedef float(*Fun)(float);

void caller(Fun f, float data) {
	float e = f(data);
	std::cout << "f() return : " << e << std::endl;
}

float CallbackFun(float size) {
	std::cout << "SIZE : " << size << std::endl;
	return 2.17F;
}

int main() {
	caller(&CallbackFun, 3.141592F);
}