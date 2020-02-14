#include <iostream>
#include <string>

class Person {
public:
	Person(std::string name, int age) : name(name), age(age) {

	}

	std::string getName() {
		return this->name;
	}

	int getAge() {
		return this->age;
	}

private:
	std::string name;
	int age;
};

class Student {
public:
	Student(std::string name, std::string code) : code(code) {
		person = new Person(name, -1);
	}

	std::string getName() {
		return this->person->getName();
	}

	std::string getCode() {
		return this->code;
	}

private:
	Person* person;
	std::string code;
};

class Professor {
public:
	Professor(std::string name, int level) : level(level) {
		person = new Person(name, -1);
	}

	std::string getName() {
		return this->person->getName();
	}

	int getLevel() {
		return this->level;
	}

private:
	Person* person;
	int level;
};

int main() {
	// °ü°è!
	Student st1("Ballbot", "16-31-001");
	std::cout << "ID : " << st1.getCode() << ", " << "Name : " << st1.getName() << std::endl;
}