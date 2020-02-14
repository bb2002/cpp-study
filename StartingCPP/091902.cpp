#include <iostream>

template <typename Type>
class Allocator {
public:
	Type a;
};

template <typename Type, typename Alloc = Allocator<Type>>
class Stack {
public:
	Type a;
	Alloc b;
};

class EmptyClass {
	class InnerClass {

	};
};

class EmptyClass2 {
	class InnerClass {

	};
};

template <typename T>
class C2 : Stack<typename T::InnerClass> {

};

int main() {
	Stack<int, Allocator<int>>* NewStack;
	NewStack->a = 10;
	NewStack->b = Allocator<int>();
}