#include <iostream>

struct Bit {
	unsigned char bit = 1;
};

size_t size(int *p) {
	std::cout << "size() ���� �迭�� �޸� ũ�� : " << sizeof *p << std::endl;
	return sizeof p / sizeof *p;
}

int main() {
	Bit bit;
	int arr[20];

	std::cout << "Bit size : " << sizeof bit << std::endl;
	std::cout << "Array size : " << sizeof arr << std::endl;

	size_t i = size(arr);

	std::cout << "�迭�� ũ�� : " << sizeof arr / sizeof arr[0] << std::endl;
	std::cout << "size() �� ��ȯ ���� ũ�� : " << i << std::endl;
}