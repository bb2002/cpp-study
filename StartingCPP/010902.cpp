#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include "Array.h"

int main() {
	int sum = 0;

	Array<int> arr = { 1,2,3,4,5,6,7,8,9,10 };
	std::for_each(arr.begin(), arr.end(), [&sum](int a) -> void { sum += a; });
	std::cout << "��� : " << sum << std::endl;

	std::cout << "=-=-=-=-=-= 999 ���� �ʱ�ȭ =-=-=-=-=-=-=" << std::endl;
	// arr ~ +5 ���� ��� 999 �� �ʱ�ȭ
	std::fill(arr.begin(), arr.begin() + 5, 999);
	std::for_each(arr.begin(), arr.end(), [](int& a) -> void { std::cout << a << std::endl; });

	std::cout << "=-=-=-=-=-= 0 ���� �ʱ�ȭ =-=-=-=-=-=-=" << std::endl;

	// arr ��� �������� �ʱ�ȭ
	std::generate(arr.begin(), arr.end(), []() -> int { return rand(); });
	std::for_each(arr.begin(), arr.end(), [](int& a) -> void { std::cout << a << std::endl; });

	// �����
	std::cout << "=-=-=-=-=-= �ָ��ϰ� ����� =-=-=-=-=-=-=" << std::endl;
	int ints[] = { 1,2,3,4,5,6,7,8,9 };
	int* start = ints;
	int* end = ints + sizeof(ints) / sizeof(int);
	end = std::remove(start, end, 5);
	std::for_each(start, end + 1, [](int a) -> void { std::cout << a << std::endl; });

	std::cout << "=-=-=-=-=-= ���� ����� =-=-=-=-=-=-=" << std::endl;
	std::vector<std::string> strarr = { "korega", "iya", "dodemo", "inochi", "koto" };
	auto it = std::remove(strarr.begin(), strarr.end(), std::string("dodemo"));
	strarr.erase(it, strarr.end());
	for (int i = 0; i < strarr.size(); ++i) {
		std::cout << strarr[i].data() << std::endl;
	}
}