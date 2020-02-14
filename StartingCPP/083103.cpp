#include <iostream>

double Account = 15.37;		// Account 변수는 double타입의 전역 변수.

class Account {
public:
	Account(double initdata) : balance(initdata) {

	}

	double GetBalance() {
		return balance;
	}

private:
	double balance = 0.0;
};

int main() {
	class Account a(Account);
	std::cout << a.GetBalance() << std::endl;
}