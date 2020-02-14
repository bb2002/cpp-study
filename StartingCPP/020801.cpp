#include <iostream>
#include <chrono>
#include <thread>

#define MAX_THREAD 9

thread_local int local;
int global = 0;

void unsafe_func(int func, int loops) {
	for (int i = 0; i < loops; ++i) {
		++global;
	}

	std::cout << func << " fun called " << loops << std::endl;
}

void save_func_1(int func, int loops) {
	local = global;
	for (int i = 0; i < loops; ++i) {
		++local;
	}

	global += local;
	std::cout << func << " fun called " << loops << std::endl;
}

int main() {
	std::thread threads[MAX_THREAD];

	for (int i = 0; i < MAX_THREAD; ++i) {
		threads[i] = std::thread(save_func_1, i, 100000);

	}

	for (int i = 0; i < MAX_THREAD; ++i) {
		threads[i].join();
	}

	std::cout << "RESULT : " << global << std::endl;
}