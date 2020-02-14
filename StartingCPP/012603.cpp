#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int main() {
	std::vector<int> myqueue = { 100,99,6,16,84,16,76,33 };
	std::priority_queue<int> pri_queue;

	std::cout << "Á¤·Ä Àü : ";
	for (int i = 0; i < myqueue.size(); ++i) {
		std::cout << myqueue[i] << " ";
		pri_queue.push(myqueue[i]);
	}

	std::cout << "\n\n\n" << std::endl;

	std::make_heap(myqueue.begin(), myqueue.end());
	while (!myqueue.empty()) {
		for (auto i : myqueue) {
			std::cout << i << " ";
		}
		std::cout << std::endl;

		std::pop_heap(myqueue.begin(), myqueue.end());
		myqueue.pop_back();
	}

	std::cout << "pri queue contains : ";
	while (!pri_queue.empty()) {
		std::cout << " " << pri_queue.top() << " ";
		pri_queue.pop();
	}

	std::cout << std::endl;
}