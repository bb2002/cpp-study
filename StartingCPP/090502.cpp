#include <iostream>

int main() {
	int x = 1000;
	int y = 2000;

	std::cout << x << " & " << y << " :: " << (x & y) << std::endl;		// 960
	std::cout << x << " | " << y << " :: " << (x | y) << std::endl;		// 2040
	std::cout << x << " ^ " << y << " :: " << (x ^ y) << std::endl;		// 1080

}