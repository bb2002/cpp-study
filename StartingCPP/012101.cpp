#include <iostream>
#include <algorithm>
#include <deque>

int main() {
	std::deque<int> que = { 7,5,16,8 };
	{
		que.emplace_back(1);
		que.emplace_back(2);
	}

	std::cout << "deque size : " << que.size() << std::endl;
	for (int i = 0; i < que.size(); ++i) {
		std::cout << que[i] << ", ";
	}
	std::cout << std::endl;

	int* var = &que[3];
	std::cout << "var = " << *var << std::endl;
	*var = 3141592;

	for (int i = 0; i < 8; ++i) {
		que.push_back(i * i * i);
	}

	std::deque<int>::iterator itr = que.begin();
	while (itr != que.end()) {
		std::cout << *itr << ", ";
		itr++;
	}
	std::cout << std::endl;

	std::cout << "지워진다 : " << que[2] << std::endl;
	que.erase(que.begin() + 2);

	std::deque<int>::iterator it = std::find(que.begin(), que.end(), 5);
	if (it != que.end()) {
		std::cout << "지워진다아 : " << *it << std::endl;
		que.erase(it);
	}

	it = que.insert(it, 200);
	it = que.insert(it, 2, 300);
	it = que.emplace(que.end(), 234);

	int size = que.size();
	int arr[100];
	std::copy(que.begin(), que.end(), arr);
	std::cout << "arr size : " << size << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << ", ";
	}

	std::cout << std::endl;
}