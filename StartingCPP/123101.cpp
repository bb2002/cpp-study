#include <iostream>

static int count = 0;

class Youtuber {
private:
	std::string name;
	int age;

public:
	Youtuber(std::string name, int age) : name(name), age(age) {

	}

	Youtuber operator+(const Youtuber& other) {
		return Youtuber(this->name + other.name, this->age + other.age);
	}

	Youtuber operator+(const int right) {
		return Youtuber(this->name , this->age + right);
	}

	bool operator==(const Youtuber& right) {
		return right.name == this->name && right.age == this->age;
	}

	void echo() {
		std::cout << "name : " << this->name.data() << ", age : " << this->age << std::endl;
	}

	friend Youtuber operator+(const int left, const Youtuber& other);
};

Youtuber operator+(const int left, const Youtuber& other) {
	return Youtuber(other.name, other.age + left);
}