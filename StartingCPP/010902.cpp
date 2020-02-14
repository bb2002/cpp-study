#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include "Array.h"

int main() {
	int sum = 0;

	Array<int> arr = { 1,2,3,4,5,6,7,8,9,10 };
	std::for_each(arr.begin(), arr.end(), [&sum](int a) -> void { sum += a; });
	std::cout << "결과 : " << sum << std::endl;

	std::cout << "=-=-=-=-=-= 999 으로 초기화 =-=-=-=-=-=-=" << std::endl;
	// arr ~ +5 까지 모두 999 로 초기화
	std::fill(arr.begin(), arr.begin() + 5, 999);
	std::for_each(arr.begin(), arr.end(), [](int& a) -> void { std::cout << a << std::endl; });

	std::cout << "=-=-=-=-=-= 0 으로 초기화 =-=-=-=-=-=-=" << std::endl;

	// arr 모두 렌덤으로 초기화
	std::generate(arr.begin(), arr.end(), []() -> int { return rand(); });
	std::for_each(arr.begin(), arr.end(), [](int& a) -> void { std::cout << a << std::endl; });

	// 지우기
	std::cout << "=-=-=-=-=-= 애매하게 지우기 =-=-=-=-=-=-=" << std::endl;
	int ints[] = { 1,2,3,4,5,6,7,8,9 };
	int* start = ints;
	int* end = ints + sizeof(ints) / sizeof(int);
	end = std::remove(start, end, 5);
	std::for_each(start, end + 1, [](int a) -> void { std::cout << a << std::endl; });

	std::cout << "=-=-=-=-=-= 빡빡 지우기 =-=-=-=-=-=-=" << std::endl;
	std::vector<std::string> strarr = { "korega", "iya", "dodemo", "inochi", "koto" };
	auto it = std::remove(strarr.begin(), strarr.end(), std::string("dodemo"));
	strarr.erase(it, strarr.end());
	for (int i = 0; i < strarr.size(); ++i) {
		std::cout << strarr[i].data() << std::endl;
	}
}