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

	std::cout << "SORT �� : ";
	for (i = 0; i < 10; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	// ���ٸ� ����� ����
	auto sorting = [](const void *left, const void *right) -> int {
		return (*((int*) right) - *((int*)left));
		//return (*((int*) left) - *((int*)right)); �������� ���� ���.
	};

	qsort(arr, 10, sizeof(int), sorting);
	std::cout << "SORT �� : ";
	for (i = 0; i < 10; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}