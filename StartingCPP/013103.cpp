#include <iostream>

int main() {
	char str[200];

	std::cout << "write : ";
	std::cin.getline(str, 100);
	std::cout << "len : " << std::cin.gcount() << " data : " << str << std::endl;
}