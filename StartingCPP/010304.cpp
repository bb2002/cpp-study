#include <iostream>
#include <cassert>
#include <initializer_list>
#include <iterator>
#include <algorithm>

template<typename T>
class Array {
private:
	T* _data;
	std::size_t _size;

public:
	Array(std::size_t size) {
		_data = new T[size];
		_size = size;
	}

	Array(std::initializer_list<T> list) : _size(list.size()) {
		_data = new T[_size];
		std::copy(list.begin(), list.end(), _data);
	}

	template<typename _InputIterator>
	inline Array(_InputIterator _first, _InputIterator _last) {
		std::size_t size = _last - _first;
		_data = new T[size];

		std::copy(_first, _last, _data);
		_size = size;
	}

	class iterator {
	public:
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;

		//typedef std::forward_iterator_tag iterator_categories;
		//typedef std::ptrdiff_t difference_type;

		// ������, ����Ʈ ������
		iterator(pointer ptr = nullptr) : _ptr(ptr) {

		}

		// ���� ���� ������
		iterator operator++() {
			++_ptr;
			return *this;
		}

		iterator operator++(int) {
			iterator tmp(*this);
			++_ptr;
			return tmp;
		}

		// rvalue �������� ������
		reference operator*() {
			return *_ptr;
		}

		// lvalue �������� ������
		pointer operator->() {
			return _ptr;
		}

		// ��� ������
		bool operator==(const iterator& rhs) {
			return _ptr == rhs._ptr;
		}

		bool operator!=(const iterator& rhs) {
			return _ptr != rhs._ptr;
		}

	private:
		T* _ptr;
	};


	T& operator[](std::size_t index) {
		assert(index < _size);
		return _data[index];
	}

	const T& operator[](std::size_t index) const {
		assert(index < _size);
		return _data[index];
	}

	iterator begin() {
		return iterator(_data);
	}

	iterator end() {
		return iterator(_data + _size);
	}

	~Array() {
		free(_data);
		_size = 0;
	}
};

class Account {
private:
	std::string _number;
	std::string _name;
	int balance = 0;

public:
	Account(std::string number, std::string name, int balance) : _number(number), _name(name), balance(balance) {

	}

	void echo() {
		std::cout << _name.data() << "�� " << _number.data() << " ���� : " << balance << "�� ����" << std::endl;
	}
};

int main() {
	Array<Account*> accounts(3);
	accounts[0] = new Account("349-032021-01-010", "����", 100);
	accounts[1] = new Account("356-473445-75-367", "����", 10000);
	accounts[2] = new Account("077-456745-22-51.", "��Ű��Ҷ�", 1003000);

	for (auto& i : accounts) {
		i->echo();
	}
}