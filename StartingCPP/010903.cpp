#include <iostream>
#include <string>
#include <algorithm>
#include "Array.h"

int main() {
	std::string arr1[] = { "�Ϸ���", "�븮��", "��帲", "���ٵ�" };
	Array<std::string> arr2 = { "������", "������", "apple", "dodemo", "nemuru" };
	Array<std::string> marge(9);

	std::sort(begin(arr1), end(arr1));
	std::sort(arr2.begin(), arr2.end());

	// �迭 ����
	std::merge(begin(arr1), end(arr1), arr2.begin(), arr2.end(), marge.begin());
	std::cout << "arr1 ��� : ";
	for (std::string& a : arr1) { std::cout << a << ", "; }
	std::cout << std::endl;
	std::cout << "arr2 ��� : ";
	for (std::string& a : arr2) { std::cout << a << ", "; }
	std::cout << std::endl;
	std::cout << "marge ��� : ";
	for (std::string& a : marge) { std::cout << a << ", "; }
	std::cout << std::endl;
}