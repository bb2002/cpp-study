#include <iostream>
#include <string>

template <typename T>
struct MapData {
	MapData(T t) : data(t) {

	}

	T getData() {
		return data;
	}

private:
	T data;
};

template<typename K, typename V, template<typename T> typename C>
class Map {
public:
	Map(K k, V v) : key(k), value(v) {

	}

	K getKey() {
		return key.getData();
	}

	V getValue() {
		return value.getData();
	}

private:
	C<K> key;
	C<V> value;
};

int main() {
	Map<int, std::string, MapData> map(1000, "ÅÆÇÃ¸´ ÅÆÇÃ¸´ ÀÎ¼ö ÀÌ´Ù.");
	std::cout << map.getKey() << std::endl;
	std::cout << map.getValue() << std::endl;

}