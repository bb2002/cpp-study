#include <iostream>
#include <future>
#include <thread>

int main() {
	// future ��� �ϴ� ���
	std::future<int> f1 = std::async(std::launch::async, []() {
		return 1;
	});

	std::promise<int> p;
	std::future<int> f2 = p.get_future();
	std::thread([](std::promise<int>&& p) {
		p.set_value(2);
	}, std::move(p)).detach();

	std::packaged_task<int()> task([]() { return 3; });
	std::future<int> f3 = task.get_future();
	std::thread(std::move(task)).detach();

	std::cout << "..." << std::endl;
	f1.wait();
	f2.wait();
	f3.wait();
	std::cout << "��� : " << f1.get() << ", " << f2.get() << ", " << f3.get() << std::endl;
}