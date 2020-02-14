#include "pch.h"
#include <iostream>
#include <cassert>

extern "C" void handler(int);
extern "C" {
	int open(const char *pathname, int flags);
}

namespace MyNameSpace {
	class MyClass {
	public:
		static void MyFun();
	};
}

int main() {
	MyNameSpace::MyClass::MyFun();
}

namespace MyNameSpace {
	void MyClass::MyFun() {
		std::cout << "Hello world!" << std::endl;
	}
}