#include "pch.h"
#include <iostream>

namespace {
	void fun() {
		std::cout << "fun() 무명 입니다." << std::endl;
	}
}

namespace Sample {
	void fun() {
		::fun();
		std::cout << "Sample::fun() 입니다." << std::endl;
	}

	namespace Inner {
		void fun() {
			std::cout << "Sample::Inner::fun() 입니다." << std::endl;
		}
	}
}

int main() {
	Sample::fun();
	Sample::Inner::fun();
	fun();
	::fun();
}