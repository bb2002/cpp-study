#include "pch.h"
#include <iostream>
#include <iomanip>
#include <locale>

void showDate(int m, int d, int y) {
	// 문장의 폭이 채워지지 않는다면 이걸로 채우기.
	std::cout << std::setfill('0');

	// 문장의 폭을 지정하고 출력.
	std::cout << std::setw(2) << m << std::endl;
	std::cout << std::setw(2) << d << std::endl;
	std::cout << std::setw(4) << y << std::endl;
	std::cout << std::endl;
}

int main() {
	double PI = 3.141592846324;

	// 고정 소수점 사용, 소수점 이하 자리를 2로.
	std::cout << std::fixed << std::setprecision(2) << PI << std::endl;

	PI = 2.0 / 3.0;

	std::cout << std::fixed << std::setprecision(4) << PI << std::endl;

	showDate(8, 24, 2019);

	unsigned long x0 = 64206;
	std::cout << x0 << std::endl;
	std::cout << std::showbase << "8진법  : " << std::oct << x0 << std::endl;
	std::cout << std::showbase << "16진법 : " << std::hex << x0 << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(15) << std::setfill('-');
	std::cout << std::left << "Hello" << std::endl;
	std::cout << std::setw(15);
	std::cout << std::right << "Hello" << std::endl;
	std::cout << std::setw(15);
	std::cout << std::internal << "Hello" << std::endl;
}