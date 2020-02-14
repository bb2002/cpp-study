#include <iostream>

int func(int);

int main() {
	int a = 0;
	a++;

	{	// 새로운 지역 범위
		int x = 1;
		x = 42;

		int a = 10;	// 이 지역의 a 변수
		std::cout << a << std::endl;		// 지역 a 출력 (혼란인데요?)
	}	// x, a 소멸.

	{
		//int z = x;	 안됩니다.
		std::cout << a << std::endl;		// a 출력 가능.
	}

	func(2);
}

int func(int n) {
	{
		if (n == 2)
			goto label;

		{
		label:
			int n = 20;		// 지역 변수 n
			++n;
			std::cout << "n :: " << n << std::endl;
		}
	}

	int a = ++n;
	std::cout << a << std::endl;
	return a;
}