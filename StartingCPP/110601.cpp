#include <iostream>

int main() {
	auto funa = [] {
		std::cout << "Hello Lambda!" << std::endl;
	};

	funa();

	auto funb = [](int a) noexcept -> int {
		std::cout << "Hello Lambda : " << a << std::endl;
		return 0;
	};

	funb(3140);
}