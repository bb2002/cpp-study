#include <iostream>
#include <chrono>
#include <cmath>

unsigned int fibonachi(unsigned int i) {
	if (i < 2) {
		return i;
	}

	return fibonachi(i - 1) + fibonachi(i - 2);
}

using Chrono = std::chrono::steady_clock;

int main() {
	Chrono::time_point start = Chrono::now();
	std::cout << "RESULT : " << fibonachi(42) << std::endl;
	Chrono::time_point end = Chrono::now();

	std::chrono::duration<double> DefaultTime = end - start;
	std::cout << "피보나치 실행 시간 : " << DefaultTime.count() << "초" << std::endl;

	std::chrono::nanoseconds nano = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << "피보나치 나노 시간 : " << nano.count() << std::endl;

	std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(end - start);
	std::cout << "피보나치 초 : " << sec.count() << std::endl;

	std::chrono::minutes min = std::chrono::duration_cast<std::chrono::minutes>(end - start);
	std::cout << "피보나치 분 : " << min.count() << std::endl;
}