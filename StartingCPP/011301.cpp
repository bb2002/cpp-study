#include <iostream>
#include <functional>
#include <string>

double my_divide(double x, double y) {
	return x / y;
}

void helloworld(const std::string& s) {
	std::cout << "Hello " << s << std::endl;
}

class Object {
public:
	void goodbye(const std::string& s) {
		std::cout << "GoodBye " << s << std::endl;
	}
};

int main() {
	Object instance;
	std::string str("Leona");

	auto bye = std::bind(&Object::goodbye, &instance, str);
	auto hello = std::bind(&helloworld, str);
	bye();
	hello();
}