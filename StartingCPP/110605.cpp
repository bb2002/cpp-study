#include <iostream>
#include <random>
#include <cstdlib>

int main() {
	int arr[10];
	int i;

	std::random_device rd;
	srand((unsigned) rd());
	for (i = 0; i < 10; ++i) {
		arr[i] = std::rand() % 1000;
	}

	std::cout << "SORT 전 : ";
	for (i = 0; i < 10; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	// 람다를 사용한 정렬
	auto sorting = [](const void *left, const void *right) -> int {
		return (*((int*) right) - *((int*)left));
		//return (*((int*) left) - *((int*)right)); 오름차순 정렬 방법.
	};

	qsort(arr, 10, sizeof(int), sorting);
	std::cout << "SORT 후 : ";
	for (i = 0; i < 10; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}