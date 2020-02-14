#include "pch.h"
#include <iostream>

int main() {
	const char *cc = "문자열 입력 와 미쳤다 대단하지 않나요.";
	std::string str;

	str = cc;		// 씹가능
	std::cout << "str : " << str.data() << std::endl;

	str += " 와 문자열이 붙여졌어 정말 대단해";

	std::cout << "str : " << str.data() << std::endl;

	std::cout << "size : " << str.length() << std::endl;
}