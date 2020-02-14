#include <iostream>

void* operator new(size_t t) {
	std::cout << "NEW CALLED SIZE :: " << t << std::endl;
	return malloc(t);
}

void operator delete(void* ptr) {
	std::cout << "DELETE" << std::endl;
	free(ptr);
}

int main() {
	int* a = new int;
	*a = 10;
	std::cout << *a << std::endl;
	delete a;

	std::string* str = new std::string;
	*str = "ЯжЊЌђБЊщЊЪЊЄкЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхокЊхо";
	std::cout << str->data() << std::endl;
	delete str;
}