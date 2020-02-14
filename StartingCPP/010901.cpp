#include <iostream>
#include <algorithm>
#include <vector>
#include "Array.h"

template<typename C>
bool quote(C& cont, const std::string& s) {
	return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();
}

int main() {
	const int a = 3;
	Array<int> arr{ 1,2,3,4,5 };

	auto result1 = std::find(std::begin(arr), std::end(arr), a);
	if (result1 == std::end(arr)) {
		std::cout << a << " 따윈 없다." << std::endl;
	}
	else {
		std::cout << a << " 따위가 있다." << std::endl;
	}

	Array<int>::iterator it = std::find_if(std::begin(arr), std::end(arr), [](int a) -> bool {
		return (a % 2) == 1; 
	});
	std::cout << "최초의 홀수 : " << *it << std::endl;

	std::cout << "=-=-=-=-=-=-=-= 문자열 찾기이 =-=-=-=-=-=-=-=-=" << std::endl;

	std::string str = "함수는 개별 변수를 컨테인의 요소와 비교하여 해당 위치를 반복자로 만들어";
	std::cout << std::boolalpha << quote(str, "변수") << ", " << quote(str, "반복자") << std::endl;

	Array<char> cvec(str.begin(), str.end());
	std::cout << quote(cvec, "컨테인") << ", " << quote(cvec, "함수") << std::endl;

	std::cout << "=-=-=-=-=-=-=-= 값 찾기이 =-=-=-=-=-=-=-=-=" << std::endl;
	Array<int> stack;
	for (int i = 0; i < 10; ++i) {
		stack.push_back(i*10);
	}
	int middle[] = { 40,50,60 };
	Array<int>::iterator itera = std::search(stack.begin(), stack.end(), middle, middle + 3, [](int r, int l) -> bool { return l == r; });
	std::cout << "middle 의 시작 위치 : " << *itera << std::endl;
}