#include <iostream>
#include <string>

int main() {
	std::string str;
	std::cout << "str 기본 크기 : " << str.capacity() << std::endl;
	std::cout << "str 의 최대 크기 : " << str.max_size() << std::endl;

	str = "君を思う気持ち";
	std::cout << "str 할당 크기 : " << str.capacity() << std::endl;
	std::cout << "str 의 길이 : " << str.length() << std::endl;
	std::cout << str << std::endl;

	const std::string search = "気持ち";
	std::string::size_type s = str.find(search);
	if (std::string::npos != s) {
		// 찾음.
		std::cout << s << "에 있더라" << std::endl;
	}

	std::cout << str.replace(0, 3, search) << std::endl;
}