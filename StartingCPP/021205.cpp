#include <iostream>
#include <future>
#include <thread>
#include <vector>

using Chrono = std::chrono::steady_clock;
using int_futures = std::vector<std::future<int>>;

inline std::future<int> launch(int a) {
	std::packaged_task<int(int)> task([](int s) {
		std::this_thread::sleep_for(std::chrono::milliseconds(s));
		return s;
	});

	std::future<int> result = task.get_future();
	std::thread work(std::move(task), a);
	work.detach();
	return result;
}

int main() {
	int_futures futures;
	Chrono::time_point start = Chrono::now();

	for (int i = 0; i < 10000; ++i) {
		futures.push_back(launch(100));
	}

	for (int i = 0; i < 10000; ++i) {
		if ((i % 100) == 0) {
			std::cout << ".";
		}

		futures[i].wait();
	}

	std::cout << std::endl;

	Chrono::time_point end = Chrono::now();

	std::chrono::milliseconds sec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "걸린 시간 : " << sec.count() << std::endl;
}