#include <iostream>
#include <atomic>
#include <thread>

#define MAX_THREAD 20

std::atomic<int> global;

void safe_func(int func, int loops) {
	for (int i = 0; i < loops; ++i) {
		global++;
	}
}

int main() {
	std::thread thread[MAX_THREAD];
	global.store(0, std::memory_order_relaxed);

	for (int i = 0; i < MAX_THREAD; ++i) {
		thread[i] = std::thread(safe_func, i, 1000000);
	}

	for (int i = 0; i < MAX_THREAD; ++i) {
		thread[i].join();
	}

	std::cout << "OK. " << global.load() << std::endl;
}