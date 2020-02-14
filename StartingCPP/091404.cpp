#include <iostream>

class Person {
public:
	Person() : name(""), age(-1) {

	}

	Person(std::string name) : name(name), age(-1) {

	}

	Person(std::string name, int age) : name(name), age(age) {

	}

protected:
	int age;

private:
	std::string name;
};


/*
public -> public
protected -> protected
private -> private
*/
class Kasumi : public Person {
public:
	Kasumi(std::string name) : Person(name), total(0) {

	}

	int getTotal() {
		return this->total;
	}

	void addTotal(int d) {
		this->total += d;
	}

	int getAge() {
		return this->age;
	}

private:
	int total;
};

/*
public -> protected
protected -> protected
private -> private
*/
class Yukina : protected Person {
public:
	Yukina(std::string name) : Person(name), total(0) {

	}

	int getTotal() {
		return this->total;
	}

	void addTotal(int d) {
		this->total += d;
	}

	int getAge() {
		return this->age;
	}

private:
	int total;
};

class Aya : private Person {
public:
	Aya(std::string name) : Person(name), total(0) {

	}

	int getTotal() {
		return this->total;
	}

	void addTotal(int d) {
		this->total += d;
	}

	int getAge() {
		return Person::age;
	}

private:
	int total;
};

int main() {
	Kasumi kasumi = Kasumi("Kasumi");
	//std::cout << kasumi.Person::age << "age " << std::endl;

	Yukina yukina = Yukina("Yukina");
	std::cout << yukina.getAge() << "age " << std::endl;
}