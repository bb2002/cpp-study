#include <iostream>
#include <future>
#include <thread>
#include <numeric>
#include <vector>
#include <functional>

void acc(
	std::vector<int>::iterator first,
	std::vector<int>::iterator last,
	std::promise<int>&& acc_promise) {
	int sum = std::accumulate(first, last, 0);
	acc_promise.set_value(sum);
}

std::future<int> launch(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	std::promise<int> acc_promise;
	std::future<int> result = acc_promise.get_future();
	std::thread work_thread(acc, first, last, std::move(acc_promise));
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
	s[1] = launch(numbers.begin()+6, numbers.end());

	int result = s[0].get() + s[1].get();
	std::cout << result << std::endl;
}