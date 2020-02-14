#include <iostream>
#include <initializer_list>
#include <exception>
#include <iterator>

template<typename T>
class Array {

public:
	typedef std::size_t  size_type;

	class Iterator {
	public:
		typedef T									data_type;
		typedef T*									pointer;
		typedef T&									reference;

		typedef std::random_access_iterator_tag		iterator_type;
		typedef std::ptrdiff_t						difference_type;

		Iterator() : _ptr(nullptr) {

		}

		Iterator(pointer rhs) : _ptr(rhs) {

		}

		Iterator(const Iterator& rhs) : _ptr(rhs._ptr) {

		}

		inline Iterator& operator=(T* rhs) {
			_ptr = rhs;
			return *this;
		}

		inline Iterator& operator=(const Iterator& rhs) {
			_ptr = rhs._ptr;
			return *this;
		}

		inline Iterator& operator+=(difference_type rhs) {
			_ptr += rhs;
			return *this;
		}

		inline Iterator& operator-=(difference_type rhs) {
			_ptr -= rhs;
			return *this;
		}

		inline T& operator*() const {
			return *_ptr;
		}

		inline T* operator->() const {
			return _ptr;
		}

		inline T& operator[](difference_type rhs) const {
			return _ptr[rhs];
		}

		inline Iterator& operator++() {
			++_ptr;
			return *this;
		}

		inline Iterator& operator--() {
			--_ptr;
			return *this;
		}

		inline Iterator operator++(int) {
			Iterator tmp(*this);
			++_ptr;
			return tmp;
		}

		inline Iterator operator--(int) {
			Iterator tmp(*this);
			--_ptr;
			return tmp;
		}

		inline Iterator operator+(difference_type rhs) const {
			return Iterator(_ptr + rhs);
		}

		inline Iterator operator-(difference_type rhs) const {
			return Iterator(_ptr - rhs);
		}

		inline difference_type operator+(const Iterator& rhs) const {
			return _ptr + rhs._ptr;
		}

		inline difference_type operator-(const Iterator& rhs) const {
			return _ptr - rhs._ptr;
		}

		inline bool operator==(const Iterator& rhs) const {
			return _ptr == rhs._ptr;
		}

		inline bool operator!=(const Iterator& rhs) const {
			return _ptr != rhs._ptr;
		}

		inline bool operator>(const Iterator& rhs) const {
			return _ptr > rhs._ptr;
		}

		inline bool operator<(const Iterator& rhs) const {
			return _ptr < rhs._ptr;
		}

		inline bool operator>=(const Iterator& rhs) const {
			return _ptr >= rhs._ptr;
		}

		inline bool operator<=(const Iterator& rhs) const {
			return _ptr <= rhs._ptr;
		}

	private:
		pointer _ptr;
	};


private:
	T* _data;
	size_type _size;

public:

	inline Array(size_type size) : _size(size) {
		_data = new T[_size];
	}

	inline Array(std::initializer_list<T> list) : _size(list.size()) {
		_data = new T[_size];
		std::copy(list.begin(), list.end(), _data);
	}

	inline ~Array() {
		if (_data) {
			delete[] _data;
			_size = 0;
		}
	}

	inline size_type size() const {
		return _size;
	}

	void push_back(T data) {
		size_type newSize = _size + 1;
		T* tmp = new T[newSize];
		std::copy(_data, _data + _size, tmp);

		tmp[_size] = data;
		delete[] _data;

		_data = tmp;
		_size = newSize;
	}

	T pop_back() {
		if (_size == 0) {
			throw std::runtime_error("Array is empty.");
		}
		else {
			--size;
			return _data[_size];
		}
	} 

	const T& operator[](size_type index) const {
		if (index > _size) {
			throw std::runtime_error("Array index out of range");
		}
		else {
			return _data[index];
		}
	}

	T& operator[](size_type index) {
		if (index > _size) {
			throw std::runtime_error("Array index out of range");
		}
		else {
			return _data[index];
		}
	}

	inline Iterator begin() {
		return Iterator(_data);
	}

	inline Iterator end() {
		return Iterator(_data + _size);
	}
};

int main() {
	Array<double> arr = { 3.1, 4.5, 1.5, 9.2 };
	for (Array<double>::Iterator i = arr.begin(); i != arr.end(); ++i) {
		std::cout << *i << std::endl;
	}

	Array<double>::Iterator iter = arr.begin() + 2;
	std::cout << *iter << std::endl;

	std::cout << arr[0] << std::endl;
}