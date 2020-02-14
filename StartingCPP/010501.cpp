#include <iostream>
#include <vector>

template<typename T>
class Array {
private:
	T* _data;
	std::size_t _length;

public:
	Array(std::size_t size) {
		_data = new T[size];
		_length = size;
	}

	Array(std::initializer_list<T> list) : _length(list.size()) {
		_data = new T[_length];
		std::copy(list.begin(), list.end(), _data);
	}

	template<typename _InputIterator>
	Array(_InputIterator begin, _InputIterator end) {
		std::size_t size = end - begin;
		_data = new T[size];
		_length = size;

		std::copy(begin, end, _data);
	}

	class Iterator {
	public:
		typedef T	type_data;
		typedef T*	pointer;
		typedef T&	reference;

		typedef std::random_access_iterator_tag interator_category;

		Iterator(pointer ptr = nullptr) : _ptr(ptr) {
			std::cout << "Iterator(pointer ptr = nullptr)" << std::endl;
		}

		Iterator operator++() {
			++_ptr;
			return *this;
		}

		Iterator operator++(int) {
			Iterator tmp(*this);
			++_ptr;
			return tmp;
		}

		reference operator*() {
			return *_ptr;
		}

		pointer operator->() {
			return _ptr;
		}

		bool operator==(Iterator other) {
			return _ptr == other._ptr;
		}

		bool operator!=(Iterator other) {
			return _ptr != other._ptr;
		}

	private:
		pointer _ptr;
	};

	void echo() {
		for (std::size_t i = 0; i < _length; ++i) {
			std::cout << _data[i] << std::endl;
		}
	}

	Iterator begin() {
		return Iterator(_data);
	}

	Iterator end() {
		return Iterator(_data + _length);
	}
};

int main() {
	Array<int> arr = Array<int>({1,3,5,7,9,11});
	for (int& o : arr) {
		std::cout << o << std::endl;
	}
}