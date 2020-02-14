#include <iostream>
#include <iterator>
#include "Array.h"

int main() {
	Array<int> arr{1,2,3,4,56,7,8,9,1,10};

	std::cout << "distance(f, l) = "
		<< std::distance(arr.begin(), arr.end()) << "\n"
		<< "distance(l, f) = "
		<< std::distance(arr.end(), arr.begin()) << std::endl;

	auto vi = std::begin(arr);
	auto nx = std::next(vi, 2);
	std::cout << *vi << ", " << *nx << std::endl;

	auto prev = std::prev(nx, 1);
	std::cout << *prev << std::endl;

	std::advance(vi, 5);
	std::cout << *vi << std::endl;

	std::cout << "rev : ";
	Array<int>::reverse_iterator rb = std::rbegin(arr);
	while (rb != std::rend(arr)) {
		std::cout << *rb++ << std::endl;
	}

	std::cout << std::endl;
}