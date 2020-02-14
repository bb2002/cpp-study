#include <iostream>
#include <thread>
#include <chrono>

void new_thread() {
	std::cout << "new_thread()" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "new_thread() 종료" << std::endl;
}

void caller() {
	std::cout << "caller()" << std::endl;
	std::thread thread(new_thread);
	std::cout << "detach 전 " << thread.get_id() << std::endl;
	thread.detach();
	std::cout << "detach 후 " << thread.get_id() << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(3));
	if (thread.joinable()) {
		thread.join();
	}
	std::cout << "caller() 끝" << std::endl;
}

int main() {
	std::thread(caller).detach();
	std::chrono::system_clock::time_point StartTime = std::chrono::system_clock::now();
	std::chrono::seconds dura_sec(4);

	std::this_thread::sleep_until(StartTime + dura_sec);
	std::cout << "main() 끝" << std::endl;
}