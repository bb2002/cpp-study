#include <iostream>
#include <list>
#include <iomanip>

typedef std::pair<std::string, int> Youtuber;

template<typename T>
void print(const char* str, std::list<T>& MyList) {
	std::cout << str << std::endl;
	for (auto item : MyList) {
		std::cout << "이름 : " << item.first.data() << " 구독자 : " << item.second << std::endl;
	}

	std::cout << std::endl;
}

int main() {
	std::list<Youtuber> MyList;

	MyList.push_front(std::make_pair("시시가미 레오나", 130000));
	MyList.push_back(std::make_pair("호시노 메아", 79000));

	Youtuber Kotone = std::make_pair("텐진 코토네", 237000);
	MyList.insert(MyList.begin(), Kotone);
	MyList.insert(MyList.begin(), Kotone);
	MyList.emplace(++MyList.begin(), "도묘지 코코아", 330000);
	MyList.emplace_front("아오이 후지", 260000);
	MyList.emplace_back("키즈나 아이", 28700000);

	print<Youtuber>("MyLIST : ", MyList);

	// 구독자 순 정렬
	auto s = [](Youtuber& l, Youtuber& r) -> bool {
		return l.second < r.second;
	};
	MyList.sort(s);
	print<Youtuber>("MyLIST SORTED! : ", MyList);

	auto u = [](Youtuber& l, Youtuber& r) -> bool {
		return l.first == r.first && l.second == r.second;
	};
	MyList.unique(u);
	print<Youtuber>("MyLIST UNIQUE! : ", MyList);

	MyList.pop_front();
	MyList.erase(MyList.begin());
	print<Youtuber>("MyLIST pop_front() & erase() : ", MyList);
}