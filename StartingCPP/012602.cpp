#include <iostream>
#include <stack>
#include <queue>

int main() {
	std::queue<int> myqueue;
	std::stack<int> mystack;
	std::priority_queue<int> mypqueue;

	for (int i = 0; i < 10; ++i) {
		myqueue.push(rand());
	}

	std::cout << "myQUEUE datas... : ";
	while (!myqueue.empty()) {
		int data = myqueue.front();

		mypqueue.push(data);
		mystack.push(data);
		std::cout << data << " ";

		myqueue.pop();
	}

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "mySTACK datas... : ";
	while (!mystack.empty()) {
		std::cout << mystack.top() << " ";
		mystack.pop();
	}

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "myPriority_queue datas... : ";
	while (!mypqueue.empty()) {
		std::cout << mypqueue.top() << std::endl;
		mypqueue.pop();
	}
	std::cout << std::endl << std::endl << std::endl;
}