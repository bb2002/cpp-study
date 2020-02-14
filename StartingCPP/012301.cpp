#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <set>

typedef std::pair<std::set<std::string>::iterator, bool> Return;

int main() {
	std::set<std::string> mSet;
	mSet.insert("Hello");
	mSet.insert("World");
	Return rt1 = mSet.emplace("Leona");
	std::cout << std::boolalpha << *rt1.first << " INSERT OK : " << rt1.second << std::endl;

	Return rt2 = mSet.emplace("Leona");
	std::cout << std::boolalpha << *rt2.first << " INSERT OK : " << rt2.second << std::endl;

	std::cout << "mSet : ";
	for (auto& s : mSet) {
		std::cout << " " << s.c_str();
	}
	std::cout << std::endl;

	std::cout << "크기 : " << mSet.size() << std::endl;
	std::set<std::string>::iterator search = mSet.find("Leona");
	if (search != mSet.end()) {
		std::cout << "레오쨩을 찾음 :!: " << *search << std::endl;
	}
	else {
		std::cout << "레오쨩 없음" << std::endl;
	}
}