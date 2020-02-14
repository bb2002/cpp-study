#include <iostream>

template <typename T>
class Form {
	T* pt;

public:
	Form(T* t) : pt(t) {
		std::cout << *t << std::endl;
	}
};

template <>
class Form<char *> {
	char* data;

public:
	Form(char * data) : data(data) {
		std::cout << "char* >> " << data << std::endl;
	}
};

int main() {
	int i = 157;
	Form<int> form1(&i);

	char c[20] = "Hello world!";
	Form<char*> form2(c);
}