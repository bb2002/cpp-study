#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
static int rank = 1;

void print(int id) {
	std::unique_lock<std::mutex> u_mtx(mtx);

	cv.wait(u_mtx);
	std::cout << ++rank << ". thread" << id << std::endl;
}

int main() {
	std::thread threads[10];

	for (int i = 0; i < 10; ++i) {
		threads[i] = std::thread(print, i);
	}
	std::cout << "10개 스레드 준비..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(10));

	{
		std::unique_lock<std::mutex> u_mtx(mtx);
		cv.notify_all();
	}

	for (auto& a : threads) {
		a.join();
	}
}