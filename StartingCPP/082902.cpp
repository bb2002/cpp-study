#include "pch.h"
#include <iostream>

int getSize() {
	int data;
	std::cin >> data;
	return data;
}

int main() {
	const int len = getSize();
	char* str = new char[len];

	std::cin >> str;

	std::cout << len << ", " << str << std::endl;

	char buf[100];
	const char * yourbuf = "HelloWorld";	// �������� �� ���� const
	char * const aptr = buf;				// ������ ������ const

	*aptr = 'a';

	int * const ptr = 0x000000;
	int const * ptr2 = 0x000000;


	int ddata = 1000;
	const int * const ddataptr = &ddata;		// ����Ű�� ���� ���, ������ ������ ���.
}