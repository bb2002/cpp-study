#include <iostream>
#include <string>

template <typename T>
T min(T a, T b) {
	return (a < b) ? a : b;
}

template <class Type>
Type max(Type a, Type b) {
	return (a < b) ? b : a;
}

int main() {
	std::cout << "�ִ밪 : " << max<double>(10, 16.5) << std::endl;
	std::cout << "�ִ밪 : " << max(3.5, 7.6) << std::endl;
	std::cout << "�ִ밪 : " << max<double>(3.5, 7.6) << std::endl;

	std::cout << "�ּҰ� : " << min('a', 'b') << std::endl;
	std::cout << "�ּҰ� : " << min<std::string>("Hello World!", "�ȳ��ϼ���") << std::endl;
}