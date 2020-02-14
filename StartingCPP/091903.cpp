#include <iostream>

template<typename First>
void print(const First first) {
	std::cout << first << std::endl;
}

template <typename First, typename... Types>
void print(const First first, const Types... types) {
	std::cout << first << ", ";
	print(types...);
}

int main() {
	print(3.141592);
	print(1, 2);
	print(1, 2, "»ï", "4", '5', 6.141592);
}