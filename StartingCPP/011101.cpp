#include <iostream>
#include <string>

int main() {
	std::string s;
	s.assign(10, '=');
	std::cout << s.data() << std::endl;

	s = "Hello sisigami leona!";
	std::string sisigami = s.substr(0, s.length() - 1);
	std::cout << sisigami.data() << std::endl;

	const char* l = "leona";
	const char* k = "leona";
	if (strcmp(l, k) == 0) {
		std::cout << l << ", " << k << "�� ����." << std::endl;
	}
	else {
		std::cout << l << ", " << k << "�� �Ȱ���." << std::endl;
	}

	std::cout << s.data() << std::endl;
	std::string str = std::to_string(3141592);
	std::cout << str << std::endl;
	std::cout << std::stoi(str) + 1 << std::endl;

	std::cout << "=-=-=-=-=-=-=-=-=-=" << std::endl;
	std::string a = "3 15 15 92";
	std::size_t fail_pos;
	int b = std::stoi(a, &fail_pos);
	std::cout << "��ȯ�� : " << b << std::endl;
	std::cout << "��ȯ ���� : " << a.substr(fail_pos);
}