#include <iostream>

int main() {
	int a = 1, b = 1, c = 1;
	
	c = [&i = a, a = a + 5]() -> int {
		i += 2;
		std::cout << "&i = " << i << ", a = " << a << std::endl;
		return a + 2;
	}();

	std::cout << "c = " << c << std::endl;
}