#include <iostream>
#include <vector>
#include <deque>

typedef std::pair<std::string, int> Substruct;

int main() {
	std::vector<Substruct> MyYoutuber;
	MyYoutuber.push_back(std::make_pair("시시가미 레오나", 130000));
	MyYoutuber.emplace(MyYoutuber.begin(), "호시노메아", 79000);
	MyYoutuber.emplace_back("도묘지 코코아", 330000);

	std::deque<Substruct> Que;
	while (!MyYoutuber.empty()) {
		Que.push_back(MyYoutuber.back());
		MyYoutuber.pop_back();
	}

	std::cout << "Que 의 데이터 : " << std::endl;
	for (auto& item : Que) {
		std::cout << "NAME : " << item.first.data() << ", 구독 : " << item.second << std::endl;
	}

	std::cout << "Vector 의 데이터" << std::endl;
	for (auto& item : MyYoutuber) {
		std::cout << "NAME : " << item.first.data() << ", 구독 : " << item.second << std::endl;
	}
}