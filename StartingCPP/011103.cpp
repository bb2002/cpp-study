#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

int main() {
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t unix_timestamp = std::chrono::system_clock::to_time_t(now);
	std::cout << "unix : " << unix_timestamp << std::endl;
	std::cout << "현재 시간 : " << std::put_time(std::localtime(&unix_timestamp), "%c %Z") << std::endl;

	std::time_t kinou = std::chrono::system_clock::to_time_t(now + std::chrono::hours(24));
	std::cout << "24시간 전 : " << std::put_time(std::localtime(&kinou), "%F %H:%M:%S %p") << std::endl;
}