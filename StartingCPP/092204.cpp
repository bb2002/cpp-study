#include <iostream>

template <typename T, size_t size>
constexpr size_t GetArrayLength(T(&a)[size]) {
	return size;
}

template <typename T, int N>
void LinkedList(T(&arr)[N]) {
	for (int i = 0; i < N; ++i) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

template<const int* pci, size_t size>
struct Array {
	void print() {  
		for (int i = 0; i < size; ++i) {
			std::cout << pci[i] << " ";
		}

		std::cout << std::endl;
	}
};

int main() {
	int a[] = {
		1,2,3,4,5,6,7,8,9
	};

	std::cout << "배열의 크기 : " << GetArrayLength(a) << std::endl;

	LinkedList<int>(a);
}