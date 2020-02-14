#include <iostream>
#include <thread>
#include <string>
#include <atomic>

std::atomic<std::string*> ptr;
int data;

void producer() {
	std::string* p = new std::string("Hello Leona!");
	data = 42;

	std::atomic_store_explicit(&ptr, p, std::memory_order_release);
}

void consumer() {
	std::string* p2 = nullptr;

	while (!(p2 = std::atomic_load_explicit(&ptr, std::memory_order_acquire))) {
		std::this_thread::yield();
	}

	std::cout << "CONSUMER : " << *p2 << std::endl;
}

int main() {
	std::thread t1(producer);
	std::thread t2(consumer);
	t1.join(); t2.join();
}