#include <iostream>

class Person {
	char* name;
	const int age;

public:
	Person() : Person("Hello", 10) {

	}

	Person(const char* c, int a) : name(new char[strlen(c) + 1]), age(a) {
		std::cout << "Person() called" << std::endl;
		strcpy_s(this->name, strlen(c) + 1, c);
	}

	void print() const;

	static void* operator new(std::size_t sz) {
		std::cout << "Person NEW!!!" << std::endl;
		return ::operator new(sz);
	}

	static void operator delete(void* ptr) {
		::operator delete(ptr);
	}

	~Person() {
		std::cout << "¿Í ¼Ò¸ê" << std::endl;
		delete[] name;
	}
};

void Person::print() const {
	std::cout << name << " : " << age << std::endl;
}

int main() {
	Person *p = new Person();
	p->print();

	delete p;
}