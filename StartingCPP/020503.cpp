#include <iostream>
#include <chrono>
#include <thread>

void InThread(const char* name) {
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << name << " Thread id : " << std::this_thread::get_id() << std::endl;
}

int main() {
	std::cout << "CPU ÄÚ¾î ¼ö : " << std::thread::hardware_concurrency() << std::endl;
	std::thread thread1(InThread, "Thread1");

	std::thread thread2;
	thread2 = std::thread(InThread, "Thread2");

	std::thread thread3([&](int param) {
		std::cout << "Thread 3 from lambda " << std::this_thread::get_id() << std::endl;
		for (int i = 0; i < param; ++i) {
			std::cout << "called " << i << std::endl;
		}
	}, 4);

	thread1.join();
	thread2.join();
	thread3.join();
}