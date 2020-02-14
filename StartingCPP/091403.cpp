#include <iostream>
#include <string>

class Person {
public:
	Person() : name("") {

	}

	Person(std::string name) : name(name) {

	}

	std::string getName() {
		return this->name;
	}

private:
	std::string name;
};

class Student : public Person {
public:
	Student(std::string name) : name(name) {

	}

	std::string getName() {
		return this->name;
	}

private:
	std::string name;
};

int main() {
	Student* s = new Student("Ballbot");
	std::cout << "Student :: " << s->getName() << ", Person :: " << s->Person::getName() << std::endl;

	delete s;
}