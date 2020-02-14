#include <iostream>
#include <functional>
#include <string>

double divide(double x, double y) {
	return x / y;
}

void goodbye(const std::string& s) {
	std::cout << "GOODBYE : " << s << std::endl;
}

class Object {
public:
	void Hello(const std::string& s) {
		std::cout << "Hello " << s << std::endl;
	}
};

int main() {
	typedef std::function<void(const std::string&)> Func;

	Object instance;
	std::string str("kokoa");
	Func f1 = std::bind(&Object::Hello, &instance, std::placeholders::_1);
	f1(str);

	auto fn = std::bind(&divide, std::placeholders::_1, std::placeholders::_2);
	std::cout << fn(3.141592653589793238462643383279, 2.7182818284590452353602874) << std::endl;

	auto f3 = std::bind(&goodbye, std::placeholders::_1);
	f3(str);
}