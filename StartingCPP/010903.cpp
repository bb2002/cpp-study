#include <iostream>
#include <string>
#include <algorithm>
#include "Array.h"

int main() {
	std::string arr1[] = { "하레루", "노리사", "뱅드림", "스텐드" };
	Array<std::string> arr2 = { "감정이", "심정이", "apple", "dodemo", "nemuru" };
	Array<std::string> marge(9);

	std::sort(begin(arr1), end(arr1));
	std::sort(arr2.begin(), arr2.end());

	// 배열 통합
	std::merge(begin(arr1), end(arr1), arr2.begin(), arr2.end(), marge.begin());
	std::cout << "arr1 요소 : ";
	for (std::string& a : arr1) { std::cout << a << ", "; }
	std::cout << std::endl;
	std::cout << "arr2 요소 : ";
	for (std::string& a : arr2) { std::cout << a << ", "; }
	std::cout << std::endl;
	std::cout << "marge 요소 : ";
	for (std::string& a : marge) { std::cout << a << ", "; }
	std::cout << std::endl;
}