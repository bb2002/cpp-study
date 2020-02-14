#include <iostream>
#include <vector>

int main() {
	std::vector<int> myvec(5);
	int* p = myvec.data();

	*p = 10;
	for (int i = 1; i < myvec.size(); ++i) {
		p[i] = p[i - 1] * i;
	}
	*(++p) += 20;

	std::cout << "myvec �� ������ : " << std::endl;
	for (int i = 0; i < myvec.size(); ++i) {
		std::cout << " " << myvec[i];
	}
	std::cout << std::endl;

	std::vector<std::string> mystr(5);
	std::string* s = mystr.data();

	*s = "�ȳ� ��ī��";
	*(s + 1) = "�ȳ� ������";
	*(s + 2) = "�ȳ� �޾�";
	*(s + 3) = "�ȳ� ���ھ�";

	std::cout << "mystr������ : " << std::endl;
	for (auto& a : mystr) {
		std::cout << a.c_str() << ", ";
	}

	std::cout << std::endl;
}