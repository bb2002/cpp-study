#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <string>
#include "Array.h"

typedef std::tuple<std::string, std::string, int> Account;

void print(Account& val) {
	std::string account;
	std::string name;
	int bal;
	std::tie(account, name, bal) = val;

	std::cout << "소유 : " << account << ", " << name << " 돈 : " << bal << std::endl;
}

bool compare(const Account& l, const Account& r) {
	return std::get<2>(l) < std::get<2>(r);
}

int main() {
	Array<Account> array = {
		std::make_tuple("349-032021-01-010", "시시가미", 100000),
		std::make_tuple("348-032021-01-010", "호시노", 12000),
		std::make_tuple("347-032021-01-010", "도묘지", 180000)
	};

	Account lee("123-456-789012", "이순신", 200);
	Account kim("316-246448431", "김유신", 20000);

	std::string name;
	int bal;
	std::tie(std::ignore, name, bal) = lee;
	std::cout << name << ", " << bal << std::endl;

	auto tups = std::tuple_cat(lee, kim);
	std::cout << "VAL1 : " << std::get<0>(tups) << ", " << std::get<1>(tups) << ", " << std::get<2>(tups) << std::endl;
	std::cout << "VAL2 : " << std::get<3>(tups) << ", " << std::get<4>(tups) << ", " << std::get<5>(tups) << std::endl;

	array.push_back(lee);
	array.push_back(kim);
	array.push_back(std::forward_as_tuple("348-41641-134131", "개쩐데", 10000000));

	std::sort(array.begin(), array.end(), compare);
	for (auto& a : array) {
		print(a);
	}
}