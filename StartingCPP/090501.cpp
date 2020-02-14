#include <iostream>

class Clazz {
public:
	static int Data;

	class Plazz {
		static int Pdata;
	};
};

int Clazz::Data = 0;
int Clazz::Plazz::Pdata = 10;

int main() {
	unsigned char value = 10;

	int bits = ~value;

	std::cout << ~value << ", " << bits << std::endl;
}