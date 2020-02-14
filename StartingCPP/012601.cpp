#include <iostream>
#include <map>
#include <string>
#include <unordered_map>


int main() {
	std::map<int, std::string> Employees;

	Employees[201026] = "넵튠";
	Employees[201027] = "느와르";

	Employees.insert(std::pair<int, const char*>(201028, "시시가미 레오나"));
	Employees.insert(std::map<int, const char*>::value_type(201029, "토야마 카스미"));
	Employees.insert(std::make_pair(201030, "미나토 유키나"));

	std::cout << "201026 : " << Employees[201026] << std::endl;
	std::cout << "201027 : " << Employees[201027] << std::endl;
	std::cout << "SIZE : " << Employees.size() << std::endl;


	typedef std::unordered_multimap<std::string, int> Substruct;
	Substruct youtubers;

	for (std::map<int, std::string>::iterator iter = Employees.begin(); iter != Employees.end() ; ++iter) {
		std::cout << "[" << iter->first << "] " << iter->second << "..." << std::endl;
		youtubers.insert(std::make_pair(iter->second, iter->first));
	}

	std::cout << "MOVE OK....." << std::endl;

	youtubers.emplace("호시노 메아", 72300);
	youtubers.emplace("호시노 메아", 723000);
	youtubers.emplace("호시노 메아", 7230000);
	std::cout << "유튜버 목록 : " << std::endl;
	for (Substruct::iterator iter = youtubers.begin(); iter != youtubers.end(); ++iter) {
		std::cout << "[" << iter->first << "] => " << iter->second << std::endl;
	}

	std::cout << "find 메아...." << std::endl;
	std::pair<Substruct::iterator, Substruct::iterator> mea = youtubers.equal_range("호시노 메아");
	for (Substruct::iterator iter = mea.first; iter != mea.second; ++iter) {
		std::cout << "[" << iter->first << "] => " << iter->second << std::endl;
	}

	youtubers.clear();
	Employees.clear();
}