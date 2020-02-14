#include <iostream>

struct Account {
	Account(const char* Name, const char* Id, int bal) : UserName(new char[strlen(Name) + 1]), CardID(new char[strlen(Id) + 1]), bal(bal) {

	}

	void print() {
		std::cout << UserName << ", " << CardID << " : " << bal << std::endl;
	}

private:
	char* UserName;
	char* CardID;
	int bal;
};

int main() {
	Account* Acc = new Account("Ballbot", "349-032021-01-010", 10000);
}