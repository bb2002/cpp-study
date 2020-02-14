#include <iostream>

void print(int i) {
	std::cout << "int " << i << std::endl;
}

void print(double d) {
	std::cout << "double " << d << std::endl;
}

void print(const char* c) {
	std::cout << "const chars " << c << std::endl;
}

void print(char* c) {
	std::cout << "chars " << c << std::endl;
}

void tmp(int i, double d, const char* c);

void tmp(int i = 10, double d = 10.0, const char* c = "Hello World");

void m();


int main() {
	/*print(1000);
	print(3.141592);
	print("Hello world!!");

	char* str = new char[100];
	std::cin >> str;
	print(str);*/

	m();
	tmp(600);
}

void m() {
	//void tmp(int, double = 1.0, const char* = "한국 안녕하세요!");
	tmp(4, 6.1, "Hello DefaultWorld!");
	tmp(64);
}

void tmp(int i, double d, const char* c) {
	printf("정수 : %d, 실수 : %f, 문자 : %s\n", i, d, c);
}