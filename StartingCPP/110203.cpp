#include <iostream>

int i = 0;

void paramCheck(int& a) {
	std::cout << ++i << ". " << a << " int& Ÿ��" << std::endl;
}

void paramCheck(const int& a) {
	std::cout << ++i << ". " << a << " const int& Ÿ��" << std::endl;
}

void paramCheck(int&& a) {
	std::cout << ++i << ". " << a << " int&& Ÿ��" << std::endl;
}

int main() {
	int s = 10;
	paramCheck(s);
	const int& cs = s;
	paramCheck(cs);
	paramCheck(static_cast<int&&>(s));
	paramCheck((int&&)10);
}