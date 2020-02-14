#include <iostream>

struct Bit {
	unsigned char bit = 1;
};

size_t size(int *p) {
	std::cout << "size() 에서 배열의 메모리 크기 : " << sizeof *p << std::endl;
	return sizeof p / sizeof *p;
}

int main() {
	Bit bit;
	int arr[20];

	std::cout << "Bit size : " << sizeof bit << std::endl;
	std::cout << "Array size : " << sizeof arr << std::endl;

	size_t i = size(arr);

	std::cout << "배열의 크기 : " << sizeof arr / sizeof arr[0] << std::endl;
	std::cout << "size() 로 반환 받은 크기 : " << i << std::endl;
}