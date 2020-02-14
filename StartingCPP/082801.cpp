#include "pch.h"
#include <iostream>

struct Something {
	static int s_value;			// ���� ���
	static int getSValue() {	// ���� ��� �Լ�
		return s_value;
	}

	int value;
	int value2;
	std::string message;
	int getValue() {
		return value2;
	}

	void print() {
		std::cout << message.data() << std::endl;
	}
};

// ���� �ɹ� ���� �ʱ�ȭ.
int Something::s_value = 10;

int main() {
	std::cout << "svalue : " << Something::getSValue() << std::endl;

	// ����ü �ʱ�ȭ
	Something s = { 100, 200, "Hello World!" };
	std::cout << "value : " << s.getValue() << std::endl;
	s.print();

	// ����/�Ϲ� �ɹ��� ȣ��
	std::cout << "svalue : " << s.getSValue() << ", value : " << s.getValue() << std::endl;
}