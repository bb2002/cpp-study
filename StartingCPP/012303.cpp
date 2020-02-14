#include <iostream>
#include <tuple>
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <iterator>

typedef std::tuple<std::string, std::string, int> Account;

void print(const Account& data) {
	std::string name;
	std::string account;
	int balance;

	std::tie(name, account, balance) = data;

	std::cout << name << "[!] 님의 " << account << "계좌에는..." << std::endl;
	std::cout << balance << "원의 잔고가 있다더라." << std::endl << std::endl;;
}

struct Compare {
	bool operator()(const Account& i, const Account& j) {
		return std::get<0>(i) < std::get<0>(j);
	}
};

struct KeyHash {
	std::size_t operator()(const Account& data) const {
		std::string name;
		std::string account;
		int balance;
		std::hash<std::string> hash;
		std::tie(name, account, balance) = data;

		return ((hash(account) ^ (hash(name) << 1)) >> 1) ^ (std::hash<int>()(balance) << 1);
	}
};

bool operator==(const Account& lhs, const Account& rhs) {
	return std::get<0>(lhs) == std::get<0>(rhs) && std::get<1>(lhs) == std::get<1>(rhs);
}

int main() {
	std::set<Account, Compare> accs = {
		std::make_tuple("볼봇", "349-0320201-01-010", 1200000),
		std::make_tuple("소라", "756-4689456456-112", 12001230),
		std::make_tuple("메아", "75619-654351-23462", 10000)
	};

	accs.insert(std::make_tuple("메아", "75619-654351-23462", 10000));

	std::cout << "set<Account, Compare> : " << std::endl;
	for (const auto& a : accs) {
		print(a);
	}

	std::unordered_set<Account, KeyHash> ms;
	ms.insert(Account("피아노", "4567456-786754654-454", 88888888));
	ms.emplace("기억", "67685434-237431-2131", 10);

	std::copy(accs.begin(), accs.end(), std::inserter(ms, ms.begin()));
	ms.insert(std::make_tuple("메아", "75619-654351-23462", 20000));
	std::cout << "unordered_set<Account, KeyHash> : " << std::endl;
	for (const auto& a : ms) {
		print(a);
	}
}