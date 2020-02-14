#include <iostream>
#include <functional>

typedef void(*Callback)(int);

class AsyncTask {
public:
	void DoLongTask(int a, int b, Callback callback) {
		std::cout << "LONG WORKING...." << std::endl;;
		callback(a + b);
	}
};

void fun(int result) {
	std::cout << "LONG WORK RESULT : " << result << std::endl;
}

int main() {
	AsyncTask task;
	task.DoLongTask(5, 10, &fun);
}