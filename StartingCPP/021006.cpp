#include <iostream>
#include <future>

int main() {
	auto f = []() {
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "Work end." << std::endl;
	};

	auto handle = std::async(f);
	std::cout << "ºñµ¿±â called" << std::endl;
	handle.wait();
}