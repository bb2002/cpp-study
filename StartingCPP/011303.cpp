#include <iostream>
#include <functional>
#include <string>

static double my_divide(double x, double y) {
	return x / y;
}

void helloworld(const std::string s) {
	std::cout << "Hello " << s << std::endl;
}

class Object {
public:
	void goodbye(const std::string s) {
		std::cout << "GoodBye " << s << std::endl;
	}
};

int main() {
	Object instance;
	std::string str("Leona");

	auto bye = std::bind(&Object::goodbye, &instance, std::ref(str));
	auto hello = std::bind(&helloworld, std::ref(str));
	auto div = std::bind(&my_divide, 3.141592F, 2.71828F);
	bye();
	hello();
	std::cout << "pie / olier = " << div() << std::endl;
}