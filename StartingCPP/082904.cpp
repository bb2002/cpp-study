#include "pch.h"
#include <iostream>

int main() {
	const char *cc = "���ڿ� �Է� �� ���ƴ� ������� �ʳ���.";
	std::string str;

	str = cc;		// �ð���
	std::cout << "str : " << str.data() << std::endl;

	str += " �� ���ڿ��� �ٿ����� ���� �����";

	std::cout << "str : " << str.data() << std::endl;

	std::cout << "size : " << str.length() << std::endl;
}