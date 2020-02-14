#include <iostream>
#include <mutex>
#include <atomic>

#define MAX_THREAD 100

std::mutex mtx_lock;
int global = 0;

void function(int func, int loops) {

	for (int i = 0; i < loops; ++i) {
		mtx_lock.lock();
		global++;
		mtx_lock.unlock();

		if ((i % 10) == 0) {
			std::this_thread::yield();
		}
	}



	std::cout << func << ". " << "GLOBAL : " << global << std::endl;
}

int main() {
	std::thread threads[MAX_THREAD];

	for (int i = 0; i < MAX_THREAD; ++i) {
		threads[i] = std::thread(function, i, 10000);
	}

	for (int i = 0; i < MAX_THREAD; ++i) {
		threads[i].join();
	}

	std::cout << "RESULT : " << global << std::endl;
}