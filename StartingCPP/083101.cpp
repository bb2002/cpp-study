#include <iostream>

int func(int);

int main() {
	int a = 0;
	a++;

	{	// ���ο� ���� ����
		int x = 1;
		x = 42;

		int a = 10;	// �� ������ a ����
		std::cout << a << std::endl;		// ���� a ��� (ȥ���ε���?)
	}	// x, a �Ҹ�.

	{
		//int z = x;	 �ȵ˴ϴ�.
		std::cout << a << std::endl;		// a ��� ����.
	}

	func(2);
}

int func(int n) {
	{
		if (n == 2)
			goto label;

		{
		label:
			int n = 20;		// ���� ���� n
			++n;
			std::cout << "n :: " << n << std::endl;
		}
	}

	int a = ++n;
	std::cout << a << std::endl;
	return a;
}