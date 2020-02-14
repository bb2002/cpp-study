#include <iostream>
#include <numeric>
#include <vector>
#include <future>

int acc_block_worker(int* data, size_t size) {
	return std::accumulate(data, data + size, 0);
}

using int_futures = std::vector<std::future<int>>;

int_futures launch_workers(std::vector<int>& v) {
	int_futures futures;

	futures.push_back(std::async(std::launch::async, acc_block_worker, v.data(), v.size() / 2));
	futures.push_back(std::async(std::launch::async, acc_block_worker, v.data() + v.size() / 2, v.size() / 2));
	return futures;
}

int main() {
	std::vector<int> v{
		1,2,3,4,5,6,7,8,9,10
	};
	int_futures futures = launch_workers(v);

	int res1 = futures[0].get();
	int res2 = futures[1].get();
	std::cout << res1 << ", " << res2 << std::endl;
	std::cout << "RESULT : " << res1 + res2 << std::endl;
}