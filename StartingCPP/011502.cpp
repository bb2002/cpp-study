#include <iostream>
#include <functional>
#include <vector>

typedef std::function<void(float)> Callback;

class AsyncTask {
public:
	void doInBackground(float a, Callback callback) {
		std::cout << "DO IN BACKGROUND LONG....." << a << std::endl;
		callback(a * a);
	}
};

void mycallback(float val) {
	std::cout << "RESULT : " << val << std::endl;
}

int main() {
	AsyncTask newtask;
	newtask.doInBackground(3.141592, std::bind(&mycallback, std::placeholders::_1));
}