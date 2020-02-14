#include <iostream>

struct S2 {
	void fun(int a);
	int a;
};

void S2::fun(int a) {
	[&] {
		// ����Ʈ -> ���� ĸó
	};
	[=] {
		// ����Ʈ -> �� ĸó
	};
	[&, a] {
		// ����Ʈ -> ����, a �� �� ĸó.
	};
	[=, &a] {
		// ����Ʈ -> ��, a �� ���� ĸó
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
		std::cout << "���� : " << a << std::endl;
	};

	auto glambda = [](auto a, auto b) -> bool {
		return a < b;
	};

	funa(300);
	std::cout << std::boolalpha << glambda(10, 31.141592) << std::endl;
}