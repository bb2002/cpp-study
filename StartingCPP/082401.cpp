#include "pch.h"
#include <iostream>
#include <iomanip>
#include <locale>

void showDate(int m, int d, int y) {
	// ������ ���� ä������ �ʴ´ٸ� �̰ɷ� ä���.
	std::cout << std::setfill('0');

	// ������ ���� �����ϰ� ���.
	std::cout << std::setw(2) << m << std::endl;
	std::cout << std::setw(2) << d << std::endl;
	std::cout << std::setw(4) << y << std::endl;
	std::cout << std::endl;
}

int main() {
	double PI = 3.141592846324;

	// ���� �Ҽ��� ���, �Ҽ��� ���� �ڸ��� 2��.
	std::cout << std::fixed << std::setprecision(2) << PI << std::endl;

	PI = 2.0 / 3.0;

	std::cout << std::fixed << std::setprecision(4) << PI << std::endl;

	showDate(8, 24, 2019);

	unsigned long x0 = 64206;
	std::cout << x0 << std::endl;
	std::cout << std::showbase << "8����  : " << std::oct << x0 << std::endl;
	std::cout << std::showbase << "16���� : " << std::hex << x0 << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(15) << std::setfill('-');
	std::cout << std::left << "Hello" << std::endl;
	std::cout << std::setw(15);
	std::cout << std::right << "Hello" << std::endl;
	std::cout << std::setw(15);
	std::cout << std::internal << "Hello" << std::endl;
}