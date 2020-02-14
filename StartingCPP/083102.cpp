#include <iostream>

struct Struct {
	int i;
};

void func(Struct, struct Struct f);

void fint(Struct f, int y = 0);

int main() {
	Struct a = { 10 };
	Struct b = { 20 };

	func(a, b);
	fint(a, 10);
	fint(b);
}

void func(Struct a, Struct f)
{
	std::cout << "func " << std::endl;
	std::cout << a.i << std::endl;
	std::cout << f.i << std::endl;
}

void fint(Struct f, int y)
{
	std::cout << "fint" << std::endl;
	std::cout << f.i << std::endl;
	std::cout << y << std::endl;
}
