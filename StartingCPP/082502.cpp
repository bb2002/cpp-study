#include "pch.h"
#include <iostream>

namespace {
	void fun() {
		std::cout << "fun() ���� �Դϴ�." << std::endl;
	}
}

namespace Sample {
	void fun() {
		::fun();
		std::cout << "Sample::fun() �Դϴ�." << std::endl;
	}

	namespace Inner {
		void fun() {
			std::cout << "Sample::Inner::fun() �Դϴ�." << std::endl;
		}
	}
}

int main() {
	Sample::fun();
	Sample::Inner::fun();
	fun();
	::fun();
}