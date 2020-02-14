#include <iostream>

void A() {
	throw std::exception("그냥 일하기 싫습니다.");
}

void B() {
	A();
}

void C() noexcept {
	B();
}

int main() {
	try {
		bool ok = noexcept(C());
		if (!ok) {
			std::cout << "예외 안터질듯" << std::endl;
			C();
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}