#include <iostream>

struct Me {
	int age;
	bool isGirl;
	int friends;

	void printMe() {
		std::cout << "싫은뎅" << std::endl;
	}
};

int main() {
	//Me m(1, false, 10);		 안됩니다.
	Me m{ 1, false, 10 };		// 됩니다.

	char *c1 = new char[20]();		// 전부 0으로 초기화 한다.
	int *iptr = new int;

	std::cout << "ptr = " << *iptr << std::endl;

	for (int i = 0; i < 20; ++i) {
		std::cout << ((c1[i] == 0) ? '.' : c1[i]);
	}

	std::cout << std::endl;

	char *c2 = new char[20];		// 초기화 하지 않는다.

	for (int i = 0; i < 20; ++i) {
		std::cout << ((c2[i] == 0) ? '.' : c2[i]);
	}
}

