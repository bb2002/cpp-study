#include <iostream>

class Simple {
public:
	int val;
};

class GoodSimple {
public:
	GoodSimple(const char* label, int val) : label(label), val(val) {

	}

	GoodSimple() = default;

	void display() {
		std::cout << label.data() << std::endl;
		std::cout << val << std::endl;
	}

	static int getStaticVal() {
		return s_val;
	}

	static int getCVal() {
		return c_val;
	}

private:
	std::string label;
	const int val;

private:
	static int s_val;
	static const int c_val;
};

// 상수의 초기화.
int GoodSimple::s_val = 100;
const int GoodSimple::c_val = 200;

int main() {
	Simple s;
	s.val = 10;
	std::cout << s.val << std::endl;

	GoodSimple gs("Ballbot", 13);
	gs.display();

	std::cout << GoodSimple::getStaticVal() << " && " << GoodSimple::getCVal() << std::endl;
}