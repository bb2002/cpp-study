#include <iostream>
#include <vector>
#include <future>

using Chrono = std::chrono::steady_clock;
using int_futures = std::vector<std::future<int>>;

int main() {
	auto plus = [](int a) -> int{
		std::this_thread::sleep_for(std::chrono::milliseconds(a));
		return a;
	};

	int_futures futures;
	Chrono::time_point start = Chrono::now();

	for (int i = 0; i < 10000; ++i) {
		futures.push_back(std::async(std::launch::async, plus, 100));
	}

	for (int i = 0; i < 10000; ++i) {
		if ((i % 100) == 0) {
			std::cout << ".";
		}

		futures[i].wait();
	}


	std::cout << std::endl << std::endl;

	Chrono::time_point end = Chrono::now();
	std::chrono::milliseconds sec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "실행 시간 : " << sec.count() << std::endl;
}