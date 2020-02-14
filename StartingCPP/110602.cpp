#include <iostream>

struct S2 {
	void fun(int a);
	int a;
};

void S2::fun(int a) {
	[&] {
		// 디폴트 -> 참조 캡처
	};
	[=] {
		// 디폴트 -> 값 캡처
	};
	[&, a] {
		// 디폴트 -> 참조, a 만 값 캡처.
	};
	[=, &a] {
		// 디폴트 -> 값, a 만 참조 캡처
	};

	[=] {
		this->a = a;
	};

	[&, this] {
		this->a = a;
		std::cout << "a=" << this->a << std::endl;
	}();
}

int main() {
	S2().fun(10);

	auto funa = [](int a) {
		std::cout << "정수 : " << a << std::endl;
	};

	auto glambda = [](auto a, auto b) -> bool {
		return a < b;
	};

	funa(300);
	std::cout << std::boolalpha << glambda(10, 31.141592) << std::endl;
}