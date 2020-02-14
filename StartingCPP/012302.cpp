#include <iostream>
#include <unordered_set>
#include <set>
#include <iterator>
#include <string>

int main() {
	std::set<std::string> MySet;
	MySet.insert("Sisigami leona");
	MySet.insert("Hoshino mea");
	MySet.insert("Domyozi kokoa");

	std::unordered_multiset<std::string> ms;
	std::copy(MySet.begin(), MySet.end(), std::inserter(ms, ms.begin()));
	ms.insert(MySet.begin(), MySet.end());
	ms.insert("Set Contains");

	std::cout << "¹öÅ¶ ¼ö : " << ms.bucket_count() << std::endl;
	while (!ms.empty()) {
		std::cout << "   [" << *ms.begin() << "] => " << ms.bucket(*ms.begin()) << std::endl;
		ms.erase(ms.begin());
	}
}