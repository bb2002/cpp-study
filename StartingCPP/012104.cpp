#include <iostream>
#include <forward_list>
#include <iomanip>

template<typename T>
void print(const char* str, std::forward_list<T>& MyList) {
	std::cout << str << std::endl;
	for (auto item : MyList) {
		std::cout << item << " ";
	}

	std::cout << std::endl;
}

int main() {
	std::forward_list<int> MyList1 = { 3,5,1,8,500 };
	auto it = MyList1.insert_after(MyList1.begin(), 2, 20);
	print<int>("MyList1 >> ", MyList1);
	
	std::forward_list<int> MyList2 = { 3,5,1,8,500 };
	print<int>("MyList2 >> ", MyList2);

	std::cout << "splice_after run" << std::endl;
	MyList2.splice_after(MyList2.before_begin(), MyList1, it);
	print<int>("MyList1 >> ", MyList1);
	print<int>("MyList2 >> ", MyList2);

	std::forward_list<int> MyList3(MyList1);
	std::forward_list<int> MyList4(MyList2);

	MyList3.sort(std::less<int>());
	MyList4.sort(std::less<int>());

	MyList3.merge(MyList4);
	print<int>("MyList3 >> ", MyList3);
	print<int>("MyList4 >> ", MyList4);
}