#include <iostream>

void countdown(int n) {
	if (n == 0) {
		// 기저사례
		std::cout << "카운트 끝" << std::endl;
		return;
	}

	std::cout << n << std::endl;
	countdown(n-1);
}

void kyukyudan(int n) {
	if (n == 1) {
		std::cout << "2 * 1 = 2" << std::endl;
		return;
	}

	std::cout << "2 * " << n << " = " << 2 * n << std::endl;
	kyukyudan(n - 1);
}

void kyukyudan_rev(int n) {
	if (n == 10) {
		std::cout << "2 * 10 = 20" << std::endl;
		return;
	}

	std::cout << "2 * " << n << " = " << 2 * n << std::endl;
	kyukyudan_rev(n + 1);
}

int fact(int n) {
	if (n == 1) {
		return 1;
	}

	return n * fact(n - 1);
}

int main() {
	std::cout << 
}