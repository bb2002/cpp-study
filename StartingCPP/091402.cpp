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

class Student : public Person {
public:
	Student(std::string name, std::string code) : Person(name, -1), code(code) {
		
	}

	std::string getCode() {
		return this->code;
	}

private:
	std::string code;
};

class Professor : public Person {
public:
	Professor(std::string name, int level) : Person(name, -1), level(level) {

	}

	int getLevel() {
		return this->level;
	}

private:
	int level;
};

int main() {
	Student s1 = Student("Ballbot", "020606");
	std::cout << "ID " << s1.getCode() << ", Name : " << s1.getName() << std::endl;
}