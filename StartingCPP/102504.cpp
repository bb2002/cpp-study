#include <iostream>

template<typename T>
class A {

};

template<int i>
class B {
	
};

class C {
public:
	int x;
};

template<typename T>
void f(T&) {
	std::cout << "T& 타입 : " << typeid(T).name() << std::endl;
}

template<typename T>
void f(T*) {
	std::cout << "T* 타입 : " << typeid(T).name() << std::endl;
}

template<typename T>
void f(const T&) {
	std::cout << "const T& 타입 : " << typeid(T).name() << std::endl;
}

template<typename T>
void f(A<T>) {
	std::cout << "A<T> 타입 : " << typeid(T).name() << std::endl;
}

template<int i>
void f(C[10][i]) {
	std::cout << "C[10][i]!!" << std::endl;
}

template<int i>
void f(B<i>) {
	std::cout << "B<i>!!" << std::endl;
}

template<typename T, typename U>
void f(T(*)(U)) {
	std::cout << "T 타입 : " << typeid(T).name() << ", U 타입 : " << typeid(U).name() << std::endl;
}

void f(int x) {
	std::cout << "void f(int) = " << x << std::endl;
}

int main() {
	C a = { 0 };
	const C b = { 0 };
	A<char> c;
	C& d = a;
	const C& e = b;

	C arr[10][20];
	B<20> b2;

	f(a); f(&a); f(b); f(&b); f(C{ 10 }); f(c); f(d); f(e); f(C{ 11 });
	f(arr);
	f(b2);

	std::cout << "맴버 변수---" << std::endl;
	f(&a.x);

	std::cout << "함수 포인터" << std::endl;
	void(*c_funct1)(int) = &f;
	f(c_funct1);
}