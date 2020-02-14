#include <iostream>

class Account {
public:
	char* AccountID;
	char* Name;
	int balance;

public:
	void Print() {
		std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl;
		std::cout << "���� : " << this->AccountID << std::endl;
		std::cout << "�̸� : " << this->Name << std::endl;
		std::cout << "�ܰ� : " << this->balance << std::endl;
	}

	void deposit(int money) {
		balance += money;
	}

	void withdraw(int money) {
		balance -= money;
	}
};

Account* OpenAccount(const char* Id, const char* Name, int Balance) {
	Account* NewAccount = new Account();
	if (NewAccount == nullptr) return nullptr;

	// Data Copy.
	char* NewId = new char[strlen(Id) + 1];
	char* NewName = new char[strlen(Name) + 1];
	strcpy_s(NewId, strlen(Id) + 1, Id);
	strcpy_s(NewName, strlen(Name) + 1, Name);

	NewAccount->AccountID = NewId;
	NewAccount->Name = NewName;
	NewAccount->balance = Balance;

	return NewAccount;
}

void CloseAccount(Account* CurrentAccount) {
	std::cout << "Account �� ���� �մϴ�...." << std::endl;
	delete[] CurrentAccount->AccountID;
	delete[] CurrentAccount->Name;
	delete CurrentAccount;
	std::cout << "Account �� ���ŵǾ����ϴ�." << std::endl;
}

int main() {
	Account* BallbotAcc =	OpenAccount("349-032021-01-010", "����", 1000000);
	Account* SaltyPieAcc =	OpenAccount("311-0513151-01-222", "§ ����", 100000);

	SaltyPieAcc->withdraw(7500);
	BallbotAcc->deposit(7500);

	SaltyPieAcc->Print();
	BallbotAcc->Print();

	CloseAccount(BallbotAcc);
	CloseAccount(SaltyPieAcc);
}