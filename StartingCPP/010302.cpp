#include <iostream>
#include <cassert>

template<typename T>
class Array {
private:
	std::size_t _size;
	T* _data;

public:
	Array(const std::size_t size) : _size(size) {
		_data = new T[size]();
	}

	T& operator[](unsigned int index) {
		assert(index < _size);
		return _data[index];
	}

	const T& operator[](unsigned int index) const {
		assert(index < _size);
		return _data[index];
	}

	~Array() {
		delete[] _data;
		_size = 0;
	}
};

int main() {
	Array<float> arr(4);
	arr[0] = 3.14F;
	arr[1] = 15.92F;
	arr[2] = 2.54F;
	arr[3] = 6.18F;

	for (int i = 0; i < 4; ++i) {
		std::cout << arr[i] << std::endl;
	}
}