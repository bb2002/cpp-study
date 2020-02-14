#include <iostream>
#include <list>
#include <iomanip>

typedef std::pair<std::string, int> Youtuber;

template<typename T>
void print(const char* str, std::list<T>& MyList) {
	std::cout << str << std::endl;
	for (auto item : MyList) {
		std::cout << "�̸� : " << item.first.data() << " ������ : " << item.second << std::endl;
	}

	std::cout << std::endl;
}

int main() {
	std::list<Youtuber> MyList;

	MyList.push_front(std::make_pair("�ýð��� ������", 130000));
	MyList.push_back(std::make_pair("ȣ�ó� �޾�", 79000));

	Youtuber Kotone = std::make_pair("���� �����", 237000);
	MyList.insert(MyList.begin(), Kotone);
	MyList.insert(MyList.begin(), Kotone);
	MyList.emplace(++MyList.begin(), "������ ���ھ�", 330000);
	MyList.emplace_front("�ƿ��� ����", 260000);
	MyList.emplace_back("Ű� ����", 28700000);

	print<Youtuber>("MyLIST : ", MyList);

	// ������ �� ����
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