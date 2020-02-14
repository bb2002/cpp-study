#include <iostream>
#include <map>
#include <string>
#include <unordered_map>


int main() {
	std::map<int, std::string> Employees;

	Employees[201026] = "��ƪ";
	Employees[201027] = "���͸�";

	Employees.insert(std::pair<int, const char*>(201028, "�ýð��� ������"));
	Employees.insert(std::map<int, const char*>::value_type(201029, "��߸� ī����"));
	Employees.insert(std::make_pair(201030, "�̳��� ��Ű��"));

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

	youtubers.emplace("ȣ�ó� �޾�", 72300);
	youtubers.emplace("ȣ�ó� �޾�", 723000);
	youtubers.emplace("ȣ�ó� �޾�", 7230000);
	std::cout << "��Ʃ�� ��� : " << std::endl;
	for (Substruct::iterator iter = youtubers.begin(); iter != youtubers.end(); ++iter) {
		std::cout << "[" << iter->first << "] => " << iter->second << std::endl;
	}

	std::cout << "find �޾�...." << std::endl;
	std::pair<Substruct::iterator, Substruct::iterator> mea = youtubers.equal_range("ȣ�ó� �޾�");
	for (Substruct::iterator iter = mea.first; iter != mea.second; ++iter) {
		std::cout << "[" << iter->first << "] => " << iter->second << std::endl;
	}

	youtubers.clear();
	Employees.clear();
}