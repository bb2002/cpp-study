#include <iostream>
#include <vector>

int main() {
	std::vector<int> myvec(5);
	int* p = myvec.data();

	*p = 10;
	for (int i = 1; i < myvec.size(); ++i) {
		p[i] = p[i - 1] * i;
	}
	*(++p) += 20;

	std::cout << "myvec 의 데이터 : " << std::endl;
	for (int i = 0; i < myvec.size(); ++i) {
		std::cout << " " << myvec[i];
	}
	std::cout << std::endl;

	std::vector<std::string> mystr(5);
	std::string* s = mystr.data();

	*s = "안녕 세카이";
	*(s + 1) = "안녕 레오나";
	*(s + 2) = "안녕 메아";
	*(s + 3) = "안녕 코코아";

	std::cout << "mystr데이터 : " << std::endl;
	for (auto& a : mystr) {
		std::cout << a.c_str() << ", ";
	}

	std::cout << std::endl;
}