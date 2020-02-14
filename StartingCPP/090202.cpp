#include <iostream>

void temp(int, double, const char*);

void temp(int i, double f = 3.141592, const char* c = "Hello World!");

void temp(int i = 4, double f = 3.141592, const char* c = "Hello World!");

int main() {
	//temp(400);
}

void temp(int i, double d, const char * c)
{
	std::cout << i << std::endl;
}
