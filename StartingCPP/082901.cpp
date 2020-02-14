#include "pch.h"
#include <iostream>

int getInt() {
	int data;

	std::cout << "숫자를 입력 하자 : ";
	std::cin >> data;
	return data;
}

int main() {
	const int i = 10;
	
	const int *iptr = &i;

	int m = 36'000'000;		// 디자인.
	int b = 0b0100010;		// 2진수
	int o = 036666;			// 8진수
	int h = 0x000000;		// 16진수

	float a = 3.1415F;
	long l = 1000000ul;		// unsigned long
	auto uul = 100000000000000000ull;		// unsigned long long

	std::cout << NULL << std::endl;

	const int dConst = getInt();
	std::cout << dConst << std::endl;

	char* chardata = new char[10];
	std::cout << &chardata << std::endl;

	std::cin >> chardata;
	std::cin >> chardata;

	std::cout << chardata << std::endl;
}