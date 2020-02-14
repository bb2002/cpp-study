#include <iostream>

template <int& a>
class Simple {
public:
	Simple() {
		std::cout << "construct a :: " << a << std::endl;
	}

	~Simple() {
		std::cout << "destroy a :: " << a << std::endl;
	}
};

int asdf = 10;

int main() {
	Simple<asdf> b;
	asdf = 100;
}