#include<iostream>

int f() {
	return 1234;
}

int main() {
	int i = 5;

	void(*fp1)() = reinterpret_cast<void(*)()>(f);
	int(*fp2)() = reinterpret_cast<int(*)()>(fp1);

	fp1();
	reinterpret_cast<unsigned int&>(i) = fp2();
	std::cout << i << std::endl;
	
	char* p2 = reinterpret_cast<char*>(&i);
	for (int i = 0; i < 4; ++i) {
		std::cout << p2[i];
	}

	std::cout << std::endl;
}