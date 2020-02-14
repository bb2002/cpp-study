#include <iostream>
#include <memory>
#include <string>

int main() {
	const int size = 10;

	std::allocator<int> a1;
	int* a = a1.allocate(size);

	for (int i = 0; i < size; ++i) {
		a[i] = i * i;
	}

	for (int i = 0; i < size; ++i) {
		std::cout << a[i] << " ";
	}

	std::cout << std::endl;
	a1.deallocate(a, size);
	std::allocator_traits<decltype(a1)>::rebind_alloc<std::string> a2;

	std::string* s2 = a2.allocate(size);
	a2.construct(s2, "Hello world!");
	a2.construct(s2 + 1, "Sisigami");
	a2.construct(s2 + 2, "Leona!");

	for (int i = 0; i < 3; ++i) {
		std::cout << s2[i] << std::endl;
		a2.destroy(s2 + i);
	}

	a2.deallocate(s2, size);
}