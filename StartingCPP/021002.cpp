#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex cout_mutex;

void in_thread(const char* name) {
	std::lock_guard<std::mutex> lock(cout_mutex);
	std::cout << name << " thread id " << std::this_thread::get_id() << std::endl;
}

int main() {
	std::cout << "CPU Count : " << std::thread::hardware_concurrency() << std::endl;
	std::thread t1(in_thread, "Thread1");
	std::thread t2 = std::thread(in_thread, "Thread2");
	std::thread t3([&](int param) {
		std::lock_guard<std::mutex> lock(cout_mutex);
		std::cout << "Thread3 : " << std::this_thread::get_id() << std::endl;
		for (int i = 0; i < param; ++i) {
			std::cout << "Thread3 params : " << i << std::endl;
		}
	}, 4);

	t1.join();
	t2.join();
	t3.join();
}