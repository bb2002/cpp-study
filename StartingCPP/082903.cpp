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

	// const ��� �Լ�!
	void print() const {
		std::cout << "���� : " << account << ", ������ : " << name << std::endl;
		std::cout << "�ܾ� : " << balance << "��" << std::endl;
	}

	void deposit(int money) {
		balance -= money;
	}

	void withdraw(int money) {
		balance += money;
	}
};

int main() {
	Account* acc = new Account("34903202101010", "����", 10000);
	acc->withdraw(1000000);
	acc->print();
}