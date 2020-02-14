#include <iostream>

void A() {
	throw std::exception("�׳� ���ϱ� �Ƚ��ϴ�.");
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
			std::cout << "���� ��������" << std::endl;
			C();
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}