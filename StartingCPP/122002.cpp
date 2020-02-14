#include <iostream>

class Kokoro {
public:
	Kokoro() {
		std::cout << "kokoro is created." << std::endl;
	}

	void Hello() {
		std::cout << "HAPPY SMILE YEAR!" << std::endl;
	}
};

class Dream {
public:
	Kokoro MyKokoro;

	Dream() = default;
};

int main() {
	Dream* MyDream = new Dream();
	MyDream->MyKokoro.Hello();
}