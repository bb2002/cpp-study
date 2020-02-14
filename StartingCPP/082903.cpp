#include "pch.h"
#include <iostream>

class Account {
	char account[20];
	char name[20];
	int balance;

public:
	Account(const char *id, const char *n, int bal) {
		strcpy_s(account, strlen(id) + 1, id);
		strcpy_s(name, strlen(n) + 1, n);
		this->balance = bal;
	}

	// const ¸â¹ö ÇÔ¼ö!
	void print() const {
		std::cout << "°èÁÂ : " << account << ", ¼ÒÀ¯ÀÚ : " << name << std::endl;
		std::cout << "ÀÜ¾× : " << balance << "¿ø" << std::endl;
	}

	void deposit(int money) {
		balance -= money;
	}

	void withdraw(int money) {
		balance += money;
	}
};

int main() {
	Account* acc = new Account("34903202101010", "º¼º¿", 10000);
	acc->withdraw(1000000);
	acc->print();
}