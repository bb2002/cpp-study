#include "pch.h"
#include <iostream>

struct Something {
	static int s_value;			// 정적 멤버
	static int getSValue() {	// 정적 멤버 함수
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

// 정적 맴버 변수 초기화.
int Something::s_value = 10;

int main() {
	std::cout << "svalue : " << Something::getSValue() << std::endl;

	// 구조체 초기화
	Something s = { 100, 200, "Hello World!" };
	std::cout << "value : " << s.getValue() << std::endl;
	s.print();

	// 정적/일반 맴버의 호출
	std::cout << "svalue : " << s.getSValue() << ", value : " << s.getValue() << std::endl;
}