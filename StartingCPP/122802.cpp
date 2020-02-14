#include <iostream>

class OtherClass;

class MyClass {
public:
	int Fun(OtherClass& a);
};

class OtherClass {
private:
	int a = 10;

	friend MyClass;
};

int main() {

}

int MyClass::Fun(OtherClass& a)
{
	return a.a;
}
