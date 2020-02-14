#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

class Account {
private:
	char *_id;
	char *name;
	int balance;

public:
	Account(const char* _id, const char* name, int balance) : _id(new char[strlen(_id) + 1]), name(new char[strlen(name) + 1]), balance(balance) {
		strcpy_s(this->_id, strlen(_id) + 1, _id);
		strcpy_s(this->name, strlen(name) + 1, name);
		this->balance = balance;

		std::cout << "Account(~) called." << std::endl;
	}

	void echo() {
		std::cout << name << " ���� " << _id << " ���´� " << balance << "�� �ִ�." << std::endl;
	}

	void deposit(int money) {
		balance += money;
		std::cout << _id << " ���¿� " << money << "�����Ͽ� " << balance << "�� �ִ�." << std::endl;
	}

	void  withdraw(int money) {
		balance -= money;
		std::cout << _id << " ���¿� " << money << "�������� " << balance << "�� �ִ�." << std::endl;
	}

	~Account() {
		delete[] _id;
		delete[] name;
		std::cout << "~Account(~) called." << std::endl;
	}
};

int main() {
	Account *ballbot = new Account("349-032021-01-010", "����", 798570);
	if (ballbot != nullptr) {
		{
			Account babo("123-123456-12-123", "�ٺ�", 85500);
			babo.withdraw(50000);
			ballbot->deposit(50000);

			ballbot->echo();
			babo.echo();
		}
	}

	delete ballbot;
}