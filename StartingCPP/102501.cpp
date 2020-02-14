#include <iostream>
#include <string>

template <typename Key, typename Value>
class KeyValuePare {
public:
	KeyValuePare(Key k, Value v) : k(k), v(v) {
		std::cout << k << " :: " << v << std::endl;
	}

private:
	Key k;
	Value v;
};

template<>
class KeyValuePare<int, std::string> {
public:
	KeyValuePare(int k, std::string value) : key(k), value(value) {
		std::cout << k << " :: " << value << " 와 숫자와 문자열의 환상" << std::endl;
	}

private:
	int key;
	std::string value;
};

template<typename Key>
class KeyValuePare<Key, std::string> {
public:
	KeyValuePare(Key key, std::string value) : key(key), value(value) {
		std::cout << key << " :: " << value << "key 와 문자열의 환상" << std::endl;
	}

private:
	Key key;
	std::string value;
};

int main() {
	auto type1 = KeyValuePare<int, double>(10, 3.141592);
	auto type2 = KeyValuePare<int, std::string>(1, "Hello Ballbot");
	auto type3 = KeyValuePare<char, std::string>('a', "Hello char ballbot");
}