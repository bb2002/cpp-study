#ifndef Array_hpp
#define Array_hpp 

#include <initializer_list>
#include <exception>
#include <iterator>

template <typename Type>
class Array {
public:
	typedef  std::size_t  size_type;

	class iterator {
	public:
		typedef Type value_type;
		typedef Type& reference;
		typedef Type* pointer;
		typedef std::random_access_iterator_tag iterator_category;

		typedef std::ptrdiff_t difference_type;

		iterator() : _ptr(nullptr) {}
		iterator(Type* rhs) : _ptr(rhs) {}
		iterator(const iterator &rhs) : _ptr(rhs._ptr) {}
		inline iterator& operator=(Type* rhs) { _ptr = rhs; return *this; }
		inline iterator& operator=(const iterator &rhs) { _ptr = rhs._ptr; return *this; }
		inline iterator& operator+=(difference_type rhs) { _ptr += rhs; return *this; }
		inline iterator& operator-=(difference_type rhs) { _ptr -= rhs; return *this; }

		inline Type& operator*() const { return *_ptr; }
		inline Type* operator->() const { return _ptr; }
		inline Type& operator[](difference_type rhs) const { return _ptr[rhs]; }

		inline iterator& operator++() { ++_ptr; return *this; }
		inline iterator& operator--() { --_ptr; return *this; }
		inline iterator operator++(int) { iterator tmp(*this); ++_ptr; return tmp; }
		inline iterator operator--(int) { iterator tmp(*this); --_ptr; return tmp; }

		inline iterator operator+(difference_type rhs) const { return iterator(_ptr + rhs); }
		inline iterator operator-(difference_type rhs) const { return iterator(_ptr - rhs); }

		inline difference_type operator+(const iterator& rhs) const { return _ptr + rhs._ptr; }
		inline difference_type operator-(const iterator& rhs) const { return _ptr - rhs._ptr; }
		friend inline iterator operator+(difference_type lhs, const iterator& rhs) {
			return iterator(lhs + rhs._ptr);
		}
		friend inline iterator operator-(difference_type lhs, const iterator& rhs) {
			return iterator(lhs - rhs._ptr);
		}

		inline bool operator==(const iterator& rhs) const { return _ptr == rhs._ptr; }
		inline bool operator!=(const iterator& rhs) const { return _ptr != rhs._ptr; }

		inline bool operator>(const iterator& rhs) const { return _ptr > rhs._ptr; }
		inline bool operator<(const iterator& rhs) const { return _ptr < rhs._ptr; }
		inline bool operator>=(const iterator& rhs) const { return _ptr >= rhs._ptr; }
		inline bool operator<=(const iterator& rhs) const { return _ptr <= rhs._ptr; }
	private:
		Type* _ptr;
	};

	inline Array(size_type size = 0) : _size(size) {
		if (0 == size) _data = nullptr;
		else _data = new Type[_size]();
	}

	inline Array(std::initializer_list<Type> init) : _size(init.size()) {
		_data = new Type[_size];
		std::copy(init.begin(), init.end(), _data);
	}

	template<typename _InputIterator>
	inline Array(_InputIterator _first, _InputIterator _last) {
		size_type size = _last - _first;
		_data = new Type[size];
		std::copy(_first, _last, _data);
		_size = size;
	}

	inline ~Array() {
		if (_data) {
			delete[] _data;
			_size = 0;
		}
	}

	inline size_type size() const { return _size; }

	inline void push_back(Type t) {
		size_type size = _size + 1;
		Type *temp = new Type[size];
		std::copy(_data, _data + _size, temp);
		temp[_size] = t;
		delete[] _data;
		_data = temp;
		_size = size;
	}

	inline Type pop_back() {
		if (0 == _size)
			throw std::runtime_error("Array : 비어있습니다.");
		--_size;
		return _data[_size];
	}

	inline Type& operator[](size_type index) {
		if (index >= _size || index < 0)
			throw std::runtime_error("index가 잘못되었습니다.");
		return _data[index];
	}

	inline const Type& operator[](size_type index) const {
		if (index >= _size || index < 0)
			throw std::runtime_error("index가 잘못되었습니다.");
		return _data[index];
	}

	typedef std::reverse_iterator<iterator>       reverse_iterator;

	inline iterator begin() {
		return iterator(_data);
	}
	inline iterator end() {
		return iterator(_data + _size);
	}

	reverse_iterator rbegin() {
		return reverse_iterator(end());
	}
	reverse_iterator rend() {
		return reverse_iterator(begin());
	}

private:
	Type* _data;
	size_type _size;
};
#endif