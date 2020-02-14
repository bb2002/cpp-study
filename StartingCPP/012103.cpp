#include <iostream>
#include <vector>
#include <deque>

typedef std::pair<std::string, int> Substruct;

int main() {
	std::vector<Substruct> MyYoutuber;
	MyYoutuber.push_back(std::make_pair("�ýð��� ������", 130000));
	MyYoutuber.emplace(MyYoutuber.begin(), "ȣ�ó�޾�", 79000);
	MyYoutuber.emplace_back("������ ���ھ�", 330000);

	std::deque<Substruct> Que;
	while (!MyYoutuber.empty()) {
		Que.push_back(MyYoutuber.back());
		MyYoutuber.pop_back();
	}

	std::cout << "Que �� ������ : " << std::endl;
	for (auto& item : Que) {
		std::cout << "NAME : " << item.first.data() << ", ���� : " << item.second << std::endl;
	}

	std::cout << "Vector �� ������" << std::endl;
	for (auto& item : MyYoutuber) {
		std::cout << "NAME : " << item.first.data() << ", ���� : " << item.second << std::endl;
	}
}