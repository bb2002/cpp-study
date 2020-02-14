#include <iostream>
#include <string>

template<typename T>
struct Data {
	Data(T a) : data(a) {
		
	}

	T getData() {
		return data;
	}

private:
	T data;
};

template<typename K, typename V, template<typename A> typename C = Data>
class Map {
public:
	Map(K key, V value) : Key(key), Value(value) {
		std::cout << "Map() ÀÌ »ý¼º µÊ" << std::endl;
	}

	K getKey() {
		return Key.getData();
	}

	V getValue() {
		return Value.getData();
	}

private:
	C<K> Key;
	C<V> Value;
};

template<typename K>
class Map<K, int> {
public:
	Map(K key, int value) : key(key), Value(value) {

	}

	K getKey() {
		return key;
	}

	int getValue() {
		return Value;
	}

private:
	K key;
	int Value;
};

int main() {
	Map<int, int> imap(100, 100);
	std::cout << "Map(" << imap.getKey() << ", " << imap.getValue() << ")" << std::endl;

	Map<int, std::string, Data> map(100, "Hello World!");
	std::cout << "Map(" << map.getKey() << ", " << map.getValue() << ")" << std::endl;
}