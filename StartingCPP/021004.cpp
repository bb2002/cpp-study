#include <iostream>
#include <vector>
#include <thread>
#include <numeric>

void acc_block_worker(int* data, size_t size, int* result) {
	for (int i = 0; i < size; ++i) {
		*result += *(data + 1);
	}
}

int main() {
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	int result1 = 0;
	int result2 = 0;

	std::thread worker(acc_block_worker, v.data(), v.size(), &result1);
	worker.join();

	std::thread worker2(acc_block_worker, v.data(), v.size(), &result2);
	worker2.join();


	int a;
	std::accumulate(1, 100, &a);
	std::cout << "a" << a << std::endl;

	printf("%d %d : %d", result1, result2, result1 + result2);
}