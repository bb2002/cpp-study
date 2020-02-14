#include <iostream>
#include <vector>

int main() {
	std::vector<int> first;
	std::vector<int> second(4, 100);
	std::vector<int> third(second.begin(), second.end());
	std::vector<int> forth(third);

	forth.resize(10);
	std::cout << "forth.capacity : " << forth.capacity() << std::endl;

	std::cout << "forth.size : " << forth.size() << std::endl;
	for (auto& i : forth) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	forth.clear();
	std::cout << "clear() -> forth.capacity : " << forth.capacity() << std::endl;
	forth.shrink_to_fit();
	std::cout << "shrink_to_fit() -> forth.capacity : " << forth.capacity() << std::endl;

}