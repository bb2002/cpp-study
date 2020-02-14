#include <iostream>

class Youtuber {
private:
	std::string name;
	int age;

public:
	Youtuber(std::string name, int age = 0) : name(name), age(age) {
		std::cout << "Hello " << name.data() << "chan! " << std::endl;
		std::cout << "AGE : " << age << std::endl;
	}

	void operator()(std::ostream& os) const {
		os << "=-=-= YOUTUBER INFO =-=-=" << std::endl;
		os << "NAME : " << name.data() << std::endl;
		os << "AGE : " << age << std::endl;
	}

	void operator()(int age) {
		this->age = age;
	}

	~Youtuber() {
		std::cout << "DESTORY!!" << std::endl;
	}
};

int main() {
	Youtuber youtuber("시시가미레오나", 2);
	youtuber(10);
	youtuber(std::cout);
}