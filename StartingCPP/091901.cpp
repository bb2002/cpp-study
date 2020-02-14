#include <iostream>

template <typename Type>
class Calc {
public:
	Type multiplay(Type a, Type b);
	Type add(Type a, Type b);
};

template <typename Type>
Type Calc<Type>::multiplay(Type a, Type b) {
	return a * b;
}

template <typename Type>
Type Calc<Type>::add(Type a, Type b) {
	return a + b;
}


template <class T>
class K {
public:
	static T x;
	static T getDate();
	static int a;
};

template <class T> 
T K<T>::x;

template <class T>
T K<T>::getDate() {
	return x;
}

int main() {
	K<int>::x = 10;
	std::cout << "K<int>::getDate() ::>>" << K<int>::getDate() << std::endl;

	K<double>::x = 3.141592;
	std::cout << "K<double>::getDate() ::>>" << K<double>::getDate() << std::endl;

	Calc<int> calcInt;
	std::cout << "Calc<int> ::>>" << calcInt.multiplay(10, 2) << std::endl;

	Calc<char> calcChar;
	std::cout << "Calc<char> add::>>" << calcChar.add('a', 'b') << std::endl;
	std::cout << "Calc<char> multiply::>>" << calcChar.multiplay('a', 'b') << std::endl;

	Calc<std::string> calcStr;
	std::cout << "Calc<string> add::>>" << calcStr.add("Hello", " World!").data() << std::endl;
	//std::cout << "Calc<char> multiply::>>" << calcStr.multiplay("Hello", " World!").data() << std::endl; ERROR

}

