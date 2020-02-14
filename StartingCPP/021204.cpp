#include <iostream>
#include <future>
#include <thread>
#include <numeric>
#include <vector>
#include <functional>

using It = std::vector<int>::iterator;

std::future<int> launch(It first, It last) {
	std::packaged_task<int(It, It)> task([](It first, It last) {
		return std::accumulate(first, last, 0);
	});
	std::future<int> result = task.get_future();
	std::thread work_thread(std::move(task), first, last);
	work_thread.detach();
	return result;
}

int main() {
	int total = 0;
	std::vector<int> numbers = {
		1,2,3,4,5,6,7,8,9,10
	};
	std::future<int> s[2];
	s[0] = launch(numbers.begin(), numbers.begin() + 6);
	s[1] = launch(numbers.begin() + 6, numbers.end());

	total = s[0].get() + s[1].get();
	std::cout << "гу╟Х : " << total << std::endl;
}