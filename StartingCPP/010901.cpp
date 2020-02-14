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
		std::cout << a << " ���� ����." << std::endl;
	}
	else {
		std::cout << a << " ������ �ִ�." << std::endl;
	}

	Array<int>::iterator it = std::find_if(std::begin(arr), std::end(arr), [](int a) -> bool {
		return (a % 2) == 1; 
	});
	std::cout << "������ Ȧ�� : " << *it << std::endl;

	std::cout << "=-=-=-=-=-=-=-= ���ڿ� ã���� =-=-=-=-=-=-=-=-=" << std::endl;

	std::string str = "�Լ��� ���� ������ �������� ��ҿ� ���Ͽ� �ش� ��ġ�� �ݺ��ڷ� �����";
	std::cout << std::boolalpha << quote(str, "����") << ", " << quote(str, "�ݺ���") << std::endl;

	Array<char> cvec(str.begin(), str.end());
	std::cout << quote(cvec, "������") << ", " << quote(cvec, "�Լ�") << std::endl;

	std::cout << "=-=-=-=-=-=-=-= �� ã���� =-=-=-=-=-=-=-=-=" << std::endl;
	Array<int> stack;
	for (int i = 0; i < 10; ++i) {
		stack.push_back(i*10);
	}
	int middle[] = { 40,50,60 };
	Array<int>::iterator itera = std::search(stack.begin(), stack.end(), middle, middle + 3, [](int r, int l) -> bool { return l == r; });
	std::cout << "middle �� ���� ��ġ : " << *itera << std::endl;
}