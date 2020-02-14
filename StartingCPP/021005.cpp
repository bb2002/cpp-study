#include <iostream>
#include <vector>
#include <future>

int acc_block_worker(int* data, size_t size) {
	int result = 0;
	for (int i = 0; i < size; ++i) {
		result += *(data + i);
	}
	std::this_thread::sleep_for(std::chrono::seconds(5));

	return result;
}

int main() {
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };

	std::future<int> fut = std::async(std::launch::async, acc_block_worker, v.data(), v.size());
	std::cout << "대기 중..." << std::endl;
	std::cout << "결과 : " << fut.get() << std::endl;
}