#include <iostream>

struct Me {
	int age;
	bool isGirl;
	int friends;

	void printMe() {
		std::cout << "������" << std::endl;
	}
};

int main() {
	//Me m(1, false, 10);		 �ȵ˴ϴ�.
	Me m{ 1, false, 10 };		// �˴ϴ�.

	char *c1 = new char[20]();		// ���� 0���� �ʱ�ȭ �Ѵ�.
	int *iptr = new int;

	std::cout << "ptr = " << *iptr << std::endl;

	for (int i = 0; i < 20; ++i) {
		std::cout << ((c1[i] == 0) ? '.' : c1[i]);
	}

	std::cout << std::endl;

	char *c2 = new char[20];		// �ʱ�ȭ ���� �ʴ´�.

	for (int i = 0; i < 20; ++i) {
		std::cout << ((c2[i] == 0) ? '.' : c2[i]);
	}
}

