#include <iostream>

template <typename T, typename U = T>
T min(T a, U b) {
	return (a < b) ? a : b;
}

int main() {
	std::cout << "�ּ� : " << min(10, 16.5) << std::endl;
	std::cout << "�ּ� : " << min<double>(10.5, 22.3) << std::endl;
	std::cout << "�ּ� : " << min<int, double>(10, 3.141592) << std::endl;
} 